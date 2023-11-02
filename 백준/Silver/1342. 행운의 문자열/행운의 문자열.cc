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

string str;
int lucky = 0, res=0, Div =1;

vector<char> v;
bool check[26];
int Same[26];

int fact(int num)
{
	int sum = 1;
	for (int i = num; i > 0; i--)
	{
		sum *= i;
	}

	return sum;
}

bool islucky()
{
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1]) return false;
	}

	return true;
}

void back(int cnt)
{
	if (cnt == str.length())
	{
		if(islucky()) lucky++;
		return;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (!check[i])
		{
			v.push_back(str[i]);
			check[i] = 1;
			back(cnt + 1);
			check[i] = 0;
			v.pop_back();
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> str;
	
	sort(str.begin(), str.end());

	memset(Same, 0 ,sizeof(Same));

	for (int i = 0; i < str.length(); i++)
	{
		Same[str[i] - 'a']++;
	}

	back(0);

	for (int i = 0; i < 26; i++)
	{
		if (Same[i] != 0)
		{
			Div *= fact(Same[i]);
		}
	}

	res = lucky / Div;
	
	cout << res;

}