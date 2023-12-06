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

int n, m, k, res=0;
int arr[51][51];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<string> v;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    cin >> k;

    map<string, int> pattern;
    for (auto s : v)
    {
        int zero = 0;
        for (auto n : s)
        {
            if (n == '0') zero++;
        }

        if (zero > k || zero % 2 != k % 2) continue;//k보다 0의 갯수가 많거나 n은 짝수개인데 k는 홀수라면 모두 키지 못함. 

        if (pattern.find(s) == pattern.end()) pattern.insert({ s,1 });
        else pattern[s]++;
    }

    for (auto p : pattern) res = max(res, p.second);

    cout << res;

}
