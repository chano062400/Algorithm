#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i=1; i<s.length(); i++)
    {
        if(s[i-1] == ' ') 
        {
            string str = s.substr(0, i);
            if(!isdigit(str[0])) str[0] = toupper(str[0]);
            for(int j=1; j<str.length(); j++)
            {
                str[j] = tolower(str[j]);
            }
            answer += str;
            s.erase(0, i);
            i = 0;
        }
    }
    
    if(!isdigit(s[0])) s[0] = toupper(s[0]);
    for(int j=1; j<s.length(); j++)
    {
        s[j] = tolower(s[j]);
    }
    answer += s;
    return answer;
}