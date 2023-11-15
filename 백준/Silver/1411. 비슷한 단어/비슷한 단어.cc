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

int n, res=0;
vector<string> v;
int alpha[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	
    memset(alpha, -1, sizeof(alpha));
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }

    vector<string> v2[100];
    for (int i = 0; i < v.size(); i++)
    {
        int cnt = 0;
        string str = "";
        for (int j = 0; j < v[i].length(); j++)
        {
           
            if (alpha[v[i][j] - 'a'] == -1)
            {
                alpha[v[i][j] - 'a'] = cnt;
                str += to_string(cnt);
                cnt++;
            }
            else
            {
                str += to_string(alpha[v[i][j] - 'a']);
            }
        }
        memset(alpha, -1, sizeof(alpha));
        v2[i].push_back(str);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (v2[i] == v2[j]) res++;
        }
    }

    cout << res;
}