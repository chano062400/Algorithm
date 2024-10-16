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

char num[3] = { '1','2','3'};
int n;

bool check(string str)
{
	int len = str.length();
	for (int i = 1; i <= len / 2; i++)
	{
		string first = str.substr(len - (i * 2), i);
		string second = str.substr(len - i, i);
		if (first == second) return false;
	}
	return true;
}

void back(string str)
{
	if (!check(str)) return;

	if (str.length() == n)
	{
		cout << str;
		exit(0);
	}

	for (int i = 0; i < 3; i++)
	{
		back(str + num[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	back("");

}

