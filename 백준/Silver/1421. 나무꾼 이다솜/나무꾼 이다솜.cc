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

int n, c, w;
long long res;
int arr[50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	
    cin >> n >> c >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + 50, greater<int>());
    
    for (int i = 1; i <= arr[0]; i++)
    {
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            int div = arr[j] / i ,rem = arr[j] % i;
            sum += max(0, rem != 0 ? div * i * w - (div * c) : div * i * w - ((div - 1) * c));
        }
        res = max(res, sum);
    }

    cout << res;
}