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

int height[257], n, m, b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> b;

	int minheight = 256, maxheight = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;

			minheight = min(minheight, a);
			maxheight = max(maxheight, a);
			height[a]++;
		}
	}

	// 최소 시간이 될 높이는 최고, 최저 높이의 중간 지점이 된다.
	int i = minheight, j = maxheight, mincnt = height[i], maxcnt = height[j], time = 0;
	while (i < j)
	{
		// 쌓기
		if (mincnt <= b && mincnt <= maxcnt * 2)
		{
			b -= mincnt;
			time += mincnt;
			mincnt += height[++i];
		}
		// 제거
		else
		{
			b += maxcnt;
			time += maxcnt * 2;
			maxcnt += height[--j];
		}
	}
    cout << time << " " << i << '\n';
}

