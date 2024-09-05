#include<iostream>
#include<algorithm>
using namespace std;

int a, zero=0, one=0;
string s;
int arr[65][65];			

void check(int x, int y, int len)
{
	int zo = arr[x][y];

	for(int i = x; i<x+len; i++)
		for (int j = y; j < y + len; j++)
		{
			if (zo != arr[i][j])
			{
				cout << '(';
				check(x, y, len / 2);
				check(x, y +len/2 , len / 2);
				check(x+len/2, y, len / 2);
				check(x + len / 2, y + len / 2, len / 2);
				cout << ')';
				return;
			}
		}

	if (zo == 1) cout << 1;
	else cout << 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> s;
		for (int j = 0; j < a; j++)
			arr[i][j] = s[j] - '0';
	}
	check(0, 0, a);
}

