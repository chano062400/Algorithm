#include <bits/stdc++.h>
using namespace std;

string lower(string s)
{
    string str ="";
    for(auto ch : s) 
    {
        str += tolower(ch);
    }
    return str;
}

int solution(string str1, string str2) {
    int answer = 0;
    double div;
    map<string, int> ch, ch1, ch2;
    vector<string> v;
    
    str1 = lower(str1);
    str2 = lower(str2);
    
    for(int i = 0; i<str1.length() -1; i++)
    {
        if(!isalpha(str1[i]) || !isalpha(str1[i+1])) continue;
        
        string str = str1.substr(i,2);
        
        if(ch1.count(str) == 0) ch1[str] = 1;
        else ch1[str]++;
        
        if(ch.count(str) == 0 ) ch[str] = 1;
    }
    
    for(int i = 0; i<str2.length() -1; i++)
    {
        if(!isalpha(str2[i]) || !isalpha(str2[i+1])) continue;
        
        string str = str2.substr(i,2);
        
        if(ch.count(str) == 0) ch2[str] = 1;
        else ch2[str]++;
        
        if(ch.count(str) == 0 ) ch[str] = 1;
    }
    int samecnt = 0, sumcnt = 0;
    for(auto s : ch) 
    {
        samecnt += min(ch1[s.first], ch2[s.first]);
        sumcnt += max(ch1[s.first], ch2[s.first]);
    }
    
    if(ch.size() == 0) div = 1;
    else div = double(samecnt) / double(sumcnt);
    return div * 65536;
}