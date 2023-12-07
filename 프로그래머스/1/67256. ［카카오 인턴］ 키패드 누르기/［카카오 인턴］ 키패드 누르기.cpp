#include <string>
#include <vector>
#include <memory.h>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l= 10, r =12;
    for(auto n : numbers)
    {
        if(n == 1 || n == 4 || n == 7) 
        {
            answer += "L";
            l = n;
        }
        else if( n == 3 || n == 6 || n == 9)
        {
            answer += "R";
            r = n;
        }
        else
        {
            if(n == 0) n = 11;
            int ldist ,rdist;
            if(l == 1 || l == 4 || l == 7 || l == 10) ldist = (abs(l - (n-1)) / 3) + 1;
            else ldist = abs(l - n) / 3;
            
            if(r == 3 || r == 6 || r == 9 || r == 12) rdist = (abs(r - (n+1)) / 3) + 1;
            else rdist = abs(r - n) / 3;
            
            if(ldist < rdist) answer += "L", l = n;
            else if(ldist > rdist) answer += "R", r = n;
            else if(ldist == rdist)
            {
                if(hand == "right") 
                {
                    answer += "R";
                    r = n;
                }
                else
                {
                    answer += "L";
                    l = n;
                }
            }
        }
    }
    return answer;
}