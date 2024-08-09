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

bool result[26][26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int c1 = str[0] - 'a';
        cin >> str;
        cin >> str;
        int c2 = str[0] - 'a';

        result[c1][c2] = true;
    }

    for (int k = 0; k < 26; k++)
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (i == j) continue;

                if (result[i][k] && result[k][j])
                    result[i][j] = true;
            }
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        int c1 = str[0] - 'a';
        cin >> str;
        cin >> str;
        int c2 = str[0] - 'a';

        result[c1][c2] ? cout << "T" << '\n' : cout << "F" << '\n';
    }
}
