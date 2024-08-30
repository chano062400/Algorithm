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

int n, res;
vector<int> v, sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    // 모든 두 수의 합 넣기.(중복 포함)
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum.push_back(v[i] + v[j]);
        }
    }

    sort(sum.begin(), sum.end());

    // v
    for (int i = n - 1; i >= 0; i--)
    {
        // sum
        for (int j = sum.size() - 1; j >= 0; j--)
        {
            // v[i] - sum[j]가 v내에 있는지 이분탐색을 통해 확인.
            int start = 0, end = n-1, target = v[i] - sum[j];
            if (target < 0) continue;

            while (start <= end)
            {
                int mid = (start + end) / 2;

                if (v[mid] == target)
                {
                    cout << v[i];
                    return 0;
                }
                else if (v[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
   
        }
    }
}

