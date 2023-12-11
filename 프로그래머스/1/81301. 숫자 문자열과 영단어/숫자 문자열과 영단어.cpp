#include <string>
#include <vector>
#include <map>
using namespace std;

string num[10] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    string answer = "";
    for(int i=0; i<s.length(); i++)
    {
        if(isdigit(s[i])) answer += s[i];
        else
        {
            for(int j=0; j<10; j++)
            {
                if(s.substr(i,3) == num[j] || s.substr(i,4) == num[j] || s.substr(i,5) == num[j])
                {
                    answer += to_string(j);
                    s.erase(i , num[j].length()-1);                
                }
            }
        }
    }
    return stoi(answer);
}