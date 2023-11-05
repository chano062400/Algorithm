#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());
    
    for(int i=0; i<score.size(); i+=m)
    {
        int mn = 10;
        if(i+m > score.size()) break;
        for(int j=i; j<i+m; j++)
        {
            mn = min(mn, score[j]);
        }
        
        answer += mn * m;
    }
    
    
    return answer;
}