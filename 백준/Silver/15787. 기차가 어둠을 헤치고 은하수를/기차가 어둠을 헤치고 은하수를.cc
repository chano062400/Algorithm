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

    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b;
        if (a < 3)
        {
            cin >> c;
		}
		if (a == 1)
		{
			v[b] |= (1 << c); // 비어있는 자리 승객 탑승
		}
		else if (a == 2)
		{
			v[b] &= ~(1 << c); // 타고있는 승객 하차
		}
		else if (a == 3)
		{
			v[b] = v[b] << 1; // 모두 한자리씩 뒤로 밀고
			// (1 << 21) - 1 = 0111111111111111111111;
			v[b] &= ((1 << 21) - 1); // 20자리 넘어가지 않도록.
		}
		else
		{
			v[b] = v[b] >> 1; // 모두 한자리씩 앞으로 밀고
			v[b] &= ~1; // 1번 승객 하차
		}
    }
	
	vector<bool>v2(1 << 21, false);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!v2[v[i]]) res++;
		v2[v[i]] = true;
	}
    
    cout << res;
}