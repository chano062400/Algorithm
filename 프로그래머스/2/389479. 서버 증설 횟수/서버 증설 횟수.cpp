#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0, server = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i < players.size(); i++)
    {
        // 제한 시간 지난 서버 제거
        while(!pq.empty())
        {
            int limit = pq.top().second;
            if(i > limit) pq.pop();
            else break;
        }
        
        int num = players[i];
        if(num >= m)
        {
            int size = pq.size();
            // 서버가 수용할 수 있는 플레이어 수
            int allowplayers = size * m;
            if(allowplayers >= num) continue;
            
            // 서버 증설 횟수
            int cnt = (num - allowplayers) / m;
            cout << num << " " << allowplayers << " " << cnt << '\n';
            while(cnt--)
            {
                pq.push({i, i + k - 1});
                answer++;
            }
        }
    }
    return answer;
}