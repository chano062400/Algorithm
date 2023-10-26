#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include "algorithm"
#include <cmath>
#include <stack>
#include <regex>
#include <map>
using namespace std;

int x, y, cnt=0;
int A[51][51], B[51][51];

bool check()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (A[i][j] != B[i][j]) return false;
		}
	}

	return true;
}

void Flip(int sx, int sy)
{
	for (int i = sx; i < sx + 3; i++)
	{
		for (int j = sy; j < sy + 3; j++)
		{
			if (A[i][j] == 1) A[i][j] = 0;
			else if(A[i][j] == 0) A[i][j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> x >> y;
	
	for (int i = 0; i < x; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < y; j++)
		{
			A[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < x; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < y; j++)
		{
			B[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < x - 2; i++)
	{
		for (int j = 0; j < y - 2; j++)
		{
			if (A[i][j] != B[i][j]) 
			{
				Flip(i, j);
				cnt++;
			}
		}
	}

	if (!check()) cout << -1;
	else cout << cnt;
}