#include <string>
#include <vector>

using namespace std;


int to_binary(int n)
{
    string s ="";
    int one = 0;
    while(n > 1)
    {
        if(n % 2 == 1) { s = "1" + s; one++; }
        else s = "0" + s;
        n >>= 1;
    }
    
    return one;
}

int solution(int n) {
    int answer = 0;
    int n1 = to_binary(n);
    for(int i = n+1; i <= 1000000; i++)
    {
        if(to_binary(i) == n1) 
        { 
            answer = i; 
            break; 
        }
    }
    return answer;
}