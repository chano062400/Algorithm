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

int n, dist[51][51], num[51];
vector<int> v[51];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j) dist[i][j] = 987654321;
        }
    }

    while (1)
    {
        int n1, n2;
        cin >> n1 >> n2;

        if (n1 == -1 && n2 == -1) break;
        
        dist[n1][n2] = 1;
        dist[n2][n1] = 1;
    }

    for (int h = 1; h <= n; h++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
				dist[i][j] = min(dist[i][j], dist[i][h] + dist[h][j]);
            }
        }
    }

    vector<int> res;
    int mn = 9876543321;
    for (int i = 1; i <= n; i++)
    {
        int score = 0;
        for (int j = 1; j <= n; j++)
        {
            score = max(dist[i][j], score);
        }

        if (score < mn)
        {
            res.clear();
            mn = score;
            res.push_back(i);
        }
        else if (score == mn) res.push_back(i);
    }

    cout << mn << " " << res.size() << '\n';
    for (auto r : res) cout << r << " ";

};

