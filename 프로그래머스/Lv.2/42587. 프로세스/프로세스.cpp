#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,bool>> q;
    stack<int> st;
    
    for(int i = 0; i<priorities.size(); i++)
    {
        if(i == location) q.push({priorities[i], true});
        else q.push({priorities[i],false});
    }
    
    sort(priorities.begin(), priorities.end());
    
    for(auto p : priorities) st.push(p);
    
    while(!q.empty())
    {
        if(q.front().first < st.top())
        {
            q.push(q.front());
            q.pop();
        }
        else
        {
            if(q.front().second == true)
            {
                answer++;
                break;
            }
            q.pop();
            st.pop();
            answer++;
        }
    }

    return answer;
}