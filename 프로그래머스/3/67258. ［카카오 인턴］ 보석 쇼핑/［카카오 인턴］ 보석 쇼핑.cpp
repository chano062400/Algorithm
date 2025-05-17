#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> gem;
    for(const auto& name : gems) gem[name] = 0;
    int size = gem.size();
    int s = 0, e = 0, cnt = 1, minlen = gems.size();
    
    pair<int, int> answer;
    gem[gems[0]] = 1;
    while(s <= e)
    {
        if(cnt < size)
        {
            if(++e >= gems.size()) break;
            if(gem[gems[e]]++ == 0)
            {
                cnt++;
            }
        }
        else
        {
            int curlen = e - s + 1;
            if((curlen == minlen && s <= answer.first) || curlen < minlen)
            {
                minlen = curlen;
                answer.first = s;
                answer.second = e;
            }
         
            if(--gem[gems[s++]] == 0)
            {
                cnt--;
            }
        }
    }
        
    return { answer.first + 1 , answer.second + 1};
}