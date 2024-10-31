#include <bits/stdc++.h>
using namespace std;

vector<int> num(101,0);
bool check[101];

void choose(int cur, int group, vector<int>& cards)
{
    if(check[cur]) return;
    
    check[cur] = true;
    num[group]++;
    choose(cards[cur] - 1, group, cards);
}

int solution(vector<int> cards) {
    int answer = 1;
    for(int i = 0; i < cards.size(); i++)
    {
        if(!check[i])
        {
            choose(i, i, cards);
        }
    }
    
    sort(num.begin(), num.end(), greater<int>());
    
    return num[0] * num[1];
}