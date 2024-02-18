#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1, size = truck_weights.size(), index = 0, sum = 0, trucknum = 0;
    vector<int> v(size);
    queue<int> q;
    while(index < size)
    {
        if(trucknum < size)
        {
            int curtruck = truck_weights[trucknum];
            if(sum + curtruck <= weight)
            {
                sum += curtruck;
                q.push(curtruck); // 새로운 트럭 출발.
                trucknum++;
            }
        }
        
        for(int i=0; i<=trucknum-1; i++) v[i]++; // 1초에 1길이 만큼 지남.
        
        if(v[index] == bridge_length) 
        {
            sum -= q.front();
            q.pop(); // 현재 차가 다 건넜으면.
            index++; // 다음 차 감시.
        }
        
        answer++;
    }
    return answer;
}