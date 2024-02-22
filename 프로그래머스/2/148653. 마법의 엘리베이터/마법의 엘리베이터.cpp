#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey >= 1)
    {
        int cur = storey % 10;
        int next = (storey / 10) % 10;
        
        if(cur > 5) // 현재 자릿수가 5 이상이면 올림.
        {
            answer += 10 - cur;
            storey += 10;
        }
        else if(cur == 5)
        {
            answer += 5;
            if(next >= 5) storey += 10; // 다음 자릿수가 5이상이면 올림, 미만이면 내림.       
        }
        else // 현재 자릿수가 5미만이면 내림
        {
            answer += cur;
        }
        
        storey /= 10;
    }
    return answer;
}