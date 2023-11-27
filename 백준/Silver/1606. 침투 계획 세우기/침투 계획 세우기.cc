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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	long long x, y, res = 1, cnt=0;
	cin >> x >> y;
	while (cnt != x + y)
	{
		res += cnt * 6;
		cnt++;
	}

	if (y == 0) cout << res;
	else cout << res + y;

}
