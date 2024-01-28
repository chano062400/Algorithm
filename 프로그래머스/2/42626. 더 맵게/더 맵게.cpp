#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool canmake = true;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto num : scoville) pq.push(num);
    while(!pq.empty())
    {
        if(pq.top() >= K) break;
        if(pq.size() == 1 && pq.top() < K) 
        {
            canmake =false;
            break;
        }
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        int mix = n1 + (n2 * 2);
        pq.push(mix);
        answer++;
    }

    if(!canmake) answer = -1;
    return answer;
}