#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
vector<int> v,v2,v3;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,b;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		v.push_back(b);
	}

	sort(v.begin(), v.end());

	int GCD = v[1] - v[0];
	for (int i = 2; i < v.size(); i++)
	{
		 GCD = gcd(GCD, v[i] - v[i - 1]);
	}

	for (int i = 2; i * i <= GCD; i++)
	{
		if (GCD % i == 0)
		{
			v2.push_back(i);
			v2.push_back(GCD / i);
		}
	}
	
	v2.push_back(GCD);
	
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << '\n';
	}
}

