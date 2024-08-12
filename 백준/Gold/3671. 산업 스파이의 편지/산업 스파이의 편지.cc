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

#define MAX 9999999
int n;
bool IsPrime[10000000], check[8];
string num;
set<int> Set;

void back(int idx, string str)
{
    if (idx > num.length()) return;

    if (idx > 0)
    {
        while (str[0] == '0')
        {
            str.erase(str.begin());
        }

        if (!str.empty() && IsPrime[stoi(str)] && Set.find(stoi(str)) == Set.end())
        {
            Set.insert(stoi(str));
        }
    }

    for (int i = 0; i < num.length(); i++)
    {
        if (!check[i])
        {
            check[i] = true;
            str += num[i];
            back(idx + 1, str);
            str.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    memset(IsPrime, 1, sizeof(IsPrime));

    IsPrime[0] = false;
    IsPrime[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++)
    {
        for (int j = i * 2; j <= MAX; j += i)
        {
            IsPrime[j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        memset(check, 0, sizeof(check));
   
        back(0, "");
        
        cout << Set.size() << '\n';
        Set.clear();
    }

}
