#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, index = 0;
    sort(people.begin(), people.end());
    while(index < people.size())
    {
        int mx = people.back(); 
        people.pop_back();
        if(mx + people[index] <= limit) { answer++; index++; } 
        else answer++;
    }
    
    return answer;
}