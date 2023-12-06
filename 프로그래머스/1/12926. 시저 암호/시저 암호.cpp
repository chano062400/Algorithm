#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(auto k : s) 
    {
        if(k == ' ') answer += ' ';
        else if(k > 'Z' && k+n > 'z') answer += k+n-26; 
        else if(k <= 'Z' && k+n > 'Z') answer += k+n-26; 
        else answer += k+n;
    }
    return answer;
}