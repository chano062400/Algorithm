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

int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k, b;

    cin >> n >> k >> b;

    fill(arr, arr + 100001, 1);

    for (int i = 0; i < b; i++)
    {
        int num;
        cin >> num;
        arr[num]--;
    }

    for (int i = 2; i <= n; i++)
    {
        // n번까지 고장나지 않은 신호등 개수.
        arr[i] += arr[i - 1];
    }

    int m = 0;

    for (int i = k; i <= n; i++)
    {
        // k개 범위 내에 고장나지 않은 신호등 개수.
        m = max(m, arr[i] - arr[i - k]);
    }

    // 고쳐야 할 신호등 개수.
    cout << k - m;
}
