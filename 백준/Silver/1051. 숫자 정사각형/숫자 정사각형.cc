#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include "algorithm"
#include <cmath>
#include <stack>
#include <regex>

using namespace std;

vector<int> sq[51];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string num;
		cin >> num;
		for (int j = 0; j < num.length(); j++)
		{
			sq[i].push_back(num[j] -'0');
		}
	}

	int len = min(N, M);
	bool same = false;
	while (len > 1)
	{
		for (int i = 0; i < len + i; i++)
		{
			if (i + len - 1 >= N) break;
			for (int j = 0; j < len + j; j++)
			{
				if (j + len - 1 >= M) break;
				if (sq[i][j] == sq[i][j + len - 1])
				{
					if (sq[i + len - 1][j] == sq[i + len - 1][j + len - 1])
					{
						if (sq[i][j] == sq[i + len - 1][j] && sq[i][j + len - 1] == sq[i + len - 1][j + len - 1])
						{
							same = true;
							break;
						}
					}
				}
			}
			if (same) break;
		}
		if (same)break;
		else len--;
	}

	if (same) cout << len * len;
	else cout << 1;
}