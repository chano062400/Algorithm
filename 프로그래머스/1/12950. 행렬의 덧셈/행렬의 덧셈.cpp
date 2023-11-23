#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int size = arr1.size();
    vector<vector<int>> answer(size);
    for(int i=0; i < arr1.size(); i++)
    {
        for(int j=0; j < arr1[0].size(); j++)
        {
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    return answer;
}