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

int alpha[26];
char alphabet[26] = { 'A', 'B', 'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string str;
	cin >> str;

	sort(str.begin(), str.end());
	
	for (int i = 0; i < str.length(); i++)
	{
		alpha[str[i] - 'A']++;
	}

	string pel = "";
	int oddcnt = 0;
	bool notpel = false, isodd = false;
	char odd;

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > 0)
		{
			int cnt = 0;
			if (alpha[i] % 2 == 1)
			{
				oddcnt++;
				isodd = true;
				odd = alphabet[i];
			}
			if (oddcnt >= 2)
			{
				notpel = true;
				isodd = false;
				break;
			}

			while (cnt < alpha[i] / 2)
			{
				pel += alphabet[i];
				cnt++;
			}
		}
	}

	string res = "";
	if (!notpel && isodd)
	{
		res += pel + odd;
		reverse(pel.begin(), pel.end());
		res += pel;

		cout << res;
	}
	else if (!notpel && !isodd)
	{
		res += pel;
		reverse(pel.begin(), pel.end());
		res += pel;

		cout << res;
	}
	else if (notpel)
	{
		cout << "I'm Sorry Hansoo";
	}

}