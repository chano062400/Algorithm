#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
int answer = 0;
vector<int> v;
bool prime[3001], visited[3001];

void back(vector<int> nums, int index, int cnt)
{
    if(cnt == 3)
    {
        int sum = 0;
        for(auto n : v) sum += n;
        if(!prime[sum]) answer++;
        return;
    }
    
    for(int i=index; i < nums.size(); i++)
    {
        int num = nums[i];
        if(!visited[num])
        {
            visited[num] = 1;
            v.push_back(num);
            back(nums, i, cnt + 1);
            v.pop_back();
            visited[num] = 0;
        }
    }
}

int solution(vector<int> nums) {
    
    memset(prime, 0, sizeof(prime));
    memset(visited, 0 ,sizeof(visited));
    
    sort(nums.begin(), nums.end());
    
    prime[1] = 1;
    
    for(int i = 2; i<= 3000; i++)
    {
        for(int j = i * 2; j <= 3000; j += i)
        {
            prime[j] = 1;
        }
    }
    
    back(nums, 0, 0);
    
    return answer;
}