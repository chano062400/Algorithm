#include <bits/stdc++.h>
using namespace std;

void pushmelody(const string& sheet, vector<string>& melodies)
{
    for(int i = 0; i < sheet.length(); i++)
    {
        string str;
        if(sheet[i] != '#' && sheet[i+1] == '#')
        {   
            str = sheet.substr(i,2);
            ++i;
        }
        else
        {
            str = sheet[i];
        }
        melodies.push_back(str);
    }
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int longestplayed = 0;

    vector<string> mv;
    pushmelody(m, mv);
    
    for(int i = 0; i < musicinfos.size(); i++)
    {
        istringstream iss(musicinfos[i]);
        string str;
        vector<string> temp;
        while(getline(iss, str, ','))
        {
            temp.push_back(str);
        }
        int startminutes = stoi(temp[0].substr(0,2)) * 60 + stoi(temp[0].substr(3,2));
        int endminutes = stoi(temp[1].substr(0,2)) * 60 + stoi(temp[1].substr(3,2));
        int minutes = endminutes - startminutes;
        int cnt = minutes;
        
        vector<string> tempmelody;
        pushmelody(temp[3], tempmelody);
        
        int idx = 0, midx = 0, size = tempmelody.size();
        while(midx < mv.size() && cnt--)
        {
            if(mv[midx] == tempmelody[idx % size])
            {
                midx++;
            }
            else
            {
                if(mv[0] == tempmelody[idx % size]) midx = 1;
                else midx = 0;
            }
            idx++;
        }
        
        if(midx == mv.size())
        {
            if(minutes > longestplayed)
            {
                answer = temp[2];
                longestplayed = minutes;
            }
        }    
    }
    
    return answer;
}