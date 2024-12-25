#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int, vector<int>, less<int>> pq;
    for(int work : works) pq.push(work);
    
    while(!pq.empty())
    {
        if(n-- == 0) break;
        
        int cur = pq.top();
        pq.pop();
        
        if(--cur > 0)
        {
            pq.push(cur);
        }
    }
    
    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        
        answer += (long long) pow(cur, 2);
    }
    
    return answer;
}