#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string str = to_string(n);
    for(auto s : str) answer += s - '0';
    return answer;
}