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

int n, k;
long long fact[21];
bool check[21];

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> k;

	fact[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = i * fact[i - 1];
	}

	if (k == 1)
	{
		vector<int> v(n);

		long long Find;
		cin >> Find;
		for (int i = 0; i < n; i++) // 자릿수
		{
			for (int j = 1; j <= n; j++) // 해당 값 찾기
			{
				if (check[j]) continue;

				if (fact[n - i - 1] < Find)
				{
					Find -= fact[n - i - 1];
				}
				else
				{
					v[i] = j;
					check[j] = 1;
					break;
				}
			}
		}

		for (auto s : v) cout << s << " ";
		cout << '\n';

	}
	else if (k == 2)
	{
		vector<int> v(n);

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		long long res = 0;

		for (int i = 0; i < n; i++) // 자릿수
		{
			for (int j = 1; j < v[i]; j++) //자리 해당 수
			{
				if (!check[j])
				{
					res += fact[n - i - 1];
				}
			}
			check[v[i]] = 1;
		}

		cout << res + 1;
	}


}