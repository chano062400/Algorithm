#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int q = s / n, r = s % n;
    if(q == 0) answer.push_back(-1);
    else
    {
        while(answer.size() < n - r)
        {
            answer.push_back(q);
        }
        while(r--) 
        {
            answer.push_back(q + 1);
        }
    }
    return answer;
}