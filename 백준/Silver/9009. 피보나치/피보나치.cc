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

int n;
int arr[45];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    arr[0] = 0;
    arr[1] = 1;

    for(int i=2; i<45; i++)
    {
        int num = arr[i - 1] + arr[i - 2];
        if (num > 1000000000) break;
        arr[i] = num;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> res;

        int num;
        cin >> num;

        for (int j = 44; j >= 0; j--)
        {
            if (arr[j] > num) continue;
           
            num -= arr[j];
            res.push_back(arr[j]);

            if (num == 0) break;
        }

        for (int k = res.size() - 1; k >= 0; k--)
        {
            if (k == 0)
            {
                cout << res[k] << '\n';
            }
            else
            {
                cout << res[k] << " ";
            }
        }
    }
}
