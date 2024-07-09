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

int N, L;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> L;
	
	int start = -1, count = 0;

	for (int i = L; i <= 100; i++)
	{
		int C = i * (i - 1) / 2;

		if ((N - C) % i == 0 && (N - C) / i >= 0)
		{
			start = (N - C) / i;
			count = i;
			break;
		}
	}

	if (start < 0) cout << start;

	for (int i = 0; i < count; i++)
	{
		cout << start + i << " ";
	}

}