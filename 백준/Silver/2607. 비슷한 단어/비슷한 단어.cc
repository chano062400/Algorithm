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

map<char, int> alpha;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		alpha[str[i]]++;
	}

	int res = 0;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> str;
		int len2 = str.length(), cnt = 0;
		map<char, int> copymap = alpha;

		for (int j = 0; j < str.length(); j++)
		{
			char ch = str[j];
			if (copymap.find(ch) != copymap.end() && copymap[ch] > 0)
			{
				copymap[ch]--;
				cnt++;
			}
		}
		// 길이가 같을 때 - DOG / GOD OR DOG / DOT
		if (len == len2 && (cnt == len || cnt == len - 1)) res++;
		// 처음 단어가 길 때 - DOLL / DOL
		else if (len == len2 + 1 && cnt == len - 1) res++;
		// 처음 단어가 짧을 때 - DOL / DOLL
		else if (len + 1 == len2 && cnt == len) res++;
	}

	cout << res;
}

