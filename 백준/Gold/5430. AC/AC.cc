#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
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
		string func;
		cin >> func;
		queue<char> q;
		for (auto f : func)
		{
			q.push(f);
		}

		int n;
		cin >> n;
		string str;
		cin >> str;

		string str2 = str.substr(1, str.length() - 2);
		deque<int> dq;

		istringstream iss(str2);
		while (getline(iss, str, ','))
		{
			dq.push_back(stoi(str));
		}

		bool reverse = false;
		bool over = false;

		while(!q.empty())
		{
			char f = q.front();
			q.pop();
			
			if (f == 'R') reverse = !reverse;
			else
			{
				if (dq.empty())
				{
					cout << "error" << '\n';
					over = true;
					break;
				}

				if (!reverse)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (!over)
		{
			cout << "[";
			while (!dq.empty())
			{
				int num;
				!reverse ? num = dq.front() : num = dq.back();
				!reverse ? dq.pop_front() : dq.pop_back();

				if (dq.empty()) cout << num;
				else cout << num << ",";
			}
			cout << "]" << '\n';
		}
	}
}