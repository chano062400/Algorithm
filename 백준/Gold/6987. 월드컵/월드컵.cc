#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
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

vector<pair<int, int>> matches = { {0,1},{0,2},{0,3},{0,4},{0,5},{1,2},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{3,5},{4,5} };

int win[6], draw[6], lose[6];
bool res[4];

bool back(int idx)
{
    // 모든 경기가 끝난 경우
    if (idx == 15)
    {
        for (int i = 0; i < 6; i++)
        {
            if (win[i] != 0 || draw[i] != 0 || lose[i] != 0) return false;
        }
        return true;
    }

    int A = matches[idx].first;
    int B = matches[idx].second;

    // A가 이기고 B가 진 경우
    if (win[A] > 0 && lose[B] > 0)
    {
        win[A]--;
        lose[B]--;
        if (back(idx + 1))
        {
            return true;
        }
        win[A]++;
        lose[B]++;
    }

    // 비긴 경우
    if (draw[A] > 0 && draw[B] > 0)
    {
        draw[A]--;
        draw[B]--;
        if (back(idx + 1))
        {
            return true;
        }
        draw[A]++;
        draw[B]++;
    }
    
    // A가 지고 B가 이긴 경우
    if (lose[A] > 0 && win[B] > 0)
    {
        lose[A]--;
        win[B]--;
        if (back(idx + 1))
        {
            return true;
        }
        lose[A]++;
        win[B]++;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 4; i++)
    {
        bool flag = true;
        int sumw = 0, sumd = 0, suml = 0;
        for (int j = 0; j < 6; j++)
        {
            cin >> win[j] >> draw[j] >> lose[j];
            if (win[j] + draw[j] + lose[j] != 5)
            {
                flag = false;
            }
            sumw += win[j];
            sumd += draw[j];
            suml += lose[j];
        }

		if (sumw != suml || sumd % 2)
		{
			flag = false;
		}

		if (!flag)
		{
			res[i] = 0;
		}
		else
		{
			res[i] = back(0);
		}

    }

    cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3];
}