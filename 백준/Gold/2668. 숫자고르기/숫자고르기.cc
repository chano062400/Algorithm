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
vector<int> v, one ,two;

void dfs(int cur)
{
    if (!visited[cur])
    {
        visited[cur] = 1;
        one.push_back(cur);
        two.push_back(arr[2][cur]);
    }
    else
    {
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());

        bool same = true;

        for (int i = 0; i < one.size(); i++)
        {
            if (one[i] != two[i])
            {
                same = false;
                break;
            }
        }

        if (same)
        {
             for (auto n : one) v.push_back(n);
        }

        return;
    }    

    dfs(arr[2][cur]);

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
        one.clear();
        two.clear();
        dfs(i);
    }

    // 1번쨰 줄과 2번째 줄 값이 같은 애들.
    for (int i = 1; i <= n; i++)
    {
        if (find(v.begin(), v.end(), i) == v.end() && arr[2][i] == i)  v.push_back(i);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << '\n';
    for (auto n : v) cout << n << '\n';

}
