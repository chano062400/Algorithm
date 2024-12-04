#include <bits/stdc++.h>

using namespace std;

struct info {
    long long x, y;
    bool flag = true;
};

info getpoint(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2) {
    info temp;
    long long denominator = (x1 * y2) - (x2 * y1);
    if (denominator == 0) {
        temp.flag = false;
        return temp;
    }
    temp.x = ((y1 * z2) - (y2 * z1)) / denominator;
    temp.y = ((z1 * x2) - (z2 * x1)) / denominator;
    if (((y1 * z2) - (y2 * z1)) % denominator != 0 || ((z1 * x2) - (z2 * x1)) % denominator != 0) {
        temp.flag = false;
    }
    return temp;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long, long long>> v;
    long long minx = LLONG_MAX, maxx = LLONG_MIN, miny = LLONG_MAX, maxy = LLONG_MIN;

    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) 
        {
            info temp = getpoint(line[i][0], line[i][1], line[i][2],
                                 line[j][0], line[j][1], line[j][2]);
            if (temp.flag) 
            {
                minx = min(minx, temp.x);
                maxx = max(maxx, temp.x);
                miny = min(miny, temp.y);
                maxy = max(maxy, temp.y);
                v.push_back({temp.x, temp.y});
            }
        }
    }

    long long width = maxx - minx + 1;
    long long height = maxy - miny + 1;
    vector<string> MAP(height, string(width, '.'));

    for (auto pair : v) {
        long long x = pair.first - minx;
        long long y = maxy - pair.second;
        MAP[y][x] = '*';
    }

    return MAP;
}
