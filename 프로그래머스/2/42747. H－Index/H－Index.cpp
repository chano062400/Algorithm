#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int start= 0, end= 10000, mid;
    while(start <= end)
    {
        mid = (start + end) / 2;
        int idx = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
        int num = citations.size() - idx;
        
        if(num >= mid) 
        {
            answer = max(answer,mid);
            start = mid +1; 
        }
        else end = mid -1;  
    }
    return answer;
    
}