#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2, int col)
{
    if(v1[col - 1] == v2[col - 1]) return v1[0] > v2[0];
    return v1[col - 1] < v2[col - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sort(data.begin(), data.end(),
         [col] (vector<int> v1, vector<int> v2) 
         {
             return cmp(v1,v2,col);
         }
    );
    
    for(int i = row_begin - 1; i <= row_end - 1; i++)
    {
        int sum = 0;
        for(int j = 0; j < data[i].size(); j++)
        {
            sum += data[i][j] % (i + 1);
        }
        answer ^= sum;
    }

    return answer;
}