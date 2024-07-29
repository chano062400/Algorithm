#include <iostream>
using namespace std;

int n, cnt;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	
	while (n--)
	{
		long long from, to;
		cin >> from >> to;

		long long dist = to - from;

		long long i = 1;
		for (;; i++)
		{
			if (dist < i * i)
				break;
		}

		if (dist == (i - 1) * (i - 1))
		{
			cnt = (i - 1) * 2 - 1;
		}

		else if (dist > (i - 1) * (i - 1) && dist < i * i)
		{
			if (dist - (i - 1) * (i - 1) <= i - 1)
				cnt = (i - 1) * 2;
			else if (dist - (i - 1) * (i - 1) > i - 1)
				cnt = (i - 1) * 2 + 1;
		}

		else if (dist == i * i)
		{
			cnt = i * 2 - 1;
		}

		cout << cnt << '\n';
	}

	return 0;
}