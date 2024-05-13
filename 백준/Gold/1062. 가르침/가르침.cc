#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<string> v;
char south[5] = {'a', 'n' , 't', 'i', 'c'};
bool alpha[26], canread;
int n, k, mx =0, cnt=0, canreads=0;

void back(int index, int cnt)
{
	
	if (cnt == k - 5)
	{
		canreads = 0;
		for (int i = 0; i < v.size(); i++)
		{
			canread = true;
			for (int j = 0; j < v[i].length(); j++)
			{
				if (!alpha[v[i][j] - 'a'])
				{
					canread = false;
					break;
				}
			}
			if (canread) canreads++;
		}

		mx = max(mx, canreads);
	}

	for (int i = index; i < 26; i++)
	{
		if (!alpha[i])
		{
			alpha[i] = 1;
			back(i, cnt + 1);
			alpha[i] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < 5; i++)
	{
		alpha[south[i] - 'a'] = 1;
	}

	if (k <= 4) cout << "0";
	else {
		back(0, 0);

		cout << mx;
	}
}