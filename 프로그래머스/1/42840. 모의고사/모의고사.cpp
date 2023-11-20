#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> numbers[3];
    
    numbers[0] = {1,2,3,4,5};
    numbers[1] = {2,1,2,3,2,4,2,5};
    numbers[2] = {3,3,1,1,2,2,4,4,5,5};
    int cnt[4];
    
    memset(cnt, 0, sizeof(cnt));
    
    int size = answers.size(), idx =0,idx1=0, idx2=0, idx3=0,mx=0;
    while(size--)
    {
        idx1 %= 5;
        idx2 %= 8;
        idx3 %= 10;
        if(answers[idx] == numbers[0][idx1]) cnt[1]++;
        if(answers[idx] == numbers[1][idx2]) cnt[2]++;
        if(answers[idx] == numbers[2][idx3]) cnt[3]++;
        idx++, idx1++, idx2++, idx3++;
        mx = max(max(cnt[1],cnt[2]),cnt[3]);
    }
    
    for(int i=1; i<=3; i++)
    {
        if(cnt[i] == mx) answer.push_back(i);
    }
    
    return answer;
}