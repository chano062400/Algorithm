#include <string>
#include <cmath>
using namespace std;

int num[4] ={0,};

int solution(string dartResult) {
    int answer = 0, idx = 1, option = 1;
    for(int i=0; i<dartResult.length(); i++)
    {
        string str="";
        if(dartResult[i] <= '9' && dartResult[i+1] <= '9') str = dartResult.substr(i,2);
        else str = dartResult[i];
        
        if(str[0] == '#' || str[0] == '*')
        {
            if(str[0] == '#')
            {
                num[idx] *= -1;
            }
            
            if(str[0] == '*')
            {
                num[idx] *= 2;
                num[idx - 1] *= 2;
            }
            idx++;
        }
        else if(str.length() == 1 && str[0] <= '9') num[idx] = str[0] - '0';
        else if(str.length() == 2) num[idx] = stoi(str) ,i++;
        else if(str[0] > '9' && str[0] <= 'Z') 
        {
            if(str[0] == 'D') num[idx] = pow(num[idx],2);
            else if(str[0] == 'T') num[idx] = pow(num[idx],3);
            if(dartResult[i+1] != '#' && dartResult[i+1] != '*') idx++;
        }
    }
    answer += num[1] + num[2] + num[3];
    return answer;
}