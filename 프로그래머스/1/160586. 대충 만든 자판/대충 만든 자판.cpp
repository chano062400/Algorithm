#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int> Map;
    
    for(int i=0; i<keymap.size(); i++)
    {
        for(int j=0; j<keymap[i].length(); j++)
        {
            string str = keymap[i];
            if(Map[str[j]] == 0) Map[str[j]] = j+1;
            
            if(Map[str[j]] > j+1) Map[str[j]] = j+1;
        }
    }
    
    bool CanWrite;
    for(int i=0; i<targets.size(); i++)
    {
        int sum= 0;
        CanWrite = true;
        for(int j=0; j<targets[i].length(); j++)
        {
            string str = targets[i];
            if(Map[str[j]] == 0)
            {
                CanWrite =false;
            }
            sum += Map[str[j]];
        }
        
        if(!CanWrite)
        {
            answer.push_back(-1);
        }
        else answer.push_back(sum);
    }
    return answer;
}