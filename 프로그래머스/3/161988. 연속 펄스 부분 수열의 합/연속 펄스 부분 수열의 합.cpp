#include <bits/stdc++.h>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int n = sequence.size();

    long long maxp = 0, maxm = 0;
    long long curp = 0, curm = 0;

    for (int i = 0; i < n; i++) 
    {
        long long sign = (i % 2 == 0) ? 1 : -1;
        long long num = sequence[i];

        curp = max(sign * num, curp + sign * num);
        maxp = max(maxp, curp);

        curm = max(-sign * num, curm - sign * num);
        maxm = max(maxm, curm);
    }

    answer = max(maxp, maxm);
    return answer;
}