#include <string>
#include <vector>

using namespace std;

int dx[4] = {0,0,1,-1,};
int dy[4] = {1,-1,0,0};
  
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> loc;
    for(int i=0; i<park.size(); i++)
    {
        for(int j=0; j<park[i].size(); j++)
        {
            if(park[i][j] == 'S')
            {
                loc = {i,j};
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++)
    {
        int dir;
        if(routes[i][0] == 'E') dir=0;
        else if(routes[i][0] == 'W') dir =1;
        else if(routes[i][0] == 'S') dir =2;
        else if(routes[i][0] == 'N') dir =3;
        
        int move = routes[i][2] - '0';
        
        int nx = loc.first;
        int ny = loc.second;
        
        while(move--)
        {
            nx += dx[dir];
            ny += dy[dir];
                
            if((nx < 0 || ny < 0 || nx >= park.size() || ny >= park[0].size()) || park[nx][ny] == 'X') break;
            
        }
        
        if(move < 0) loc = {nx,ny};
    }
        answer = {loc.first , loc.second};

    return answer;
}