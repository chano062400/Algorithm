#include <bits/stdc++.h>
using namespace std;

void copy(int rows, int columns, vector<vector<int>>& arr, vector<vector<int>>& temp)
{
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            temp[i][j] = arr[i][j];
        }
    }
}

int rotate(int lx, int ly, int rx, int ry, vector<vector<int>>& arr, vector<vector<int>>& temp)
{
    vector<int> v;
    for(int y = ly; y < ry; y++)
    {
        arr[lx][y + 1] = temp[lx][y]; 
        v.push_back(temp[lx][y]);
    }
    
    for(int x = lx; x < rx; x++)
    {
        arr[x + 1][ry] = temp[x][ry];
        v.push_back(temp[x][ry]);
    }
    
    for(int y = ry; y > ly; y--)
    {
        arr[rx][y - 1] = temp[rx][y];
        v.push_back(temp[rx][y]);
    }
    
    for(int x = rx; x > lx; x--)
    {
        arr[x - 1][ly] = temp[x][ly];
        v.push_back(temp[x][ly]);
    }
    
    sort(v.begin(), v.end());
    
    return v[0];
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr(rows + 1, vector<int>(columns + 1,0)), temp = arr;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            arr[i][j] = columns * (i-1) + j;
            temp[i][j] = arr[i][j];
        }
    }
    
    for(auto query : queries)
    {
        int lx = query[0], ly = query[1], rx = query[2], ry = query[3];
        answer.push_back(rotate(lx, ly, rx, ry, arr, temp));
        copy(rows, columns, arr, temp);
    }
    
    return answer;
}