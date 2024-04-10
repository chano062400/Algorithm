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

string ToBinary(int num)
{
    string str = "";
    while (num >= 1)
    {
        str += to_string(num % 2);
        num /= 2;
    }
    str.pop_back();
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    string res = ToBinary(n+1);
   
    for (int i = res.length() -1; i >= 0; i--)
    {
        if (res[i] == '1') res[i] = '7';
        else res[i] = '4';
    }

    reverse(res.begin(), res.end());
    cout << res;
}
