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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> a >> b;

	vector<bool> isprime(b + 1, 1);

	for (int i = 2; i <= sqrt(10000000); i++)
	{
		if (!isprime[i]) continue;
		for (int j = i * i; j <= b; j += i)
		{
			isprime[j] = false;
		}
	}

	for (int i = a; i <= 10000000; i++)
	{
		if (!isprime[i]) continue;
		if (i > b) break;

		int num = i;
		string str = to_string(i), rstr;

		rstr = str;
		reverse(str.begin(), str.end());

		if (rstr == str) cout << i << '\n';
	}
	cout << -1 << '\n';
}

