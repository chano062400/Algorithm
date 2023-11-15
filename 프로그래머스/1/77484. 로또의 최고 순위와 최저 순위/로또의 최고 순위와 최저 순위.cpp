#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same =0, zero =0;
    for(int i=0; i<6; i++)
    {
        if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) same++;
        else if(lottos[i] == 0) zero++;
    }
    int mx = same + zero, mn = same;
    answer = { min(6,1 + (6 - mx)), min(6,1 + (6 - mn))};
    return answer;
}