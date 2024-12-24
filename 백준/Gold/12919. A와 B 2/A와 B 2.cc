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

void back(string cur, string target)
{
	if (cur == target)
	{
		cout << 1;
		exit(0);
	}

	if (cur.length() < target.length()) return;

	if (cur.back() == 'A')
	{
		string temp = cur;
		temp.pop_back();
		back(temp, target);
	}
	
	if(cur[0] == 'B')
	{
		string temp = cur.substr(1);
		reverse(temp.begin(), temp.end());
		back(temp, target);
	}
}	

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string a, b;
	cin >> a >> b;

	back(b, a);
	cout << 0;
}


