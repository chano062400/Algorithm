#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> cp;
    
    for(auto p : participant) 
    {
        if(cp.count(p) == 0) cp.emplace(p,1);
        else cp[p]++;
    }
    
    for(auto p : completion) cp[p]--;
    
    for(auto p : cp) if(p.second > 0) answer += p.first;
    
    return answer;
}