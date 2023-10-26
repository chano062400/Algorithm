#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int mnx = 51, mny = 51 ,mxx =0, mxy =0;
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j=0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(mnx > i) mnx = i;
                if(mny > j) mny = j;
                if(i > mxx) mxx = i;
                if(j > mxy) mxy = j;
            }
        }
    }
    
    answer.push_back(mnx);
    answer.push_back(mny);
    answer.push_back(mxx+1);
    answer.push_back(mxy+1);
    
    return answer;
}