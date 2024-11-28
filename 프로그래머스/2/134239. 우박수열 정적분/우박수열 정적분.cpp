#include <bits/stdc++.h>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    int cnt = 0, prevy;
    vector<double> area;
    vector<double> answer;
    area.push_back(0.f);
    prevy = k;
    while(k > 1)
    {
        k = k % 2 ? 3 * k + 1 : k / 2;
        double triangle = abs(prevy - k) * 0.5f;
        double rectangle = min(prevy, k);
        area.push_back(area.back() + triangle + rectangle);
        prevy = k;
        ++cnt;
        cout << area.back() << '\n';
    }
    
    for(int i = 0; i < ranges.size(); i++)
    {
        int start = ranges[i][0];
        int end = ranges[i][1];
        end = end < 0 ? cnt + end : cnt - end;
        if(start > end)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(area[end] - area[start]);
        }
    }
    return answer;
}