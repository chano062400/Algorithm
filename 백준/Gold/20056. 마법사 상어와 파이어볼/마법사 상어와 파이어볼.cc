 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

struct Fireball {
    int r, c;  // 위치
    int m;     // 질량
    int s;     // 속력
    int d;     // 방향
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<Fireball> fireballs(M);

    // 입력 받기
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fireballs[i] = { r - 1, c - 1, m, s, d };
    }

    int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    for (int i = 0; i < K; i++) {
        unordered_map<long long, vector<Fireball>> newMap;
        newMap.reserve(fireballs.size());

        for (auto& fb : fireballs) 
        {
            int nr = (fb.r + dr[fb.d] * fb.s) % N;
            int nc = (fb.c + dc[fb.d] * fb.s) % N;

            if (nr < 0) nr += N;
            if (nc < 0) nc += N;

            // 해쉬로 관리
            long long key = (long long)nr * 100000 + (long long)nc;
            newMap[key].push_back({ nr, nc, fb.m, fb.s, fb.d });
        }

        vector<Fireball> nextFireballs;
        nextFireballs.reserve(M);

        for (auto& item : newMap) 
        {
            auto& fbs = item.second;
            if (fbs.size() == 1) 
            {
                nextFireballs.push_back(fbs[0]);
            }
            // 2개 이상
            else 
            {
                int sumM = 0, sumS = 0;
                bool allEven = true, allOdd = true;
                for (auto& f : fbs) 
                {
                    sumM += f.m;
                    sumS += f.s;
                    if (f.d % 2 == 0) 
                    {
                        allOdd = false;
                    }
                    else 
                    {
                        allEven = false;
                    }
                }
                int count = fbs.size();
                int newM = sumM / 5;
                int newS = sumS / count;

                if (newM > 0)
                {
                    vector<int> ndir;
                    if (allEven || allOdd) 
                    {
                        ndir = { 0, 2, 4, 6 };
                    }
                    else 
                    {
                        ndir = { 1, 3, 5, 7 };
                    }

                    // 새로운 파이어볼 4개 생성
                    for (int d : ndir) 
                    {
                        nextFireballs.push_back({ fbs[0].r, fbs[0].c, newM, newS, d });
                    }
                }
            }
        }

        fireballs = move(nextFireballs);
    }

    long long res = 0;
    for (auto& fb : fireballs) 
    {
        res += fb.m;
    }

    cout << res << "\n";
    return 0;
}