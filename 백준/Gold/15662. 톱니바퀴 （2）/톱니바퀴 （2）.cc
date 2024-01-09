#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
using namespace std;

int n, k, Rot[1001], res=0;
deque<int> dq[1001];
#define N 0 
#define S 1 
#define Right 2
#define Left 6

void rot(int num, int dir)
{
    int temp = num;
    int tdir = dir;
    Rot[num] = dir;

    while (1) // 회전시킬 톱니바퀴 기준 왼쪽
    {
        if (temp <= 1) break;
        if (dq[temp - 1][Right] != dq[temp][Left] && Rot[temp] != 0) // 현재 톱니바퀴가 움직이지 않는다면 현재 기준 왼쪽에 있는 톱니바퀴들을 모두 움직이지 않음.
        {
            tdir *= -1;
            Rot[temp - 1] = tdir;
        }
        temp--;
    }

    temp = num;
    tdir = dir;

    while (1) // 회전시킬 톱니봐퀴 기준 오른쪽
    {
        if (temp >= n) break;
        if (dq[temp + 1][Left] != dq[temp][Right] && Rot[temp] != 0) // 현재 톱니바퀴가 움직이지 않는다면 현재 기준 오른쪽에 있는 톱니바퀴들을 모두 움직이지 않음.
        {
            tdir *= -1;
            Rot[temp + 1] = tdir;
        }
        temp++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (Rot[i] == 1)
        {
            dq[i].push_front(dq[i].back());
            dq[i].pop_back();
        }
        if (Rot[i] == -1)
        {
            dq[i].push_back(dq[i].front());
            dq[i].pop_front();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j <8; j++)
        {
            dq[i].push_back(str[j] - '0');
        }
    }
    
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        memset(Rot, 0, sizeof(Rot));
        int num, dir;
        cin >> num >> dir;
        rot(num, dir);
    }

    for (int i = 1; i <= n; i++)
    {
        if (dq[i][0] == S) res++;
    }

    cout << res;
}
