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

int n;
queue<int> q;
vector<int> v[11];
int Tree[2000];

void dfs(int node, int depth)
{
    if (node > pow(2,n) - 1) return;

    // 왼쪽 자식 노드
    dfs(node * 2, depth + 1);

    Tree[node] = q.front();
    q.pop();
    v[depth].push_back(Tree[node]);

    // 오른쪽 자식 노드
    dfs(node * 2 + 1, depth + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    
    for (int i = 0; i < pow(2,n) - 1; i++)
    {
        int num;
        cin >> num;
        q.push(num);
    }

    dfs(1, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    
}
