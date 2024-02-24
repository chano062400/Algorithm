#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> v1, pair<int,int> v2)
{
    return v1.first < v2.first;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> v;
    for(int i=0; i<book_time.size(); i++)
    {
        int start = stoi(book_time[i][0].substr(0,2)) * 100 + stoi(book_time[i][0].substr(3,2));
        int end = stoi(book_time[i][1].substr(0,2)) * 100 + stoi(book_time[i][1].substr(3,2)) + 10;
        if (end % 100 >= 60) end += 40; // 1560 = 16:00 이므로 +40 해줘서 -> 1600

        v.push_back({start, end});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    priority_queue<int, vector<int> ,greater<>> pq;
    pq.push(v[0].second);
    
    for(int i=1; i<v.size(); i++)
    {
        // 진행 중인 강의 중 가장 빨리 끝나는 강의가 다음 강의 시작시간보다 일찍 끝난다면
        if(pq.top() <= v[i].first)
        {
            //진행 중인 강의를 끝내고 현 강의실에서 강의 진행.
            pq.pop();
            pq.push(v[i].second);
        }
        // 다른 강의실에서 강의 진행
        else pq.push(v[i].second);
    }
    
    return pq.size();
}