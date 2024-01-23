#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include "memory.h"
using namespace std;

bool isprime(string str)
{
    if(str.empty()) return false; 
    
    long long num = stoll(str);
    
    if(num < 2) return false;
    
    for(long long i = 2; i<= sqrt(num); i++)
    {
        if(num % i == 0) return false;    
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str ="";
    
    for(int i=n; i > 0;)
    {
        str = to_string(i % k) + str;
        i /= k;
    }
    
    stringstream ss(str);
    string temp;

    while(getline(ss,temp,'0')) if(isprime(temp)) answer++;

    return answer;
}