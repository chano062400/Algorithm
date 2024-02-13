#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

bool isprime(long long num)
{
    if(num < 2) return false; 
    
    for(int i=2; i<= sqrt(num); i++)
    {
        if(num % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
 
    set<int> prime;
   
    sort(numbers.begin(), numbers.end());
    
    do{
        string num = "";
        for(int i=0; i<numbers.length(); i++)
        {
            num += numbers[i];
            if(isprime(stoll(num))) prime.insert(stoll(num));
        }
        
        
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return prime.size();
}