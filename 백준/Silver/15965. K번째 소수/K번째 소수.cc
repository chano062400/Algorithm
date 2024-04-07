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

#define MAX 10000001    
bool Prime[MAX] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n;
    cin >> n;

    for (int i = 2; i < sqrt(MAX); i++)
    {
        for (int j = i * 2; j <= MAX; j+=i)
        {
            Prime[j] = true;
        }
    }

    int cnt = 0;
    for (int i = 2; i <= MAX; i++)
    {
        if (!Prime[i]) cnt++;
        if (cnt == n)
        {
            cout << i;
            return 0;
        }
    }

}
