#include <bits/stdc++.h>
using namespace std;

vector<string> answer, tempPath;
map<string, vector<pair<string, bool>>> airports;
int totalTicket;

bool dfs(string cur, int cnt) 
{
    tempPath.push_back(cur);
    if (cnt == totalTicket) 
    {
        answer = tempPath;
        return true;
    }

    for(int i = 0; i < airports[cur].size(); i++)
    {
        auto& next = airports[cur][i];
        if(!next.second)
        {
            next.second = true;
            if(dfs(next.first, cnt + 1)) return true;
            next.second = false;
        }
    }

    tempPath.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    totalTicket = tickets.size();

    for (auto& ticket : tickets) 
    {
        airports[ticket[0]].emplace_back(ticket[1], false);
    }

    for (auto& airport : airports) 
    {
        sort(airport.second.begin(), airport.second.end());
    }

    dfs("ICN", 0);
    return answer;
}