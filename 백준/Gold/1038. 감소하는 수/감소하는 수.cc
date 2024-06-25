#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

#define MAX 1000000 

int n, index = 9;
queue<long long> q;
long long des[MAX + 1] = { 0 };


void back()
{
	while (index <= n)
	{
		if (q.empty()) return;

		long long desnum = q.front();
		q.pop();

		long long deslastnum = desnum % 10;

		for (int i = 0; i < deslastnum; i++)
		{
			q.push(desnum * 10 + i);
			des[++index] = desnum * 10 + i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		q.push(i);
		des[i] = i;
	}

	back();

	if (!des[n] && n != 0) cout << "-1";
	else cout << des[n];
}