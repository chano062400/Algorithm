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

bool prime[10000];
int n, res = 0;

bool isprime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }

    return true;
}

bool bfs(int start, int target)
{
    queue<pair<int,int>> q;
    q.push({ 0,start });
    set<int> Set;
    Set.insert(start);

    while (!q.empty())
    {
        int cnt = q.front().first;
        int cur = q.front().second;
        q.pop();

        if (cur == target)
        {
            res = cnt;
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int num[4] = { 0, };
            num[0] = cur / 1000;
            num[1] = (cur % 1000) / 100;
            num[2] = (cur % 100) / 10;
            num[3] = cur % 10;

            for (int j = 0; j < 10; j++)
            {
                if (i == 0 && j == 0) continue;
                
                int prevnum = num[i];
                num[i] = j;

                int nextnum = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];

                if (isprime(nextnum) && Set.count(nextnum) == 0)
                {
                    Set.insert(nextnum);
                    q.push({ cnt + 1, nextnum });
                }
                // 한번에 한 자리만 바꿀 수 있으므로, 바꿨던 자리를 원상복귀.
                num[i] = prevnum;
            }
            
        }


    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {        
        int s, t;
        cin >> s >> t;
     
        res = 0;

        if (bfs(s, t)) cout << res << '\n';
        else cout << "Impossible" << '\n';
    }
}
