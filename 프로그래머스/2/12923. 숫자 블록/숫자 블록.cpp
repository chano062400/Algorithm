#include <bits/stdc++.h>

using namespace std;

int getnum(int num)
{
    if(num < 2) return 0;
    int max = 1;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            max = i;
            if(num / i <= 10000000) return num / i;
        }
    }
    return max;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i = begin; i <= end; i++)
    {
        answer.push_back(getnum(i));
    }
    return answer;
}