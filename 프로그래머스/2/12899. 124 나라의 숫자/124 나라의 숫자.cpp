#include <string>
#include <vector>

using namespace std;

char num[] = {'4','1','2'};

string solution(int n) {
    string answer = "";
    char end = num[n % 3];
    while(n > 3)
    {
        if(n % 3 == 0) n -= 3;
        answer = num[(n / 3) % 3] + answer;
        n /= 3;
    }
    answer += end;
    return answer;
}