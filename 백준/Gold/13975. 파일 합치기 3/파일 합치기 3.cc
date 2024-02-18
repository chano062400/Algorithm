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
using namespace std;

int t,n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> v;
        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            int size;
            cin >> size;
            v.push_back(size);
        }

		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 0; i < v.size(); i++)
		{
			pq.push(v[i]);
		}

		while (1)
		{
			if (pq.size() == 1) break;

			long long first = pq.top();
			pq.pop();
			long long second = pq.top();
			pq.pop();

			long long temp = first + second;
			res += temp;
			pq.push(temp);
		}

		cout << res << '\n';

    }
};

