#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int xnum[10], ynum[10];

string solution(string X, string Y){
    string answer = "";
    for(auto s : X) xnum[s-'0']++;
    for(auto s : Y) ynum[s-'0']++;
    
    vector<int> v;
    for(int i=0; i<=9; i++)
    {
        if(xnum[i] && ynum[i])
        {
            int mn = min(xnum[i], ynum[i]);
            while(mn--)
            {
                v.push_back(i);
            }
        }
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i=0; i<v.size(); i++)
    {
       answer += to_string(v[i]); 
    }
    
    if(answer.length() == 0) answer = "-1";
    else if(answer[0] == '0') answer = "0";
    
    return answer;
}