#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> v;
    
    for(int i=1; i<= number; i++)
    {
        int div;
        if(i==1) div =1;
        else div =2;
        
        for(int j =2; j<= i/2; j++)
        {
            if(i % j == 0) div++;    
        }
        
        v.push_back(div);
    }
    
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] > limit) v[i] = power;
        answer += v[i];
    }
    
    return answer;
}