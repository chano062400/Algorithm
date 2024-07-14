#include<iostream>
#include<algorithm>
using namespace std;

int arr[10001];
int dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a,MAX=0;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = arr[0]+arr[1];
	dp[2] = max(arr[1]+arr[2], arr[0] + arr[2]);
	dp[3] = max(dp[1]+arr[3],dp[0]+arr[2]+arr[3]);
	
	for (int i = 4; i < a; i++)
	{
		dp[i] = max(dp[i-2]+arr[i], max(dp[i-3]+ arr[i-1] + arr[i], dp[i-4]+arr[i-1]+ arr[i]));
	}

	for (int i = 0; i < a; i++)
	{
		if (dp[i] > MAX)
			MAX = dp[i];
	}

	cout << MAX;
}

