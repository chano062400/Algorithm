#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    sort(routes.begin(), routes.end());
    int s = routes[0][0], e = routes[0][1];
    for(int i = 1; i < routes.size(); i++)
    {
        pq.push({routes[i][0], routes[i][1]});
    }
    
    while(!pq.empty())
    {
        int cs = pq.top().first;
        int ce = pq.top().second;
        pq.pop();
        
        if(s <= cs && e >= cs) 
        {
            s = max(s, cs);
            e = min(e, ce);
        }
        else
        {
            s = cs;
            e = ce;
            answer++;
        }
    }
    
    return answer;
}