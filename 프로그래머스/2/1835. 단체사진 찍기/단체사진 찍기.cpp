#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;

    vector<char> friends = {'A','C','F','J','M','N','R','T'};
    do
    {
        map<char,int> loc;
        string str;
        for(int i = 0 ; i < friends.size(); i++)
        {
            loc[friends[i]] = i;
            str += friends[i];
        }

        
        bool flag = false;
        for(int i = 0; i < data.size(); i++)
        {
            char c1 = data[i][0];
            char c2 = data[i][2];
            int dif = data[i][4] - '0';
            if(data[i][3] == '=')
            { 
                if(abs(loc[c1] - loc[c2]) == dif + 1) continue;
                flag = true;
            }
            else if(data[i][3] == '<')
            {
                if(abs(loc[c1] - loc[c2]) <= dif) continue;
                flag = true;
            }
            else
            {
                if(abs(loc[c1] - loc[c2]) >= dif + 2) continue;
                flag = true;
            }
            if(flag) break;
        }
        if(!flag) answer++;
    }
    while(next_permutation(friends.begin(), friends.end()));
    return answer;
}