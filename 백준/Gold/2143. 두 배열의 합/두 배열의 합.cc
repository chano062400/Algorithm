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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	int n;
	cin >> n;
	
	vector<int> A(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	int m;
	cin >> m;
	vector<int> B(m, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> B[i];
	}

	vector<long long> sumA, sumB;

	// A, B배열의 모든 부배열의 누적합을 넣어줌.
	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += A[j];
			sumA.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		long long sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += B[j];
			sumB.push_back(sum);
		}
	}

	sort(sumB.begin(), sumB.end());

	long long res = 0;
	for (int i = 0; i < sumA.size(); i++)
	{
		long long value = t - sumA[i];
		int idx1 = lower_bound(sumB.begin(), sumB.end(), value) - sumB.begin();
		int idx2 = upper_bound(sumB.begin(), sumB.end(), value) - sumB.begin();
		res += (idx2 - idx1);
	}

	cout << res;
}


