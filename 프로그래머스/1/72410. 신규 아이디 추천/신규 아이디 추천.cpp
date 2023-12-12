#include <string>
#include <vector>
#include <regex>
using namespace std;

string solution(string new_id) {
    string answer = "";
    for (auto& s : new_id) if (s >= 'A' && s <= 'Z') s = tolower(s);
    for (auto s : new_id) if ((s >= 'a' && s <= 'z') || isdigit(s) || s == '_' || s == '-' || s == '.') answer.push_back(s);
    if(!answer.empty())
    {
        while (1)
        {
            if (answer.find("..") != string::npos) answer.erase(answer.find(".."), 1);
            if (answer.find("..") == string::npos) break;
        }
        while (1)
        {
            if (answer[0] == '.') answer.erase(0, 1);
            if (answer[answer.length() - 1] == '.') answer.erase(answer.length() - 1, 1);
            if (answer.front() != '.' && answer.back() != '.') break;
        }
    }
    if(answer.empty()) answer += "a";
    if(answer.length() >= 16) answer = answer.substr(0,15); if(answer.back() == '.') answer.pop_back();
    if (answer.length() <= 2) 
    {
        while (1){ answer += answer.back(); if(answer.length() == 3) break; }
    }
    return answer;
}