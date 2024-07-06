#include<iostream>
#include<algorithm>
using namespace std;

int arr[200001];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + a );

	int start = 1, end = arr[a-1] - arr[0], prev, ans = 0, cnt;
	while (start <= end)
	{
		prev = arr[0];
		cnt = 1;
		int mid = (start + end) / 2;
		for (int i = 1; i <= a; i++)
		{
			if (arr[i] - prev >= mid)
			{
				cnt++;
				prev = arr[i];
			}
		}

		if (cnt >= b)
		{
			ans = max(mid, ans);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << ans;
}

