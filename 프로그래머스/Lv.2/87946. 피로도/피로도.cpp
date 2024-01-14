#include<bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> v;
    for(int i=0; i<dungeons.size(); i++) v.push_back(i);
    do{
        int health = k,cnt =0;
        for(int i=0; i<v.size(); i++)
        {
           int req = dungeons[v[i]][0], use = dungeons[v[i]][1];
           if(health >= req)
           {
               health -= use;
               cnt++;
           }
        }
        answer = max(cnt, answer);
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}