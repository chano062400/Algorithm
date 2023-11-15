#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i=left; i<=right; i++)
    {
        int div = 2;
        for(int j = 1; j <= i / 2; j++)
        {
            if(i % j == 0) div++;
        }
        div % 2 ? answer += i : answer -= i;
    }
    return answer;
}