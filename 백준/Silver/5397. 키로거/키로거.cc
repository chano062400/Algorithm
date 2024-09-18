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

	int t;
	cin >> t;

	while (t--)
	{
		string str;
		cin >> str;
		stack<char> st, temp;

		for (int i = 0; i < str.length(); i++)
		{
			char ch = str[i];
			if (ch == '<')
			{
				if (st.empty()) continue;

				temp.push(st.top());
				st.pop();
			}
			else if (ch == '>')
			{
				if (temp.empty()) continue;

				st.push(temp.top());
				temp.pop();
			}
			else if (ch == '-')
			{
				if (st.empty()) continue;

				st.pop();
			}
			else
			{
				st.push(ch);
			}
		}
			string res = "";
			while (!st.empty())
			{
				res += st.top();
				st.pop();
			}

			reverse(res.begin(), res.end());

			while (!temp.empty())
			{
				res += temp.top();
				temp.pop();
			}

			cout << res << '\n';
		
	}
}

