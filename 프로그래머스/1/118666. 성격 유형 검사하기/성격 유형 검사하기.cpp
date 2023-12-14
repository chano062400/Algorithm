#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<vector<char>> alpha = {{'R','T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
    map<char,int> mp;
    for(auto s : alpha) for(auto n : s) mp.insert({n,0});
    for(int i=0; i<survey.size(); i++)
    {
        int score = choices[i] - 4;
        if(score < 0) mp[survey[i][0]] += abs(score);
        if(score > 0) mp[survey[i][1]] += score;   
    }
    for(auto s : alpha)
    {
        if(mp[s[0]] == mp[s[1]]) answer.push_back(min(s[0],s[1]));
        else if(mp[s[0]] > mp[s[1]]) answer.push_back(s[0]);
        else answer.push_back(s[1]);
    }
    return answer;
}