#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
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

int inning[51][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, res = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> inning[i][j];
		}
	}

	vector<int> player = { 2,3,4,5,6,7,8,9 };

	do
	{
		int order[10], idx = 0;
		// 4번 타자는 항상 1번 선수.
        order[4] = 1;
		for (int i = 1; i <= 9; i++)
		{
			if (i == 4) continue;
			order[i] = player[idx++];
		}

		int score = 0, startbatter = 1;

		for (int i = 1; i <= n; i++)
		{
			int out = 0;
			vector<bool> base(4, 0);

			while (out != 3)
			{
                // 이번 타석에 치는 선수
				int batter = order[startbatter];
                // 타자의 결과.
				int result = inning[i][batter];

				if (result == 0)
				{
					out++;
				}
                else if (result == 1) 
                {
                    // 1루타
                    // 3루에 있던 주자는 홈인 → 득점
                    if (base[3]) {
                        score++;
                        base[3] = false;
                    }
                    // 2루에 있던 주자는 3루로
                    if (base[2]) {
                        base[3] = true;
                        base[2] = false;
                    }
                    // 1루에 있던 주자는 2루로
                    if (base[1]) {
                        base[2] = true;
                        base[1] = false;
                    }
                    // 타자는 1루로
                    base[1] = true;
                }
                else if (result == 2) {
                    // 2루타
                    // 3루 주자 득점
                    if (base[3]) {
                        score++;
                        base[3] = false;
                    }
                    // 2루 주자 득점
                    if (base[2]) {
                        score++;
                        base[2] = false;
                    }
                    // 1루 주자는 3루로
                    if (base[1]) {
                        base[3] = true;
                        base[1] = false;
                    }
                    // 타자는 2루로
                    base[2] = true;
                }
                else if (result == 3) {
                    // 3루타
                    // 3루 주자 득점
                    if (base[3]) {
                        score++;
                        base[3] = false;
                    }
                    // 2루 주자 득점
                    if (base[2]) {
                        score++;
                        base[2] = false;
                    }
                    // 1루 주자 득점
                    if (base[1]) {
                        score++;
                        base[1] = false;
                    }
                    // 타자는 3루로
                    base[3] = true;
                }
                else {
                    // 4 = 홈런
                    // 모든 주자 + 타자 득점
                    for (int r = 1; r <= 3; r++) {
                        if (base[r]) {
                            score++;
                            base[r] = false;
                        }
                    }
                    score++; // 타자 본인 득점
                }

                // 다음 타자로 타순 넘어감.
                startbatter++;
                if (startbatter == 10) startbatter = 1;
			}
		}

        res = max(res, score);

	} while (next_permutation(player.begin(), player.end()));

    cout << res;
}


