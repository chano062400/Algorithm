#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 1000000, mxw=0, mxh=0;
    
    for(int i=0; i<sizes.size(); i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            mxw = max(mxw, sizes[i][0]);
            mxh = max(mxh, sizes[i][1]);
        }
        else
        {
            mxw = max(mxw, sizes[i][1]);
            mxh = max(mxh, sizes[i][0]);
        }
    }
    
    answer = mxw * mxh;
    
    return answer;
    
}