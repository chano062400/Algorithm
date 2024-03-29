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

struct Info
{
    int idx;
    int n;
    int m;
};

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int num = gcd(n, m);
    vector<Info> v;
    for (int i = 1; i <= gcd(n, m) / 2; i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            v.push_back({ i, n / i, m / i });
        }
    }

    v.push_back({ num, n / num, m / num });

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].idx << " " << v[i].n << " " << v[i].m << '\n';
    }

}
