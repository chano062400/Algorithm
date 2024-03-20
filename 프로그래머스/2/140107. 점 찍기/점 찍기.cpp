#include <bits/stdc++.h>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(long long i = 0; i <= d; i += k)
    {
        
        long long cnt = floor(sqrt((long long)d*d - i*i));
        answer += (cnt / k) + 1;
    }
    return answer;
}