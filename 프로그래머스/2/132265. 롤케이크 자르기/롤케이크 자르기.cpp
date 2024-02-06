#include <string>
#include <vector>
#include <algorithm>
#include "memory.h"
using namespace std;

int solution(vector<int> topping) {
    int answer = 0, size = topping.size();
    vector<int> v1(size),v2(size);
    bool check[10001][2];
    memset(check,0,sizeof(check));
    
    v1[0] = 1;
    check[topping.front()][0] = true;
    
    v2[size-1] = 1;
    check[topping.back()][1] = true;
    
    for(int i=1; i<topping.size(); i++)
    {
        int num1 = topping[i];
        int num2 = topping[topping.size() - 1 - i];
        if(!check[num1][0]) 
        {
            check[num1][0] = true;
            v1[i] = v1[i-1] + 1;
        }
        else v1[i] = v1[i-1];
        
        if(!check[num2][1])
        {
            check[num2][1] = true;
            v2[size - 1 - i] = v2[size-i] + 1;
        }
        else v2[size-1-i] = v2[size-i];
    }
    
    for(int i=0; i<size-1; i++)
    {
        if(v1[i] == v2[i+1]) answer++;
    }
    
    return answer;
}