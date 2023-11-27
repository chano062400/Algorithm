#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp0(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}

bool cmp1(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}

bool cmp2(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

bool cmp3(vector<int> v1, vector<int> v2)
{
    return v1[3] < v2[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int pick;
    if(ext == "code") pick =0;
    if(ext == "date") pick =1;
    if(ext == "maximum") pick =2;
    if(ext == "remain") pick =3;
    
    for(int i=0; i<data.size(); i++)
    {
        if(data[i][pick] < val_ext) answer.push_back(data[i]);
    }
    
    if(sort_by == "code") sort(answer.begin(), answer.end(),cmp0);
    if(sort_by == "date") sort(answer.begin(), answer.end(),cmp1);
    if(sort_by == "maximum") sort(answer.begin(), answer.end(),cmp2);
    if(sort_by == "remain") sort(answer.begin(), answer.end(),cmp3);
    
    return answer;
}