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

long long a, b;

long long sum(long long num)
{
    // 최소 2^0으로는 모두 나누어지므로 num을 초기값으로 설정.
    long long result = num;

    // 2^1, 2^2, 2^3 ... 2의 거듭제곱으로 나누어지는 수들의 갯수만큼 더해줌.
    // 2^0에서 이미 1을 더해줬으므로 2^1로 나누어지면 1을 더하고(i / 2)그 다음은 4 - 2해서 2를 더하고 ...
    for (long long i = 2; i <= num; i *= 2)
    {
        result += (num / i) * (i / 2);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;

    cout << sum(b) - sum(a - 1);
}
