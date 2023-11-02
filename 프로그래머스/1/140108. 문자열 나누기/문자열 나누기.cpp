#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    char startch = s[0];
    int startcnt =0, othercnt=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == startch) startcnt++;
        if(s[i] != startch) othercnt++;
        
        if(startcnt == othercnt || (startcnt != othercnt && i == s.length() - 1))
        {
            answer++;
            startcnt =0;
            othercnt =0;
            startch = s[i+1];
        }
    }
    
    return answer;
}