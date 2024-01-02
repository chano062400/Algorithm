#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> q;
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        q.clear();
        for(auto ch : s) q.push_back(ch);
        
        int rot = i;
        while(rot--)
        {
            char ch = q.front();
            q.pop_front();
            q.push_back(ch);
        }
        
        if(q.front() == ')' || q.front() == '}' || q.front() == ']') continue;
        
        bool right = true;
        int size = q.size();
        for(int i=0; i < size; i++)
        {
            char ch = q.front();
            if(st.empty()) 
            {
                st.push(ch);
                q.pop_front();
            }
            else
            {
                if(st.top() == '(' && ch == ')') st.pop();
                else if(st.top() == '{' && ch == '}') st.pop();
                else if(st.top() == '[' && ch == ']') st.pop();
                else st.push(ch);
                
                q.pop_front();
            }
        }
        if(st.empty()) answer++;
        else while(!st.empty()) st.pop();
    }
    return answer;
}