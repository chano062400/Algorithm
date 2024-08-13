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

struct Info
{
    int x;
    int y;
    int size;
};

int n, m;
char arr[101][101];
bool visited[101][101], incross[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<Info> v;

void checkcross(int x, int y)
{
	for (int size = 1; size <= 99; size++)
	{
        vector<pair<int, int>> pos;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j] * size;
			int ny = y + dy[j] * size;

            if (nx < 1 || nx > n || ny < 1 || ny > m || arr[nx][ny] != '*')
            {
                pos.clear();
                return;
            }
            pos.push_back({ nx, ny });
		}

        for (auto xy : pos)
        {
            incross[xy.first][xy.second] = true;
        }
        v.push_back({ x, y, size });
        incross[x][y] = true;
        
	}

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j] && arr[i][j] == '*')
            {
                checkcross(i, j);
                visited[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == '*' && !incross[i][j])
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

	cout << v.size() << '\n';

	for (auto Info : v)
	{
		cout << Info.x << " " << Info.y << " " << Info.size << '\n';
	}

}
