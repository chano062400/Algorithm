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
using namespace std;

int alpha[26];

void back(string anagram, string str)
{
    if (anagram.length() == str.length())
    {
        cout << anagram << '\n';
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > 0)
        {
            alpha[i]--;
            anagram += i + 'a';
            back(anagram, str);
            anagram.pop_back();
            alpha[i]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    while (n--)
    {
        memset(alpha, 0, sizeof(alpha));

        string str;
        cin >> str;

        sort(str.begin(), str.end());

        for (auto ch : str)
        {
            alpha[ch - 'a']++;
        }

        back("",str);
    }
}
