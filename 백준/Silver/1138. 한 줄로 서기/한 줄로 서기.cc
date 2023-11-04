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

int n;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	vector<int> v(n), res(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		int index = 0;
		while (v[i] != 0)
		{
			if(res[index] == 0) v[i]--;
			index++;
		}

		while(res[index] != 0) index++;
		res[index] = i + 1;
	}

	for (auto s : res) cout << s << " ";
}