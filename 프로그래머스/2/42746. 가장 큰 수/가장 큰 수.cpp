#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string str1, string str2)
{
    return str1 + str2 > str2 + str1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(auto num : numbers) v.push_back(to_string(num));
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto num : v) answer += num;
    if(answer[0] == '0') answer = "0";
    return answer;
}