#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true; 
    int sum=0, temp = x;
    while(temp >= 1)
    {
        sum += temp % 10;
        temp /= 10;
    }
    x % sum == 0 ? answer = true : answer = false;
    return answer;
}