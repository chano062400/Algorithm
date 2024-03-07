#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long factorial(int n) 
{
    if(n == 1) return 1;
    else return n * factorial(n-1);
}

vector<int> solution(int n, long long k) {
   vector<int> answer, v;
    long long idx, num;
    
    for(int i=1; i<=n; i++) v.push_back(i);
    
    while(n > 0)
    {
        num = factorial(n) / n;
        idx = (k - 1) / num;
        answer.push_back(v[idx]);
        v.erase(v.begin() + idx);
        n--;
        k %= num;
        if(k == 0) k = num;
    }
    
    
    return answer;
}