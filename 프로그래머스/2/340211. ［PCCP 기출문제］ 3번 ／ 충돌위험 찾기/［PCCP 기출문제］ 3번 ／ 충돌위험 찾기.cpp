#include <bits/stdc++.h>
using namespace std;

struct info
{
    int x, y, time;  
    bool operator<(const info& other) const 
    {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return time < other.time;
    }
};

map<int,pair<int,int>> pos;
map<info, int> num;
    
void MoveTo(const vector<vector<int>>& routes)
{
    for(int i = 0; i < routes.size(); i++)
    {
        pair<int,int> sp = pos[routes[i][0]];
        info cur = {sp.first, sp.second, 0};
        num[cur]++;
        int time = 1;
        for(int j = 1; j < routes[i].size(); j++)
        {
            pair<int,int> cp = {cur.x, cur.y};
            pair<int,int> tp = pos[routes[i][j]];
            while(cp.first != tp.first)
            {
                if(cp.first < tp.first) ++cp.first;
                else --cp.first;
                cur = {cp.first, cp.second, time};
                num[cur]++;
                ++time;
            }
            while(cp.second != tp.second)
            {
                if(cp.second < tp.second) ++cp.second;
                else --cp.second;
                cur = {cp.first, cp.second, time};
                num[cur]++;
                ++time;
            }
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    for(int i = 1; i <= points.size(); i++)
    {
        pos[i] = { points[i-1][0], points[i-1][1] };
    }
    
    MoveTo(routes);
    
    for(auto information : num)
    {
        if(information.second > 1) answer++;
    }
    
    return answer;
}