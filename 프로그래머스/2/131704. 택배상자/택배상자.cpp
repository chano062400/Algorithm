#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    int answer = 0, num = 1;
    stack<int> st;
    queue<int> q;
    
    for(int i = 0; i<order.size(); i++) q.push(order[i]);
    
    for(int i = 1; i <= q.front(); i++)
    {
        st.push(i);
    }
    
    while(!q.empty())
    {
        while(q.front() == st.top())
        {
            num = max(num, st.top());
            q.pop();
            st.pop();
            answer++;
            if(q.empty() || st.empty()) break;
        }

        if(num < q.front())
        {
            for(int i= num+1; i<=q.front(); i++) st.push(i);
        }
        else break;
        
    }
    
    return answer;
}