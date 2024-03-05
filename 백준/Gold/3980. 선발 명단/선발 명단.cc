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
using namespace std;

int n, arr[12][12], res;
bool visited[12];

void back(int num, int sum)
{
    if (num == 12)
    {
        res = max(res, sum);
        return;
    }

    for (int i = 1; i <= 11; i++)
    {
        if (arr[num][i] == 0) continue;
        
        if (!visited[i])
        {
            visited[i] = 1;
            back(num + 1, sum + arr[num][i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    while (n--)
    {
        for (int i = 1; i <= 11; i++)
        {
            for (int j = 1; j <= 11; j++)
            {
                cin >> arr[i][j];
            }
        }
        res = 0;

        memset(visited, 0, sizeof(visited));

        back(1,0);

        cout << res << '\n';
    }
}
