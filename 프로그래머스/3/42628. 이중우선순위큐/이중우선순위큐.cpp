#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    for(auto operation : operations)
    {
        char ch = operation[0];
        string str = operation.substr(2, operation.length() - 2);
        int num = stoi(str);
        if(ch == 'I')
        {
            ms.insert(num);
        }
        else
        {
            if(ms.empty()) continue;
            
            if (num == 1) 
            {
                auto it = --ms.end();
                ms.erase(it);
            } 
            else 
            {
                auto it = ms.begin();
                ms.erase(it);
            }
        }
    }
    
    if(ms.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*--ms.end());
        answer.push_back(*ms.begin());
    }
    
    return answer;
}