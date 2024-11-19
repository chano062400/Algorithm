#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
using namespace std;

int n, m, x, y ,k;
int arr[20][20];
int dice[7];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

void east()
{
    int temp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = temp;
}

void west()
{
    int temp = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = temp;
}

void north()
{
    int temp = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[5];
    dice[5] = temp;
}

void south()
{
    int temp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = dice[2];
    dice[2] = temp;
}

void move(int dir)
{
    if (dir == 1) east();
    else if (dir == 2) west();
    else if (dir == 3) north();
    else south();

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> x >> y >> k;  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    dice[6] = arr[x][y];

    for (int i = 0; i < k; i++)
    {
        int dir;
        cin >> dir;
        if (x + dx[dir] < 0 || x + dx[dir] >= n || y + dy[dir] < 0 || y + dy[dir] >= m) continue;
        
        move(dir);
        
        x += dx[dir];
        y += dy[dir];
        
        if (arr[x][y] == 0)
        {
            arr[x][y] = dice[6];
        }
        else
        {
            dice[6] = arr[x][y];
            arr[x][y] = 0;
        }
       
        cout << dice[1] << '\n';
    }
    
}
