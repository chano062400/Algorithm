#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    int sum =0;
    for(int i=1; i<food.size(); i++)
    {
        if(food[i] % 2 == 1) food[i]--;
        sum += food[i];
    }
    
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