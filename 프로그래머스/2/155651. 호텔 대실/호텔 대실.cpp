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
    int time[2410] = {0,};
    for(int i=0; i<book_time.size(); i++)
    {
        int start = stoi(book_time[i][0].substr(0,2)) * 100 + stoi(book_time[i][0].substr(3,2));
        int end = stoi(book_time[i][1].substr(0,2)) * 100 + stoi(book_time[i][1].substr(3,2)) + 10;
        if (end % 100 >= 60) end += 40; // 1560 = 16:00 이므로 +40 해줘서 -> 1600

        for(int j=start; j<end; j++)
        {
            time[j]++;
        }
    }
    
    for(int i=0; i<=2409; i++)
    {
        answer = max(answer, time[i]);
    }
    
    return answer;
}