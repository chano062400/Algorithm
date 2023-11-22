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
using namespace std;

#define MAX 100000000

long long idx, limit, cnt;
int arr[8] = { 1,2,3,4,5,4,3,2 };
int fingeridx[6] = { 0,1,2,2,2,1 };
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> idx >> limit;
    
	long long div = limit / fingeridx[idx];
    long long finger = fingeridx[idx] * (div + 1);
	cnt = (div+1) * 8 ;

	for (int j = 7; j >= 0; j--)
	{
		if (arr[j] == idx)
		{
			finger--;
			if (finger == limit)
			{
				cout << cnt - 1;
				break;
			}
		}
		cnt--;
	}

}