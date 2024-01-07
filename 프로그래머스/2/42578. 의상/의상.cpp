#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> cloth;
    for(int i=0; i<clothes.size(); i++)
    {
        string str = clothes[i][1];
        if(cloth.count(str) == 0) cloth[str] = 1;
        else cloth[str]++;

    }
    
    for(auto c : cloth) answer *= c.second + 1;
    return answer - 1;
}