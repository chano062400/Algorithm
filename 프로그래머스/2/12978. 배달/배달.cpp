#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[51];
vector<pair<int,int>> v[51];

void dijkstra(int start)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start] = 0;
    
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int curdist = pq.top().first;
        pq.pop();
        
        if(curdist > dist[cur]) continue;
        
        for(int i=0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].second;
            int nextdist = curdist + v[cur][i].first;
            
            if(nextdist < dist[next])
            {
                dist[next] = nextdist;
                pq.push({nextdist, next});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i=0; i<road.size(); i++)
    {
        int s = road[i][0], e = road[i][1], c = road[i][2];
        v[s].push_back({c,e});
        v[e].push_back({c,s});
    }
    
    fill(dist , dist +51, 9876543210);
    dijkstra(1);
    
    for(int i=1; i<=N; i++)
    {
        if(dist[i] <= K) answer++;
    }
    return answer;
}