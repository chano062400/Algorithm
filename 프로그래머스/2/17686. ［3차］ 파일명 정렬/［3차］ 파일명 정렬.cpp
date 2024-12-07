#include <bits/stdc++.h>
using namespace std;

struct info
{
    string head, tail, str;  
    int number, idx;
};

bool cmp(const info& info1, const info& info2)
{
    if(info1.head == info2.head) 
    {
        if(info1.number == info2.number) return info1.idx < info2.idx;
        return info1.number < info2.number;
    }
    return info1.head < info2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<info> v;
    for (int idx = 0; idx < files.size(); idx++) 
    {
        string file = files[idx];
        string head, number, tail;
        int i = 0;

        // HEAD 추출
        while (i < file.length() && !isdigit(file[i])) 
        {
            head += file[i];
            i++;
        }

        // NUMBER 추출
        int number_start = i;
        while (i < file.length() && isdigit(file[i])) 
        {
            number += file[i];
            i++;
        }

        // TAIL 추출
        tail = file.substr(i);

        // 앞자리 0 제거
        if (!number.empty() && number != "0") 
        {
            while (number.size() > 1 && number.front() == '0') number.erase(number.begin());
        }

        // HEAD를 소문자로 변환
        string lower_head = head;
        for (char& ch : lower_head) ch = tolower(ch);

        v.push_back({lower_head, tail, file, stoi(number), idx});
    }
    
    sort(v.begin(), v.end(), cmp);
    for(auto infos : v)
    {
        answer.push_back(infos.str);
    }
    
    return answer;
}