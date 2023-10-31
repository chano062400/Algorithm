#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include "algorithm"
#include <cmath>
#include <stack>
#include <regex>
#include <map>
using namespace std;

int n;

bool cmp(pair<int, int> v1, pair<int, int> v2)
{
	if (v1.first == v2.first) return v1.second < v2.second;
	return v1.first < v2.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	vector<pair<int, int>> v,lines;

	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({ start,end });
	}

	sort(v.begin(), v.end(),cmp);

	int start = v[0].first, end = v[0].second, sum = end -start;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].first > end)
		{
			start = v[i].first;
			end = v[i].second;
			sum += end - start;
		}
		else if (v[i].first <= end)
		{
			if (v[i].first < start)
			{
				sum += start - v[i].first;
				start = v[i].first;
			}
			if (v[i].second > end)
			{
				sum += v[i].second - end;
				end = v[i].second;
			}
		}
		
	}


	cout << sum;
}