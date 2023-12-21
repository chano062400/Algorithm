#include <string>
#include <vector>

using namespace std;

string to_binary(long long n)
{
    string s = ""; 
    while(n > 0)
    {
        if(n % 2 == 1) s = "1" + s;
        else s = "0" + s;
        n >>= 1;
    }
    
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero =0, binary = 0;
    while(s != "1")
    {
        string str = "";
        for(auto ss : s) if(ss != '0') str += ss; else if(ss == '0') zero++;
        int len = str.length();
        s = to_binary(len);
        binary++;
    }
    answer.push_back(binary);
    answer.push_back(zero);
    return answer;
}