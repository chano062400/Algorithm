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

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        
        vector<int> v;

        for (int i = 0; i < str.size(); i++)
        {
            v.push_back(str[i] - '0');
        }

        if (!next_permutation(v.begin(), v.end()))
        {
            cout << "BIGGEST" << '\n';
        }
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
  