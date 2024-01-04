#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    vector<long long> v;
    bool Find =false;
    long long startx = left / n + 1, starty = left % n + 1;
    for(long long i= startx; i<=n; i++)
    {
        for(long long j= starty; j<=n; j++)
        {
            v.push_back(max(i,j));
            if(v.size() > right - left)
            {
                Find = 1;
                break;
            }
        }
        starty = 1;
        if(Find) break;
    }
    for(long long i = 0; i<= right - left; i++)
    {
        answer.push_back(v[i]);
    }
    return answer;
}