#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genreplayed;
    map<int, string, greater<int>> playedgenre;
    map<string , vector<pair<int,int>>> genresongs;
    
    for(int i = 0; i < plays.size(); i++)
    {
        string genre = genres[i];
        int play = plays[i];
        if(genreplayed.find(genre) == genreplayed.end())
        {
            genreplayed[genre] = play;
        }
        else
        {
            genreplayed[genre] += play;
        }
        
        genresongs[genre].push_back({play, i});
    }
        
    for(auto pair : genreplayed)
    {
        playedgenre[pair.second] = pair.first;
    }

    int rank = 0;
    for(auto pair : playedgenre)
    {
        // 해당 장르의 재생 횟수.
        int played = pair.first;
        // 장르 이름.
        string genre = pair.second;
                
        sort(genresongs[genre].begin(), genresongs[genre].end(), cmp);
        
        int cnt = 0;
        for(int i = 0; i < genresongs[genre].size(); i++)
        {
            if(cnt == 2) break;
            answer.push_back(genresongs[genre][i].second);
            ++cnt;
        }
    }
    
    return answer;
}