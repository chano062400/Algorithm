#include <string>
#include <vector>
#include <map>
using namespace std;

string alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q","R","S","T","U","V","W","X","Y","Z"};

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> alpha;
    for(int i = 0; i< 26; i++)
    {
        alpha.insert({alphabet[i],i+1});
    }
    
    int last = 27;
    string str= "";
    for(int i=0; i<msg.length(); i++)
    {
        str += msg[i];
        if(alpha.count(str) == 0)
        {
            alpha.insert({str,last++});
            str = str.substr(0, str.length() -1);
            answer.push_back(alpha[str]);
            str = "";
            i--;
        }
    }
    answer.push_back(alpha[str]);
    
    return answer;
}