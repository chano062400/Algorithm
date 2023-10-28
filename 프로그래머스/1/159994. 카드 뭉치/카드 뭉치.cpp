#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    bool Find = true;
    
    int i1=0, i2=0, ig=0;
    while(ig < goal.size())
    {
        if(goal[ig] == cards1[i1])
        {
            i1++;
            ig++;
        }
        else if(goal[ig] == cards2[i2])
        {
            i2++;
            ig++;
        }
        else if(goal[ig] != cards1[i1] && goal[ig] != cards2[i2])
        {
            Find =false;
            break;
        }
    }
    
    if(Find) answer = "Yes";
    else answer = "No";
    
    return answer;
}