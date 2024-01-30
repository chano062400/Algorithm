#include <string>
#include <queue>
using namespace std;

int dx[4] ={1,-1,0,0};
int dy[4] ={0,0,1,-1};
bool visited[11][11][4]; //[11][11] 이동했을 때 위치 [4] 이동하기 전의 방향 
int solution(string dirs) {
    int answer = 0, cx = 5, cy =5, nx, ny;
    
    for(int i = 0; i < dirs.length(); i++)
    {
        char dir = dirs[i];
        int idx;
        if(dir == 'D') idx = 0;
        else if(dir == 'U') idx = 1;
        else if(dir == 'R') idx = 2;
        else if(dir == 'L') idx = 3;

        int nx = cx + dx[idx];
        int ny = cy + dy[idx];
        
        if(nx >= 0 && nx <= 10 && ny >= 0 && ny <= 10)
        {
            int reverseidx;
            if(idx == 0) reverseidx = 1;
            else if(idx == 1) reverseidx= 0;
            else if(idx == 2) reverseidx = 3;
            else if(idx == 3) reverseidx = 2;
            
            if(!visited[nx][ny][reverseidx] && !visited[cx][cy][idx])
            {   
                visited[cx][cy][idx] = true;
                answer++;
            }
            cx = nx;
            cy = ny;
        }

    }
    return answer;
}