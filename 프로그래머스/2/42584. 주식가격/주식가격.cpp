#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> st;
    vector<pair<int,int>> v;
    for(int i=0; i<prices.size(); i++)
    {
        st.push(prices[i]);
    }
    
    int size = st.size();
    for(int i=0; i<size; i++)
    {
        if(answer.empty()) 
        {
            answer.push_back(0);
        }
        else
        {
            bool dec = false;
            for(int i= v.size() - 1; i >= 0; i--)
            {
                if(st.top() > v[i].second)
                {
                    answer.push_back(v[i].first - st.size());
                    dec = true;
                    break;
                }
            }
            if(!dec) answer.push_back(prices.size() - st.size());
        }
        
        v.push_back({st.size(), st.top()});
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}