#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int size = commands.size();
    vector<int> sorted[size];
    for(int i=0; i<commands.size(); i++)
    {
        for(int j = commands[i][0]-1; j <= commands[i][1]-1; j++)
        {
            sorted[i].push_back(array[j]);
        }
        sort(sorted[i].begin(), sorted[i].end());
    }
    
    for(int i=0; i<size; i++)
    {
        answer.push_back(sorted[i][commands[i][2]-1]);
    }
    
    return answer;
}