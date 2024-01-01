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
using namespace std;

int n, w, l, res = 1;
vector<int> truck;
int t[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        truck.push_back(weight);
    }
                        
    queue<int> q;
    q.push(truck[0]);
    t[0] = 1;
    int weight = truck[0], idx = 1;
    while (!q.empty())
    {

		for (int i = 0; i < idx; i++)
		{
			t[i]++;
			if (t[i] == w + 1)
			{
				weight -= truck[i];
				q.pop();
			}
		}
   
        if(idx < truck.size() && weight + truck[idx] <= l)
        {
            weight += truck[idx];
            q.push(truck[idx]);
            t[idx] = 1;
            idx++;
        }

        res++;
    }

    cout << res;
}
