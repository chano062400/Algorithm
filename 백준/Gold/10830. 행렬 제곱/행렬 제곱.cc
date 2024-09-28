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
long long b;

vector<vector<long long>> matrixmul(const vector<vector<long long>>& v1, const vector<vector<long long>>& v2)
{
	vector<vector<long long>> temp(v1.size(), vector<long long>(v1[0].size(), 0));

	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2[0].size(); j++)
		{
			for (int k = 0; k < v1[0].size(); k++)
			{
				temp[i][j] += v1[i][k] * v2[k][j];
			}
			temp[i][j] %= 1000;
		}
	}

	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> b;
	
	vector<vector<long long>> arr(n, vector<long long>(n, 0)), res(n, vector<long long>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
		res[i][i] = 1;
	}

	while (b)
	{
		if (b % 2)
		{
			res = matrixmul(res, arr);
			b--;
		}
		else
		{
			arr = matrixmul(arr, arr);
			b /= 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << '\n';
	}

}

