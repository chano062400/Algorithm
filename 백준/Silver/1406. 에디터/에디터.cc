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
using namespace std;


int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string str;
	cin >> str;
	int n;
	cin >> n;
	
	stack<char> left;
	stack<char> right;

	for (int i = 0; i < str.length(); i++)
	{
		left.push(str[i]);
	}

	for (int i = 0; i < n; i++)
	{
		char cmd;
		cin >> cmd;

		if (cmd == 'P')
		{
			char push;
			cin >> push;

			left.push(push);
		}
		else if (cmd == 'L') // 커서를 왼쪽으로 움직이면 커서 기준 오른쪽이 1개 많아지는 것 
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') // 커서를 오른쪽으로 움직이면 커서 기준 왼쪽이 1개 많아지는 것.
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B')
		{
			if (!left.empty())
			{
				left.pop();
			}
		}
	}

	while (!left.empty()) // left를 다 넣어서 출력할때는 거꾸로 출력해서 순서가 맞도록
	{
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) 
	{
		cout << right.top();
		right.pop();
	}
}