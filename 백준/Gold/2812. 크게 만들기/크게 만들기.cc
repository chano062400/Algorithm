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
using namespace std;

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, k, cnt = 0;
	cin >> n >> k;

	string str, temp;
	cin >> str;

	stack<char> st;
	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		if (st.empty())
		{
			st.push(ch);
		}
		else
		{
			while (!st.empty() && ch > st.top())
			{
				if (st.empty()) break;
				if (str.length() - i + st.size() == n - k)
				{
					temp = str.substr(i);
					break;
				}
				st.pop();
				cnt++;
			}

			if (str.length() - i + st.size() == n - k)
			{
				temp = str.substr(i);
				break;
			}

			st.push(ch);
		}
	}

	string res;
	if (cnt < k)
	{
		while (cnt++ < k)
		{
			st.pop();
		}
	}

	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}

	reverse(res.begin(), res.end());
	res += temp;
	cout << res;
}


