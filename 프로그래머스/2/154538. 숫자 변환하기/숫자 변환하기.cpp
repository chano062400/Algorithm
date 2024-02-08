#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    set<int> number;
    queue<pair<int,int>> q;
    q.push({x,0});
    while(!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == y) return cnt;
        
        if(number.find(cur + n) == number.end() && cur + n <= y) 
        {
            q.push({cur + n, cnt + 1});
            number.insert(cur + n);
        }
        if(number.find(cur * 2) == number.end() && cur * 2 <= y) 
        {
            q.push({cur * 2, cnt + 1});
            number.insert(cur * 2);
        }
        if(number.find(cur * 3) == number.end() && cur * 3 <= y)
        {
            q.push({cur * 3, cnt + 1});
            number.insert(cur * 3);
        }
    }
    return -1;
}