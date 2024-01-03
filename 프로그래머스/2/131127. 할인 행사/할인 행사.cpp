#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> canget;
    
    for(int i=0; i < discount.size(); i++)
    {
        for(int j = i; j < i+10 && j < discount.size(); j++)
        {
            string item = discount[j];
            if(canget.find(item) == canget.end()) canget.insert({item, 1});
            else canget[item]++;
        }
        
        bool reg = true;
        for(int h=0; h < want.size(); h++)
        {
            if(number[h] != canget[want[h]])
            {
                reg =false;
                break;
            }
        }
        
        if(reg) answer += 1;
        canget.clear();
    }
    
    return answer;
}