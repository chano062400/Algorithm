#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
using namespace std;

int num, room;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> num >> room;
    vector<pair<string, int>> rank[333];

    for (int i = 0; i < num; i++) { 
        int level; string name;
        cin >> level >> name;   

        int flag = 0;

        for (int j = 0; j <= i; j++) {
            if (rank[j].size() < room && rank[j].size() > 0) {
                if (abs(rank[j][0].second - level) <= 10) { //처음 입장한 플레이어의 레벨 기준으로 -10 부터 +10 범위 안이라면
                    flag = 1;
                    rank[j].push_back(make_pair(name, level));
                    break;
                }
            }
        }
        if (flag == 0) {
            rank[i].push_back(make_pair(name, level));
        }
    }

    for (auto team : rank)
    {
        if (team.size() == room)  cout << "Started!" << '\n';
        else if(team.size() > 0 && team.size() < room) cout << "Waiting!" << '\n';
        sort(team.begin(), team.end());
        for (auto n : team) cout << n.second << " " << n.first << '\n';
    }
}
