#include <string>
#include <vector>
#include "memory.h"
#include <queue>
using namespace std;

bool IsKeepDistance(vector<string>& place)
{
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    
    for(int x=0; x<5; x++)
    {
        for(int y=0; y<5; y++)
        {
            if(place[x][y] == 'P')
            {
                for(int i=0; i<5; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
                    {
                        if(place[nx][ny] == 'X') continue;
                        if(place[nx][ny] == 'P' || place[nx][ny] == 'N') return false;
                        place[nx][ny] = 'N';
                    }
                }      
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto& place : places)
    {
        answer.push_back(IsKeepDistance(place));
    }
    
    return answer;
}