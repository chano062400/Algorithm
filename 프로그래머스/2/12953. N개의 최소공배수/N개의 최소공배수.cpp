#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> arr) {
    int answer = 0;
    while(!arr.empty())
    {
        int a, b;
        if(answer == 0)
        {
            a = arr.back(); 
            arr.pop_back();
            b = arr.back();
            answer = a * b / gcd(a,b);
        }
        else 
        {
            a = answer;
            b = arr.back();
            arr.pop_back();
            
            answer = a * b / gcd(a,b);
        }
    }
    return answer;
}