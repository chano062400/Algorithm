#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0, gcda = arrayA[0], gcdb = arrayB[0];
    
    for(int i=1; i<arrayA.size(); i++)
    {
       gcda = gcd(gcda, arrayA[i]);
    }
    
    for(int i=1; i<arrayB.size(); i++)
    {
        gcdb = gcd(gcdb, arrayB[i]);
    }

    for(int i=0; i<arrayA.size(); i++)
    {
        if(gcdb != 0 && arrayA[i] % gcdb == 0)
        {
            gcdb = 0;
        }
    }
    
    for(int i=0; i<arrayB.size(); i++)
    {
        if(gcda != 0 && arrayB[i] % gcda == 0)
        {
            gcda = 0;
        }
    }
    
    answer = max(gcda, gcdb);
    return answer;
}