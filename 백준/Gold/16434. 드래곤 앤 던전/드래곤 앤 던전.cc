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

#define MAX 999999000001

struct info
{
	int t, a, hp;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, atk;

    cin >> n >> atk;

	vector<info> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].t >> v[i].a >> v[i].hp;
	}

	long long start = 1, end = MAX * n, res = 0;

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long maxhp = mid, curhp = mid, curatk = atk;

		bool dead = false;

		for (int i = 0; i < n; i++)
		{
			long long t = v[i].t, a = v[i].a, hp = v[i].hp;
			
			// 몬스터와 전투
			if (t == 1)
			{
				long long cnt = hp / curatk; // 플레이어가 몬스터가 죽기 전까지 맞은 횟수.
				if (hp % curatk == 0) cnt--; // 몬스터가 플레이어를 때리기 전 죽음.

				curhp -= a * cnt;
				if (curhp <= 0)
				{
					dead = true;
					break;
				}
			}
			// 포션 방
			else if(t == 2)
			{
				curatk += a;
				curhp = min(maxhp, curhp + hp);
			}
		}

		if (dead) start = mid + 1;
		else
		{
			res = mid;
			end = mid - 1;
		}
	}

	cout << res;
}

