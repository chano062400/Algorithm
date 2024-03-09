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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    while (n--)
    {

        string str;
        cin >> str;

        sort(str.begin(), str.end());

        do 
        {
            for (auto ch : str)
            {
                cout << ch;
            }
            cout << '\n';
        }
        while (next_permutation(str.begin(), str.end()));
    }
}
