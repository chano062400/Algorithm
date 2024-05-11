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

int n, k, second = 0;
string str[2];
bool visited[100001][2];

struct Info
{
    int map;
    int idx;
    int seconds;
};

bool bfs()
{
    queue<Info> q;
    q.push({ 0,0,0 });

    while (!q.empty())
    {
        int cm = q.front().map;
        int ci = q.front().idx;
        int cs = q.front().seconds;
        q.pop();

        if (cm == 0)
        {
            if (ci + 1 >= n) return 1;
            else if (str[cm][ci + 1] == '1' && ci + 1 > cs && !visited[ci + 1][cm])
            {
                visited[ci + 1][cm] = 1;
                q.push({ cm, ci + 1, cs + 1 });
            }

            if (ci - 1 >= 0 && str[cm][ci - 1] == '1' && ci - 1 > cs && !visited[ci - 1][cm])
            {
                visited[ci - 1][cm] = 1;
                q.push({ cm,ci - 1,cs + 1 });
            }
            
            if (ci + k >= n) return 1;
            else if (str[cm + 1][ci + k] == '1' && ci + k > cs && !visited[ci + k][cm + 1])
            {
                visited[ci + k][cm + 1] = 1;
                q.push({ cm + 1, ci + k, cs + 1 });
            }
        }
        else
        {
            if (ci + 1 >= n) return 1;
            else if (str[cm][ci + 1] == '1' && ci + 1 > cs && !visited[ci + 1][cm])
            {
                visited[ci + 1][cm] = 1;
                q.push({ cm, ci + 1, cs + 1 });
            }

            if (ci - 1 >= 0 && str[cm][ci - 1] == '1' && ci - 1 > cs && !visited[ci -1][cm])
            {
                visited[ci - 1][cm] = 1;
                q.push({ cm, ci - 1 , cs + 1 });
            }
            
            if (ci + k >= n) return 1;
            else if (str[cm - 1][ci + k] == '1' && ci + k > cs && !visited[ci + k][cm - 1])
            {
                visited[ci + k][cm - 1] = 1;
                q.push({ cm - 1, ci + k, cs + 1 });
            }
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k >> str[0] >> str[1];

    if (bfs()) cout << 1;
    else cout << 0;

}
   