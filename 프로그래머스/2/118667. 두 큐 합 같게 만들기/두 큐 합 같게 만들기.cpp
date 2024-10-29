#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2 = 0, total = 0;
    int answer = 0, size = queue1.size() + queue2.size();
    queue<int> q1, q2;
    for(int num : queue1) 
    {
        q1.push(num);
        sum1 += num;
    }
    for(int num : queue2) 
    {
        q2.push(num);
        sum2 += num;
    }
    total = sum1 + sum2;
    
    while(sum1 != sum2)
    {
        if(answer > size * 2) return -1;
        
        if(sum1 > sum2)
        {
            int num = q1.front();
            if(num > total) return -1;
            q1.pop();
            q2.push(num);
            sum1 -= num;
            sum2 += num;
        }
        else if(sum1 < sum2)
        {
            int num = q2.front();
            if(num > total) return -1;
            q2.pop();
            q1.push(num);
            sum1 += num;
            sum2 -= num; 
        }
        answer++;
    }
    
    return answer;
}