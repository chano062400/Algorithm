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

const int MAX = 987654321;
int n, gp, gf, gs, gv, res = MAX;
struct info
{
    int mp, mf, ms, mv, cost;
};
vector<info> v;
vector<int> resv;
bool visited[16];

bool check(info infos)
{
    return infos.mp >= gp && infos.mf >= gf && infos.ms >= gs && infos.mv >= gv;
}

void calcadd(int idx, info& infos)
{
    infos.mp += v[idx].mp;
    infos.mf += v[idx].mf;
    infos.ms += v[idx].ms;
    infos.mv += v[idx].mv;
    infos.cost += v[idx].cost;
}

void calcsub(int idx, info& infos)
{
    infos.mp -= v[idx].mp;
    infos.mf -= v[idx].mf;
    infos.ms -= v[idx].ms;
    infos.mv -= v[idx].mv;
    infos.cost -= v[idx].cost;
}

void dfs(int idx, info& infos, vector<int>& selected)
{
    if (check(infos))
    {
        if (res > infos.cost)
        {
            res = min(res, infos.cost);
            resv = selected;
        }
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            calcadd(i, infos);
            selected.push_back(i);
            dfs(i, infos, selected);
            visited[i] = false;
            calcsub(i, infos);
            selected.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    cin >> gp >> gf >> gs >> gv;

    for (int i = 0; i < n; i++)
    {
        int mp, mf, ms, mv, cost;
        cin >> mp >> mf >> ms >> mv >> cost;
        v.push_back({ mp, mf, ms, mv, cost });
    }
    info temp = { 0,0,0,0,0 };
    vector<int> selected;
    dfs(0, temp, selected);
    
    if (res == MAX)
    {
        cout << -1;
    }
    else
    {
        cout << res << '\n';

        for (auto idx : resv) cout << idx + 1 << " ";
    }
    return 0;
}