#include <string>
#include <vector>

using namespace std;

bool isskip(char ch, string skip)
{
    for(int i=0; i < skip.length(); i++)
    {
        if(skip[i] == ch) return true;
    }
    return false;
}

string solution(string s, string skip, int index) {
    string answer = "";

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        
        for(int j = index; j > 0;)
        {
            ch +=1;
            
            if(ch == 'z' + 1) ch = 'a';

            if(!isskip(ch,skip)) j--;
        }
        
        answer += ch;
    }

    return answer;
}