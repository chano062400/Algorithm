#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int mul;
    for(int i=0; i<arr1.size(); i++)
    {
        vector<int> v;
        for(int j=0; j<arr2[0].size(); j++)
        {
            mul = 0;
            for(int h=0; h<arr1[0].size(); h++)
            {
                mul += arr1[i][h] * arr2[h][j];
            }
            v.push_back(mul);
        }
        answer.push_back(v);
    }
    return answer;
    
}