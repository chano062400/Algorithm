#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;

bool cmp(pair<int,float> p1, pair<int,float> p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int num[501];
    memset(num, 0, sizeof(num));
    for(auto n : stages) num[n]++;
    map<int,float> percent;
    int size = stages.size();
    for(int i =1; i<= N; i++)
    {
        if(num[i] == 0 ) percent.insert({i,0});
        else percent.insert({i ,float(num[i]) / float(size)});   
        size -= num[i];
    }
    vector<pair<int,float>> v;
    for(auto p : percent) v.push_back({p.first, p.second});
    sort(v.begin(), v.end(), cmp);
    for(auto p : v) answer.push_back(p.first);
    return answer;
}