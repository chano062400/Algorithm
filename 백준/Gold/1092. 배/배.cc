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
using namespace std;

int n, m, res = 0;
vector<int> crane, box;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        crane.push_back(weight);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int weight;
        cin >> weight;
        box.push_back(weight);
    }

    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    if (*max_element(crane.begin(), crane.end()) < *max_element(box.begin(), box.end())) cout << -1;
    else
    {
        while (!box.empty())
        {
            for (int i = 0; i < crane.size(); i++)
            {
                for (int j = 0; j < box.size(); j++)
                {
                    if (crane[i] >= box[j])
                    {
                        box.erase(box.begin() + j);
                        break;
                    }
                }
            }
            res++;
        }

        cout << res;
    }
}
