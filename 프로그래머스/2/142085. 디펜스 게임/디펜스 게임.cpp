#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;  
    for(int i=0; i<enemy.size(); i++)
    {
        if(n >= enemy[i])
        {
            pq.push(enemy[i]);
            n -= enemy[i];
        }
        else
        {
            if(k)
            {
                k--;
                
                if(!pq.empty())    
                {
                    int top = pq.top();
                    pq.pop();  
                    // 이전 라운드에 무적권 사용
                    if(top >= enemy[i])
                    {
                        n += top - enemy[i];
                        pq.push(enemy[i]);
                    }
                    // 이번 라운드에 무적권 사용
                    else
                        pq.push(top);
                }
            }
            else 
            {
                return i;
            }
        }
    }

    return enemy.size();
}