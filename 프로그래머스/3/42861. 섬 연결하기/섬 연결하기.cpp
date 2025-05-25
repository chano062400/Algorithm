#include <bits/stdc++.h>

using namespace std;

int parent[101];

int Find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    
    if(x == y) return;
    
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

bool cmp(vector<int>& v1, vector<int>& v2)
{
    if(v1[2] == v2[2]) 
    {
        if(v1[0] == v2[0]) return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
    return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < costs.size(); i++)
    {
        int cur = costs[i][0];
        int next = costs[i][1];
        int cost = costs[i][2];
        if(Find(cur) != Find(next))
        {
            Union(cur, next);
            answer += cost;
        }
    }
    
    return answer;
}