#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int d[10001] = {
        0,
    };
    int n, k;
    vector<int> input;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        input.push_back(in);
    }


    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= input[i]) {
                d[j] += d[j - input[i]];
            }
        }
    }

    cout << d[k] << "\n";
    
    return 0;
}