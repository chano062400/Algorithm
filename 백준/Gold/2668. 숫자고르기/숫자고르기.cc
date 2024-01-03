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

int n, arr[3][101];
bool visited[101];
vector<int> v;

void dfs(int cur, int start)
{
    if (visited[cur]) 
    {
        if (cur == start) // 사이클 발생
            v.push_back(cur);
        return;
    }
    
    visited[cur] = 1;
    dfs(arr[2][cur], start);

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        arr[1][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[2][i];
    }

    for (int i = 1; i <= n; i++)
    {
		memset(visited, 0, sizeof(visited));
		dfs(i,i);
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto n : v) cout << n << '\n';

}
