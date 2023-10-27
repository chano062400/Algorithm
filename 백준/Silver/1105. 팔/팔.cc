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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string l, r;
	cin >> l >> r;

	int lcnt=0, rcnt=0;
	
	if (l.length() < r.length())
	{
		cout << 0;
		return 0;
	}
	else if (l.length() == r.length())
	{
		int cnt = 0;
		for (int i = 0; i < l.length(); i++)
		{
			if (l[i] != r[i]) break;
			if (l[i] == r[i] && l[i] == '8') cnt++;
		}
		cout << cnt;

	}
	
}