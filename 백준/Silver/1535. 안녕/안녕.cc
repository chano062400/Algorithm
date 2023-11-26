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
using namespace std;

int hp[20], joy[20], dp[101], n, res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> hp[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> joy[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 100; j >= hp[i]; j--) {
			dp[j] = max(dp[j], dp[j - hp[i]] + joy[i]);
		}
	}

	cout << dp[99];
}
