#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include "algorithm"
#include <cmath>

using namespace std;

int parent[1001];

int Find(int x)
{
	if (parent[x] == x) return x;

	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y) return;

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	vector<pair<float, float>> star;
	vector<pair< float, pair<float, float>>> stars;

	int n;
	float res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		float x, y;
		cin >> x >> y;
		star.push_back({ x,y });
	}

	for (int i = 0; i < star.size(); i++)
	{
		for (int j = 1; j < star.size(); j++)
		{
			float dist = sqrt(pow(star[i].first - star[j].first, 2) + pow(star[i].second - star[j].second, 2));
			stars.push_back({ dist, {i,j} });
		}
	}
	
	sort(stars.begin(), stars.end());

	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < stars.size(); i++)
	{
		if (Find(stars[i].second.first) != Find(stars[i].second.second))
		{
			Union(stars[i].second.first, stars[i].second.second);
			res += stars[i].first;
		}
	}
	
	cout.precision(3);
	cout.fixed;
	cout << res;

}