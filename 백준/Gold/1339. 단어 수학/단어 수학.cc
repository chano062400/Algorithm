#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

vector<string> v;
int alphabet[26] = { 0, };

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, num = 0, rank = 9,result=0, Len=0;
	cin >> a;
	string str;
	for (int i = 0; i < a; i++)
	{
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < a; i++)
	{
		Len = v[i].length();
		for (int j = 0; j <= Len - 1; j++)
		{
			int temp = v[i][j] - 'A';
			num = pow(10, Len - 1 - j);
			alphabet[temp] += num;
		}
	}

	sort(alphabet, alphabet + 26,cmp);


	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] == 0) break;
		result = result + (alphabet[i] * rank);
		rank--;
	}

	cout << result;
}
