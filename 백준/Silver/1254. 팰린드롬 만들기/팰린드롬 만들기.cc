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

	string str, temp;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++)
	{
		string temp = str;
		string add = str.substr(0, i);
		reverse(add.begin(), add.end());
		temp += add;
			 
		string rev = temp;
		reverse(rev.begin(), rev.end());

		if (temp == rev)
		{
			cout << temp.length() << '\n';
			return 0;
		}
	}

}

