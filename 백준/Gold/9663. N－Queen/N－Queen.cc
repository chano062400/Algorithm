#include<iostream>
#include<vector>
using namespace std;

int n,cnt=0;
int check1[14];
int check2[27];
int check3[27];

void bt(int row)
{
	if (row == n)
	{
		cnt++;
		return;
	}


	for (int col = 0; col < n; col++)
	{
		if (check1[col] || check2[row + col] || check3[row - col + n - 1])
			continue;

		check1[col] = true;
		check2[row + col] = true;
		check3[row - col + n - 1] = true;

		bt(row + 1);

		check1[col] = false;
		check2[row + col] = false;
		check3[row - col + n - 1] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	bt(0);
	cout << cnt;
	
}
