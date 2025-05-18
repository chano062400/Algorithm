#include <bits/stdc++.h>

using namespace std;

bool check(const vector<int>& stones, int k, int people) {
    int blank = 0;
    for (int s : stones) 
    {
        if (s - people < 0) 
        {
            if (++blank >= k) return false;   // k개 연속으로 0 이하 → 실패
        } 
        else 
        {
            blank = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int l = 1, r = *max_element(stones.begin(), stones.end()), answer = 0;
    while (l <= r) 
    {
        int mid = (l + r) / 2;
        if (check(stones, k, mid)) 
        {
            answer = mid;            
            l  = mid + 1;   // 건널 수 있으니 더 많은 사람을 시도
        } 
        else 
        {
            r  = mid - 1;   // 못 건너니 인원을 줄임
        }
    }
    return answer;
}