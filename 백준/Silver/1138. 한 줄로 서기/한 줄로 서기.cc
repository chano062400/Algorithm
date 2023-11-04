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
using namespace std;

int n;
int arr[11];
bool check[11];

bool issame(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int num = vec[i];
		int bigger = 0;
		for (int j = 0; j < i; j++)
		{
			if (vec[j] > num) bigger++;
		}

		if (arr[num] != bigger) return false;
	}

	return true;
}

void back(vector<int> vec, int index, int len)
{
	if (len == n)
	{
		if (issame(vec))
		{
			for (auto s : vec) cout << s << " ";
			return;
		}

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			vec.push_back(i);
			check[i] = 1;
			back(vec, i, len + 1);
			check[i] = 0;
			vec.pop_back();
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	vector<int>v;

	back(v, 0, 0);
}