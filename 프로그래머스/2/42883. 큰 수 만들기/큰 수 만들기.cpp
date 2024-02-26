#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = -1; // 인덱스 0부터 시작
    for(int i=0; i<number.size()-k; i++)
    {
        char maxch = ' ';
        // 선택한 숫자 다음 자리부터 시작. 1924 -> 9 선택했으면 다음엔 2부터 탐색.
        for(int j= idx+1; j<=i+k; j++)
        {
            if(number[j] > maxch)
            {
                maxch = number[j];
                idx = j;
            }
        }
        answer += maxch;
    }
    
    return answer;
}