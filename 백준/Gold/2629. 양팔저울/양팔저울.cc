#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

int n, m, weights[31];
bool dp[31][15001];

void dfs(int index, int weight)
{
	if (index > n || dp[index][weight]) return;
	dp[index][weight] = true;
	
	dfs(index + 1, weight + weights[index]);
	dfs(index + 1, abs(weight - weights[index]));
	dfs(index + 1, weight);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	dfs(0, 0);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int bead;
		cin >> bead;
		if (bead > 15000) cout << "N ";
		else if (dp[n][bead]) cout << "Y ";
		else cout << "N ";
	}

}


