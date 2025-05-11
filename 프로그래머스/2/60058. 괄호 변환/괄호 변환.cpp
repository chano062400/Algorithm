#include <bits/stdc++.h>
using namespace std;

void split(string str, string& u, string& v)
{
    int left = 0, right = 0;
    string temp = "";
    for(int i = 0; i < str.length(); i++)
    {
        str[i] == '(' ? ++left : ++right;

        if (left == right)
        {
            u = str.substr(0, i + 1);
            v = str.substr(i + 1);      
            break;
        }
    }
}

bool check(string u)
{
    stack<int> st;
    for(int i = 0; i < u.length(); i++)
    {
        char ch = u[i];
        if (ch == '(') st.push(ch);
        else
        {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

void reversestr(string& str)
{
    for(auto& ch : str)
    {
        if(ch == '(') ch = ')';
        else ch = '(';
    }
}

string recur(const string w)
{
    if (w.empty()) return "";
    
    string u, v;
    split(w, u ,v);
    
    if(check(u))
    {
        return u + recur(v);
    }
    
    string temp = "(" + recur(v) + ")";
    string mid = u.substr(1, u.length() - 2); 
    reversestr(mid);
    return temp + mid;
    
}

string solution(string p) {    
    if(p.empty() || check(p)) return p;
    
    string w = p, u = "", v = "";
    
    return recur(w);
}