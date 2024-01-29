#include <string>
#include <vector>

using namespace std;

int cnt = -1, answer = 0;
string str = "AEIOU";

void dfs(string now, string target)
{
    cnt++;
    
    if(now == target) 
    { 
        answer = cnt;
        return;
    }
    if(now.length() >= 5) return;
    
    for(int i=0; i < 5; i++)
    {
        dfs(now + str[i],target);
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}