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

int getpriority(char ch)
{
    if (ch == '+') return 1;
    if (ch == '-') return 1;
    if (ch == '*') return 2;
    if (ch == '/') return 2;
    if (ch == '(') return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	stack<char> st;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];

		if (ch >= 'A' && ch <= 'Z')
		{
			cout << ch;
		}
		else if (ch == '(')
		{
			st.push('(');
		}
		else if (ch == ')')
		{
			while (st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && getpriority(st.top()) >= getpriority(ch))
			{
				cout << st.top();
				st.pop();
			}
			st.push(ch);
		}

	}

	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}

}

    