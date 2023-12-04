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

long long a, b, res;

void find47(long long num)
{
    if (num > b) return;

    if (num >= a && num <= b) res++;

    find47(num * 10 + 4);
    find47(num * 10 + 7);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> a >> b;

    find47(4);
    find47(7);

    cout << res;
}
