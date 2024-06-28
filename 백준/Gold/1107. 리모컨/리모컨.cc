#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int goal, temp, num, nw , cnt=0 ,len ,ans=1000000;
bool notwork[10];

int check(int a)
{
	if (a == 0) // 채널을 0으로 가서 +/-하는 경우
	{
		if (notwork[a]) return false;
		else return true;
	}

	len = 0;
	while (a > 0)  // 채널을 0이 아닌 다른 채널을 누르고 +/- 하는 경우
	{
		int b = a % 10;
		if (!notwork[b])
		{
			a /= 10;
			len++;
		}
		else 
			return false;
	}

	return len;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> goal >> num;
	temp = goal;

	for (int i = 0; i < num; i++)
	{
		cin >> nw;
		notwork[nw] = true;
	}

	ans = abs(100 - goal); // 채널 100에서 +/- 하는 경우

	for (int i = 0; i <= 1000000; i++)
	{
		len = check(i);
		if (len > 0)
		{
			cnt = abs(i - goal) + len;
			ans = min(ans, cnt);
		}
	}

	cout << ans;

}