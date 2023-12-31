#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second == p2.second) return p1.first< p2.first;
    return p1.second > p2.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0, sum =0;
    map<int,int> size;
    for(auto t : tangerine)
    {
        if(size.count(t) == 0) size.insert({t,1});
        else size[t]++;
    }
    vector<pair<int,int>> v(size.begin(), size.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto t : v)
    {
        if(sum < k) 
        {
            sum += t.second;
            answer++;
        }
        else break;
    }
    
    return answer;
}