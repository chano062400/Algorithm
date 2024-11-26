#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0, n = name.length();

    // 알파벳 변경 최소 이동 계산
    for (char c : name) 
    {
        answer += min(c - 'A', 'Z' - c + 1);
    }

    if(answer == 0) return 0;
    
    // 좌우 이동 최소값 계산
    int min_moves = n - 1; // 기본적으로 오른쪽 끝까지 이동하는 경우
    for (int i = 0; i < n; i++) {
        if (name[i] == 'A') continue;
        int next = i + 1;
        while (next < n && name[next] == 'A') 
        {
            ++next;
        }
        
        // 1. 오른쪽으로 i를 먼저 탐색 후, 왼쪽으로 조작해서 next를 탐색 
        int case1 = i * 2 + (n - next);
        // 2. 왼쪽으로 next를 먼저 탐색 후, 오른쪽으로 조작해서 i를 탐색
		int case2 = i + (n - next) * 2;
        min_moves = min(min_moves, min(case1, case2));
    }

    answer += min_moves;
    return answer;
}