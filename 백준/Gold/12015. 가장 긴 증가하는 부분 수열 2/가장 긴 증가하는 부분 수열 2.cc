#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,b;
	cin >> a;

	v.push_back(1000000);
	

	for (int i = 0; i < a; i++)
	{
		cin >> b;
		if (b > v.back()) v.push_back(b);
		else
		{
			int index =lower_bound(v.begin(), v.end(), b) - v.begin();
			v[index] = b;
		}
	}

	cout << v.size();
	




}

