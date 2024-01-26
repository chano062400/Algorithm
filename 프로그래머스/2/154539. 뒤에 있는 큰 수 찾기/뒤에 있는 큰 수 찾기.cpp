#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> st;
    for(int i = numbers.size() - 1; i >= 0; i--)
    {
        int num = numbers[i];
        while(!st.empty())
        {
            if(st.top() > num)
            {
                answer.push_back(st.top());
                st.push(num);
                break;
            }
            else st.pop();
        }
        
        if(st.empty())
        {
            answer.push_back(-1);
            st.push(num);
        }
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}