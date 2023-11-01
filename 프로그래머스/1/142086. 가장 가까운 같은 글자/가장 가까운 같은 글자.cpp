#include <string>
#include <vector>
#include "memory.h"
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    bool check[26];
    int index[26];
    
    memset(check, 0, sizeof(check));
    memset(index ,0, sizeof(index));
    
    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i] - 'a';
        if(!check[ch])
        {
            answer.push_back(-1);
            index[ch] = i;
            check[ch] =1;
        }
        else if(check[ch])
        {
            answer.push_back(i - index[ch]);
            index[ch] = i;
        }
    }
    
    
    return answer;
}