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
#include <map>
using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	
	int buy = 0, temp;
	
	while (1)
	{	
		temp = n + buy;
		int cnt = 0;
		while (temp != 0)
		{
			if (temp % 2 == 0) temp /= 2;
			else
			{
				temp /= 2;
				cnt++;
			}
		}
		if (cnt <= k)
		{
			cout << buy;
			break;
		}

		buy++;
	}
}