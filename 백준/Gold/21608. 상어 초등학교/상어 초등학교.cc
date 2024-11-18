#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

struct info
{
    int student, s1, s2, s3, s4;
};

struct pos
{
    int x, y, likecnt, emptycnt;
};

bool emptycmp(const pos& p1, const pos& p2)
{
    return p1.emptycnt > p2.emptycnt;
}

bool likecmp(const pos& p1, const pos& p2)
{
    return p1.likecnt > p2.likecnt;
}

bool poscmp(const pos& p1, const pos& p2)
{
    if (p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}

vector<pos> getposinfo(const vector<vector<int>>& v, int s1, int s2, int s3, int s4)
{
    int maxcnt = 0;
    vector<pos> posinfo;
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 1; j < v.size(); j++)
        {
            int likecnt = 0, emptycnt = 0;
            if (v[i][j] != 0) continue;

            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 1 || nx >= v.size() || ny < 1 || ny >= v.size()) continue;
                if (v[nx][ny] == 0) emptycnt++;
                if (v[nx][ny] == s1 || v[nx][ny] == s2 || v[nx][ny] == s3 || v[nx][ny] == s4) likecnt++;
            }
            posinfo.push_back({ i,j,likecnt,emptycnt });
        }
    }
    return posinfo;
}

int getpoint(int cnt)
{
    if (cnt == 0) return 0;
    if (cnt == 1) return 1;
    if (cnt == 2) return 10;
    if (cnt == 3) return 100;
    if (cnt == 4) return 1000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, res = 0;
    cin >> n;
    vector<info> students;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n * n; i++)
    {
        int num, a, b, c, d;
        cin >> num >> a >> b >> c >> d;
        students.push_back({ num,a,b,c,d });
    }

    for(int i = 0 ; i < students.size(); i++)
    {
        int student = students[i].student;
        int s1 = students[i].s1;
        int s2 = students[i].s2;
        int s3 = students[i].s3;
        int s4 = students[i].s4;

        int x = 0, y = 0;
        vector<pos> posinfo = getposinfo(v, s1, s2, s3, s4);
        sort(posinfo.begin(), posinfo.end(), likecmp);
        int maxlike = posinfo[0].likecnt;
        vector<pos> maxlikepos;
        for (int i = 0; i < posinfo.size(); i++)
        {
            if (posinfo[i].likecnt == maxlike && v[posinfo[i].x][posinfo[i].y] == 0)
            {
                maxlikepos.push_back({ posinfo[i].x, posinfo[i].y, posinfo[i].likecnt, posinfo[i].emptycnt });
            }
        }

        if (maxlikepos.size() > 1)
        {
            sort(maxlikepos.begin(), maxlikepos.end(), emptycmp);
            int maxempty = maxlikepos[0].emptycnt;
            vector<pos> maxemptypos;
            for (int i = 0; i < maxlikepos.size(); i++)
            {
                if (maxlikepos[i].emptycnt == maxempty && v[maxlikepos[i].x][maxlikepos [i].y] == 0)
                {
                    maxemptypos.push_back({ maxlikepos[i].x, maxlikepos[i].y, maxlikepos[i].likecnt, maxlikepos[i].emptycnt });
                }
            }

            if (maxemptypos.size() > 1)
            {
                sort(maxemptypos.begin(), maxemptypos.end(), poscmp);
            }
            x = maxemptypos[0].x;
            y = maxemptypos[0].y;
        }
        else
        {
            x = posinfo[0].x;
            y = posinfo[0].y;
        }

        v[x][y] = student;
    }    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cur = v[i][j], cnt = 0;;
            for (int k = 0; k < students.size(); k++)
            {
                if (students[k].student == cur)
                {
                    for (int h = 0; h < 4; h++)
                    {
                        int nx = i + dx[h];
                        int ny = j + dy[h];
                        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                        if (v[nx][ny] == students[k].s1 || v[nx][ny] == students[k].s2 || v[nx][ny] == students[k].s3 || v[nx][ny] == students[k].s4) cnt++;
                    }
                    break;
                }
            }
            res += getpoint(cnt);
        }
    }

    cout << res;
}
