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

string str;
int n, res = INT_MIN;

int calculate(int n1, int n2, char op)
{
	if (op == '+') return n1 + n2;
	if (op == '-') return n1 - n2;
	if (op == '*') return n1 * n2;
	return n1;
}

void dfs(int idx, int calc)
{
	if (idx >= n)
	{
		res = max(res, calc);
		return;
	}

	char op = idx == 0 ? '+' : str[idx - 1];

	// 괄호 처리.
	if (idx + 2 < n)
	{
		// 괄호 안 계산.
		int temp = calculate(str[idx] - '0', str[idx + 2] - '0' , str[idx + 1]);
		// 현재 값 + 괄호 안 계산 값 
		dfs(idx + 4, calculate(calc, temp, op));
	}

	// 괄호 없이 계산.
	dfs(idx + 2, calculate(calc, str[idx] - '0', op));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> str;

	dfs(0, 0);

	cout << res;
}


