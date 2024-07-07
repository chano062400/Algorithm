#include <iostream>
#include <vector>

using namespace std;

int n,m, cnt=0,res=0;
int arr[501][501];
bool know = true;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
	}

	for (int mid = 1; mid <= n; mid++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][mid] && arr[mid][j])
					arr[i][j] = 1;

			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[j][i] || arr[i][j])
			{
				cnt++;
			}
		}
		if (cnt == n - 1) res++;
		cnt = 0;
	}

	cout << res;

}