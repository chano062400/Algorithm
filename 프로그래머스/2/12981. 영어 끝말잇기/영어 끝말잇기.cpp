#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> wordmap;
    string prevword =words[0];
    wordmap.insert({prevword,1});
    int order = 1, cnt = 1;
    for(int i = 1; i < words.size(); i++)
    {
        string str = words[i];
        order++;
        if(order > n)
        {
            order %= n;
            cnt++;
        }
        if(prevword.back() == str.front()) // 끝말잇기 O
        {
            if(wordmap.count(str) == 0) // 처음 말한거
            {
                wordmap[str] = 1;
                prevword = str;
            }
            else // 이미 말했던거
            {
                answer.push_back(order);
                answer.push_back(cnt);
                break;
            }
        }
        else // 끝말잇기 X
        {
            answer.push_back(order);
            answer.push_back(cnt);
            break;
        }
    }

    if(answer.empty()) { answer.push_back(0); answer.push_back(0); } // 아무도 안걸리고 끝났으면
    
    return answer;
}