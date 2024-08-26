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
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

int n, k, res = 0, cnt = 0;

deque<int> v; // 칸 내구도
deque<int> robot; // 로봇

void Rotate()
{
    // 벨트 회전.
	v.push_front(v.back());
	v.pop_back();

	robot.push_front(robot.back());
	robot.pop_back();

    // n칸에서 내림
	if (robot[n - 1]) robot[n - 1] = 0;
}

void RobotMove()
{
    // 로봇 이동
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i + 1] > 0 && robot[i] && !robot[i + 1])
        {
            v[i + 1] -= 1;

            robot[i] = 0;
            robot[i + 1] = 1;
        }  
        
        // n칸에서 내림
        if (robot[n - 1]) robot[n - 1] = 0;
    }
}

void OnRobot()
{
    // 로봇 올림.
    if (v[0] > 0 && !robot[0])
    {
        v[0] -= 1;
        robot[0] = 1;
    }
}

void check()
{
    // 내구도 0 체크.
    for (int i = 0; i < n * 2; i++)
    {
        if (v[i] == 0) cnt++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n * 2; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        robot.push_back(0);
    }

    while(1)
    {
        cnt = 0;

        Rotate();

        RobotMove();

        OnRobot();

        check();

        res++;

        if (cnt >= k) break; 
    }

    cout << res;
}
