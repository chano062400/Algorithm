#include <string>
#include <vector>

using namespace std;
int cnt = 0;
vector<int> v;
bool visited[13];

void back(vector<int> number,int index, int count)
{
    if(count == 3)
    {
        int sum =0;
        for(auto n : v) sum += n;
        if(sum == 0) cnt++;
        return;
    }
    
    for(int i=index; i<number.size(); i++)
    {
        if(!visited[i])
        {
            int num = number[i];
            v.push_back(num);
            visited[i] = 1;
            back(number, i, count+1);
            visited[i] = 0;
            v.pop_back();
        }
    }
}

int solution(vector<int> number) {
    
    back(number, 0, 0);
    
    int answer = cnt;
    
    return answer;
}