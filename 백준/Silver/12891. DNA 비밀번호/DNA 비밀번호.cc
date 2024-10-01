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

int dna[4];
char ch[4] = { 'A','C','G','T' };
int s, p;

bool check(const vector<char>& v, map<char, int>& num)
{
	for (int i = 0; i < 4; i++)
	{
		if (num[ch[i]] < dna[i]) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s >> p;

	vector<char> v(s);
	for (int i = 0; i < s; i++)
	{
		cin >> v[i];
	}

	string str = "";
	for (int i = 0; i < 4; i++)
	{
		cin >> dna[i];
	}

	int res = 0;
	map<char, int> num;
	// 첫 범위
	for (int i = 0; i <= p - 1; i++)
	{
		if (v[i] == 'A')
		{
			if (num.find(v[i]) == num.end()) num.insert({ 'A',1 });
			else num[v[i]]++;
		}
		if (v[i] == 'C')
		{
			if (num.find(v[i]) == num.end()) num.insert({ 'C',1 });
			else num[v[i]]++;
		}
		if (v[i] == 'G')
		{
			if (num.find(v[i]) == num.end()) num.insert({ 'G',1 });
			else num[v[i]]++;
		}
		if (v[i] == 'T')
		{
			if (num.find(v[i]) == num.end()) num.insert({ 'T',1 });
			else num[v[i]]++;
		}
	}
	if (check(v, num)) res++;

	for (int i = 1; i <= s - p; i++)
	{
		if(num.find(v[i - 1]) != num.end()) num[v[i - 1]]--;
		
		if (num.find(v[i + p - 1]) != num.end()) num[v[i + p - 1]]++;
		else num.insert({ num[v[i + p - 1]],1 });

		if (check(v, num)) res++;
	}

	cout << res;
}

