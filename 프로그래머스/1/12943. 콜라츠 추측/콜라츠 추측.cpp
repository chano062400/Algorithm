#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long temp = num;
    if(num == 1) return answer;
    else
    {
        while(temp != 1)
        {
            temp % 2 == 0 ? temp /= 2 : temp = (temp * 3) + 1;
            if(answer <= 500) answer++;
            else 
            {   
                answer = -1;
                break;
            }
        }
    }
    return answer;
}