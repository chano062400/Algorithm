#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,int>> v;
    map<int,int> tnum; // 숫자, 나온 횟수
    for(int i=0; i<s.length(); i++)
    {
        if(!isdigit(s[i])) s[i] = ' ';
    }
    
    int num =0;
    stringstream ss;
    ss.str(s);
    while(ss >> num) 
    {
        if(tnum.count(num) == 0) tnum[num] =1;
        else tnum[num]++;
    }
    
    for(auto n : tnum) v.push_back({n.second, n.first});
    
    sort(v.begin(), v.end(), greater<>());
    
    for(auto n : v) answer.push_back(n.second);
    
    return answer;
}
