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

int n, res = 987654321;
int arr[21][21];
bool check[21];

void back(int idx, int cnt)
{
    if (cnt > n / 2) return;

    if (cnt > 0)
    {
        int start = 0, link = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (check[i] && check[j])
                {
                    start += arr[i][j];
                }
                
                if (!check[i] && !check[j])
                {
                    link += arr[i][j];
                }
            }
        }

        int dif = abs(start - link);
        res = min(res, dif);
    }

    for (int i = idx; i <= n; i++)
    {
		check[i] = 1;
		back(i + 1, cnt + 1);
		check[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(check, 0, sizeof(check));

    back(1,0);

    cout << res;
}
