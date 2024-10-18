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

int arr[1025][1025], arr2[1025][1025];
int n;
vector<int> second;

int dq(int x, int y, int len)
{
    if (len == 2)
    {
        vector<int> v;
        for (int i = x; i < x + len; i++)
        {
            for (int j = y; j < y + len; j++)
            {
                v.push_back(arr[i][j]);
            }
        }

        sort(v.begin(), v.end(), greater<int>());

        return v[1];
    }

    vector<int> res;

    res.push_back(dq(x, y, len / 2));
    res.push_back(dq(x, y + len / 2, len / 2));
    res.push_back(dq(x + len / 2, y, len / 2));
    res.push_back(dq(x + len / 2, y + len / 2, len / 2));

    sort(res.begin(), res.end(), greater<int>());
    return res[1];
}

void makematrix(int size)
{
	int idx = 0;
	for (int i = 1; i <= sqrt(size); i++)
	{
		for (int j = 1; j <= sqrt(size); j++)
		{
			arr[i][j] = second[idx++];
		}
	}
}

void copy()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = arr2[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << dq(1, 1, n);
}