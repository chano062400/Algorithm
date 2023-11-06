#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";

    string str = "";
    int index =1, cnt =0;
    while(index < food.size())
    {
        if(cnt != food[index] / 2)
        {
            str += to_string(index);
            cnt++;
        }
        else
        {
            index++;
            cnt = 0;
        }
    }
  
    answer += str + "0";
    reverse(str.begin(), str.end());
    answer += str;
    
    return answer;
}