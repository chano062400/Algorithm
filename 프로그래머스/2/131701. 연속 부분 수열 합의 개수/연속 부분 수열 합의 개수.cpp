#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> elements) {
    int len = 1, sum;
    vector<int> sums;
    while(len <= elements.size())
    {
        for(int i= 0; i < elements.size(); i++)
        {
            sum = 0;
            for(int j = 0; j < len; j++)
            {
                int idx = i + j;
                if(idx >= elements.size()) idx %= elements.size();
                sum += elements[idx];
            }
            sums.push_back(sum);
        }
        len++;
    }
    sort(sums.begin(),sums.end());
    sums.erase(unique(sums.begin(),sums.end()), sums.end());
    return sums.size();
}