#include<iostream>
#include<algorithm>
using namespace std;

int RGB[1001][3];
int cost[1001][3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}

	for (int i = 1; i <=a; i++)
	{
		cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + RGB[i][0];
		cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + RGB[i][1];
		cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + RGB[i][2];
	}

	cout << min(cost[a][0], min(cost[a][1], cost[a][2]));
}
