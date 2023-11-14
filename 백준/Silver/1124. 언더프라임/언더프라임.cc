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
using namespace std;

int a, b, res=0;
int num[100001]; /* 가장 작은 소인수 */
int decim[100001]; // 소수인지 판별 
vector<int> factor[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> a >> b;
   
    for (int i = 2; i <= b; i++)
    {
        num[i] = i;
        decim[i] = i;
    }
    for (int i = 2; i <= b; i++)
    {
        if (num[i] == i)
        {
            for (int j = 2; j * i <= b; j++)
            {
                if (num[i * j] == i * j) num[i * j] = i;
                decim[i * j] = 0;
            }
        }
    }
    

    for (int i = a; i <= b; i++)
    {
        int n = i;
        while (n > 1)
        {
            factor[i].push_back(num[n]); //해당 값의 가장 작은 소인수로 나눈다.
            n /= num[n];
        }
    }

    for (int i = a; i <= b; i++)
    {
        if (decim[factor[i].size()] != 0) res++; //소수 목록의 길이가 소수이면 res++
    }

    cout << res;

    return 0;
}