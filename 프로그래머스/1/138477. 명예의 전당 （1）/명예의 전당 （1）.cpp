#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer,v;
    
    for(int i=0; i<score.size(); i++)
    {
        v.push_back(score[i]);
        sort(v.begin(), v.end());
        
        if(v.size() > k) v.erase(v.begin());
        answer.push_back(v.front());
    }
    
    return answer;
}