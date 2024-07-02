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
int arr[11][11];
bool check[11][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<int, int>> v;

int getsum()
{
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int cx = v[i].first;
        int cy = v[i].second;

        check[cx][cy] = 1;
        sum += arr[cx][cy];

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (check[nx][ny] || nx < 1 || nx > n || ny < 1 || ny > n) return -1;

            check[nx][ny] = 1;
            sum += arr[nx][ny];
        }
    }

    return sum;
}

void back(int x, int y, int cnt)
{
    if (cnt == 3)
    {
        int sum = getsum();
        if (sum != -1) res = min(res, sum);
        memset(check, 0, sizeof(check));
        return;
    }

    for (int i = x; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
			v.push_back({ i,j });
			back(i, j, cnt + 1);
			v.pop_back();            
        }
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            v.push_back({ i,j });
            back(i, j, 1);
            v.pop_back();
        }
    }
    
    cout << res;
}
