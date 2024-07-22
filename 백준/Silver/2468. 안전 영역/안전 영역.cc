#include<iostream>
#include<algorithm>

using namespace std;

int arr[101][101];
bool checked[101][101];

int nexty[] = { 0, 0,1,-1 };
int nextx[] = { 1,-1,0,0 };

int a, cnt , answer = 1, MaxH = 1;

void reset()
{
    for(int y=0; y<a; y++)
    {
        for(int x=0; x<a; x++)
        {
            checked[y][x] =false;
        }
    }
}


void dfs(int y, int x, int height)
{
	checked[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + nexty[i];
		int nx = x + nextx[i];
		if (ny < 0 || ny >= a || nx < 0 || nx >= a) continue;
		if (checked[ny][nx] || arr[ny][nx] <= height) continue;
			
		
		dfs(ny, nx, height); 
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		

	cin >> a;

	for (int y = 0; y < a; y++)
	{
		for (int x = 0; x < a; x++)
		{
			cin >> arr[y][x];
			if (arr[y][x] > MaxH) MaxH = arr[y][x];
		}
	}

	for (int height = 1; height < MaxH; height++)
	{
		cnt = 0;
		
        reset();
        
		for (int y = 0; y < a; y++)
		{
			for (int x = 0; x < a; x++)
			{
				if (arr[y][x] > height && !checked[y][x])
				{
					cnt++;
					dfs(y, x, height);
				}
				else
					checked[y][x] = true;
			}
		}

		if (cnt > answer)
			answer = cnt;
	}

	cout << answer;
}

