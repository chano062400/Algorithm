#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0; i<speeds.size(); i++)
    {
        int sub = 100 - progresses[i], day = sub / speeds[i], rem = sub % speeds[i];
        if(rem != 0) day += 1;
        q.push(day);
    }
    
    int cnt = 0, prev = q.front(), size =q.size();
    for(int i=0; i<size; i++)
    {
        if(prev >= q.front())
        {
            cnt++;
            q.pop();
        }
        else
        {
            answer.push_back(cnt);
            cnt = 1;
            prev = q.front();
            q.pop();
        }
        if(i == size - 1) answer.push_back(cnt);
    }
    
    return answer;
}