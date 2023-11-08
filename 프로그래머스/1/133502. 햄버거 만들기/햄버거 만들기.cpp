#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    string str = "";
    
    int index=0;
    
    for(int i=0; i<ingredient.size(); i++)
    {
        str += to_string(ingredient[i]);
        if(str.length() >= 4)
        {
            if(str.substr(str.length()-4,4) == "1231")
            {
                answer++;
                str.erase(str.length()-4,4);
            }
        }
    }
    
    return answer;
}