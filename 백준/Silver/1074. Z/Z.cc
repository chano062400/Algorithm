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

int n, r, c, res=0;
int arr[10000];
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> r >> c;
	long long len = pow(2, n);
	
	r++;
	c++;

	while (len >= 2 )
	{
		int Pow = len / 2;

		if (r > len / 2)
		{
			if (c > len / 2)
			{
				res += Pow * Pow * 3;
			}
			else
			{
				res += Pow * Pow * 2;
			}
		}
		else
		{
			if (c > len / 2)
			{
				res += Pow * Pow * 1;
			}
			else
				res += 0;


		}
		if (r > len / 2) r -= len / 2;
		if (c > len / 2) c -= len / 2;
		len /= 2;
		
	}

	cout << res;
}