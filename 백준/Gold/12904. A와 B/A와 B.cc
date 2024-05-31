#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

string a, b;
set<string> s;

bool bfs(string start)
{
    queue<string> q;
    q.push(start);
    s.insert(start);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        if (cur == a)
        {
            return true;
        }

        if (cur.length() - 1 >= a.length())
        {
            if(cur.back() == 'A')
            {
                string temp(cur.begin(), cur.end());
                temp.erase(temp.begin() + temp.length() - 1);
                q.push(temp);
            }
            else
            {
                string temp(cur.begin(), cur.end() - 1);
                reverse(temp.begin(), temp.end());
                q.push(temp);
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    
    cout << bfs(b);
}
    