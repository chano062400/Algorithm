#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> courses[11];
bool check[11];
map<string,int> MAP;
int countorder[11];

void back(int idx, int cnt, int len, string order, string str)
{
    if(cnt == len)
    {
        string temp = str;
        sort(temp.begin(), temp.end());
        courses[len].push_back(temp);
        MAP[temp]++;
        countorder[len] = max(countorder[len], MAP[temp]);
        return;
    }
    
    for(int i = idx; i < order.length(); i++)
    {
        if(!check[i])
        {
            check[i] = true;
            str += order[i];
            back(i, cnt + 1, len, order, str);
            str.pop_back();
            check[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i = 0; i < orders.size(); i++)
    {
        for(int j = 0; j < course.size(); j++)
        {
            back(0, 0, course[j], orders[i], "");
        }
    }
    
    for(int i = 0; i < course.size(); i++)
    {
        int len = course[i];
        sort(courses[len].begin(), courses[len].end());
        courses[len].erase(unique(courses[len].begin(), courses[len].end()), courses[len].end());
        for(int j = 0; j < courses[len].size(); j++)
        {
           if(MAP[courses[len][j]] == countorder[len] && countorder[len] > 1)
           {
               answer.push_back(courses[len][j]);
           }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}