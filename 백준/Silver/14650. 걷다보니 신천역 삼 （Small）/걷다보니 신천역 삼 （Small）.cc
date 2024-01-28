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
using namespace std;

int n, cnt=0;
vector<int> v;

void f(int size, int num)
{
    if (size == n)
    {
        if (num % 3 == 0) cnt++;
        return;
    }

    if(num != 0) f(size + 1, num * 10);
    f(size + 1, num * 10 + 1);
    f(size + 1, num * 10 + 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    f(0,0);

    cout << cnt;

    return 0;
};

