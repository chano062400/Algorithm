#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

char arr[201][201];
int install[201][201];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int r, c, n, second = 2;

// 0 초기 1 무 2 설치 3 폭파 4 설치 5 폭파

void explosion(int cursecond)
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (cursecond - install[i][j] == 3)
			{
				arr[i][j] = '.';

				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
					
					arr[nx][ny] = '.';
				}
			}
		}
	}
}

void bombinstall(int cursecond)
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (arr[i][j] == '.')
			{
				arr[i][j] = 'O';
				install[i][j] = cursecond;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c >> n;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'O')
			{
				install[i][j] = 0;
			}
			else
			{
				install[i][j] = -1;
			}
		}
	}

    if(n < 1)
    {
        for (int i = 1; i <= r; i++)
	    {
		    for (int j = 1; j <= c; j++)
		    {
			    cout << arr[i][j];
		    }
		cout << '\n';
	    }
        return 0;
    }
    
	while (second < n + 1)
	{
		if (second % 2 == 0)
		{
			bombinstall(second);
		}
		else
		{
			explosion(second);
		}
		second++;
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
	
}

