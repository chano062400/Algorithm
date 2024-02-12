#include <string>
#include <vector>

using namespace std;

int num[2] = {0,};
vector<vector<int>> arr2;

void quad(int x, int y, int len)
{
    int first = arr2[x][y];
    bool same = true;
 
    for(int i = x; i < x + len; i++)
    {
        for(int j = y; j < y + len; j++)
        {
            if(arr2[i][j] != first)
            {
                same = false;
                break;
            }
        }
        if(!same) break;
    }
    
    if(same) 
    {
        num[first]++;
        return;
    }
    else
    {
        quad(x, y, len / 2);
        quad(x + len / 2, y, len / 2);
        quad(x, y + len / 2, len / 2);
        quad(x + len / 2, y + len / 2, len / 2);
        return;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    arr2 = arr;
    quad(0,0, arr.size());
    answer.push_back(num[0]);
    answer.push_back(num[1]);
    
    return answer;
}