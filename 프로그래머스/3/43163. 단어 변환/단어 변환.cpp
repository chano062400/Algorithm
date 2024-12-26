#include <bits/stdc++.h>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    set<string> check;
    queue<pair<string,int>> q;
    q.push({begin, 0});
    
    while(!q.empty())
    {
        string cur = q.front().first;
        int cnt = q.front().second;
        if(cur == target)
        {
            return cnt;
        }
        q.pop();
        
        for(string word : words)
        {
            if(check.find(word) != check.end()) continue;
            
            int dif = 0;
            bool flag = true;
            for(int i = 0; i < word.length(); i++)
            {
                if(word[i] != cur[i])
                {
                    if(++dif > 1) 
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) continue;
            
            cout << word << " " << cnt << '\n';
            check.insert(word);
            q.push({word, cnt + 1});
        }
    }
    return 0;
}