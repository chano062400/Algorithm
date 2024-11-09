#include <bits/stdc++.h>

using namespace std;

int ft[3][3] =
{
    {1,1,1},
    {5,1,1},
    {25,5,1}
};

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 750;
    vector<int> order;
    for(int i = 0; i < picks.size(); i++)
    {
        for(int j = 0; j < picks[i]; j++)
        {
            order.push_back(i);
        }
    }
        
    do
    {
        int sum = 0, idx = 0;
        bool flag = false;
        for(int i = 0; i < order.size(); i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if (idx == minerals.size()) 
                {
                    flag = true;
                    break;
                }
                string mineral = minerals[idx++];
    
                int ftidx;
                if (mineral == "diamond") ftidx = 0;
                else if (mineral == "iron") ftidx = 1;
                else ftidx = 2;
                
                sum += ft[order[i]][ftidx];
            }
            if(flag) break;
        }
        answer = min(answer, sum);
    }
    while(next_permutation(order.begin(), order.end()));
    
    
    return answer;
}