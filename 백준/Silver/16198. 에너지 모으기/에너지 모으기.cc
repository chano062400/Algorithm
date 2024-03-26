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

long long res = 0;
vector<int> v;

void back(long long sum)
{
    if (v.size() == 2)
    {
        res = max(res, sum);
        return;
    }

    int size = v.size();
    vector<int> temp(v.begin(), v.end());
    for (int i = 1; i < size - 1; i++)
    {
        long long mul = v[i - 1] * v[i + 1];
        v.erase(v.begin() + i);
        back(sum + mul);
        v = temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    back(0);
    
    cout << res;
}
