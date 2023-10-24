#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map <string, int> nameyearn;
    for(int i=0; i<name.size(); i++)
    {
        nameyearn[name[i]] = yearning[i];
    }
    
    int sum;
    for(int i=0; i< photo.size(); i++)
    {
        sum=0;
        for(int j=0; j<photo[i].size(); j++)
        {
            if(nameyearn[photo[i][j]] > 0)
            {
                sum += nameyearn[photo[i][j]];
            }
            else continue;
        }
        answer.push_back(sum);
    }
    
    return answer;
}