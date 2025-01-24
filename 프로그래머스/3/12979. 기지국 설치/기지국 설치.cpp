#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, start = 1 , end = n, range = w * 2 + 1, len = 0, num = 0;

    for(auto station : stations)
    {
        end = station - w - 1;
        len = max(0, end - start + 1);
        num = len % range == 0 ? len / range : len / range + 1;
        answer += num;
        start = station + w + 1;
    }
    
    if(start <= n)
    {
        len = n - start + 1;
        num = len % range == 0 ? len / range : len / range + 1;
        answer += num;
    }
    return answer;
}