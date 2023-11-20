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
using namespace std;

int n, s, res=987654321, mul=1;
bool visited[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	
    cin >> n >> s;
    
    if (s == 0)
    {
        cout << 0;
        return 0;
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < s; i++)
    {
        int num; 
        cin >> num;
        visited[num] = 1;
    }

    
    for (int i = 1; i <= 1001; i++)
    {
        if (visited[i]) continue;
        for (int j = 1; j <= 1001; j++)
        {
            if (visited[j]) continue;
            for (int h = 1; h <= 1001; h++)
            {
                if(visited[h]) continue;
                mul = i * j * h;
                res = min(res, abs(n -mul));
                if (n + 1 < mul) break;
            }
        }
    }
   
    cout << res;
}