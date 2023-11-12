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


int arr[6], mx=0;
long long n, res =0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
        res += arr[i];
        mx = max(mx, arr[i]);
    }

    if (n == 1) cout << res - mx;
    else
    {
        res =0;
        arr[0] = min(arr[0], arr[5]); // a, f
        arr[1] = min(arr[1], arr[4]); // b, e
        arr[2] = min(arr[2], arr[3]); // c, d

        sort(arr, arr + 3);
        
        int sum1 = arr[0]; // 한면
        int sum2 = sum1 + arr[1]; // 두면
        int sum3 = sum2 + arr[2]; // 세면 

        res += sum3 * 4;
        res += sum2 * (4 * (n - 2) + 4 * (n - 1));
        res += sum1 * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));
        
        cout << res;
    }


}