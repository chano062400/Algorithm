#include <bits/stdc++.h>

using namespace std;

int getfastestcursor(int size, int prev, int cur)
{
    int left, right;
    if(prev < cur)
    {    
        right = cur - prev;
        left = prev + 1 + (size - cur);
    }
    else
    {
        right = size - prev + cur + 1;
        left = prev - cur;
    }
    return min(right, left);
}

int getfastestalpha(char target)
{
    int up = target - 'A';
    int down = 1 + 'Z' - target;
    return min(up, down);
}

int solution(string name) {
    int answer = 987654321;
    vector<int> v;
    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] == 'A') continue;
        v.push_back(i);
    }
    
    do
    {
        int temp = 0, prev = 0;
        for(int i = 0; i < v.size(); i++)
        {
            temp += getfastestcursor(name.length() - 1, prev, v[i]);
            prev = v[i];
            temp += getfastestalpha(name[v[i]]);
        }
        answer = min(answer, temp);
    }while(next_permutation(v.begin(),v.end()));

    return answer;
}