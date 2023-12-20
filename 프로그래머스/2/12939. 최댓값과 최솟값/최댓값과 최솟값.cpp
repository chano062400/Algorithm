#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "", str;
    vector<int> v;
    stringstream ss(s);
    while(ss >> str) v.push_back(stoi(str));
    sort(v.begin(), v.end());
    answer += to_string(v.front());
    answer += " ";
    answer += to_string(v.back());
    return answer;
}