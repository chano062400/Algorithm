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
using namespace std;

int cnt, type, cont, coup, res=0;
bool check[30001];

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	vector<int> plate;

	cin >> cnt >> type >> cont >> coup;

	for (int i = 0; i < cnt; i++)
	{
		int num;
		cin >> num;
		plate.push_back(num);
	}
	
	for (int i = 0; i < plate.size(); i++)
	{
		int flag = 0;
		for (int j = i; j < i + cont; j++)
		{
			if (check[plate[j % cnt]] || plate[j % cnt] == coup) continue;

			if (!check[plate[j % cnt]])
			{
				check[plate[j % cnt]] = 1;
				flag++;
			}
			
		}

		res = max(res, flag + 1);
		memset(check, 0, sizeof(check));
	}

	cout << res;
}