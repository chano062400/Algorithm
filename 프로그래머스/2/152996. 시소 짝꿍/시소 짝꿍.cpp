#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    long long count[1001] = {0,};
    set<int> num;
    for(auto weight : weights) 
    {
        count[weight]++;
        num.insert(weight);
    }
    
    for(auto weight : num)
    {
        // 같은 몸무게 aC2 
        if(count[weight] >= 2)
        {
            answer += (count[weight] * (count[weight] -1)) / 2; 
        }
        
        // 2:3
        if(weight % 2 == 0 && weight * 3 / 2 <= 1000 && count[weight * 3 / 2] > 0)
        {
            answer += count[weight] * count[weight * 3 / 2 ];
        }
        
        // 2:4
        if(weight * 2 <= 1000 && count[weight * 2] > 0)
        {
            answer += count[weight] * count[weight * 2];
        }
        
        // 3:4
        if(weight % 3 == 0 && weight * 4 / 3 <= 1000 && count[weight * 4 / 3] > 0)
        {
            answer += count[weight] * count[weight * 4 / 3];
        }
    }
    return answer;
}