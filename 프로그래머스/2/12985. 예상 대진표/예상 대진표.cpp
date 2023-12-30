#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while(abs(a-b) != 1 || max(a,b) % 2 != 0)
    {
        if(a % 2) a += 1;
        if(b % 2) b += 1;
        a /= 2;
        b /= 2;
        answer++;
    } 
    return answer;
}