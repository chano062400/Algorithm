#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str = to_string(n);
    reverse(str.begin(), str.end());
    for(auto s : str) answer.push_back(s - '0');
    return answer;
}