#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, start = 1, end = 1, sum = 1;
    while(start <= end)
    {
        if(sum < n) 
        {
            end++;
            sum += end;
        }
        if(sum == n) 
        {
            answer++;
            sum -= start;
            start++;
        }
        if(sum > n) 
        {
            sum -= start;
            start++;
        }
    }
    
    return answer;
}