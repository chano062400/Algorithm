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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    long long n, size=0;
    long long cnt = 0;
    cin >> n;
    long long temp = n;

    while (temp > 1)
    {
        if (temp < 10) break;
        temp /= 10;
        size++;
    }

    for (int i = 0; i < size; i++)
    {
        cnt += ((pow(10, i + 1) - 1) - pow(10, i) + 1) * (i+1);
    }

    cnt += (n - pow(10, size) + 1) * (size+1);
    cnt %= 1234567;
    cout << cnt;
  
}