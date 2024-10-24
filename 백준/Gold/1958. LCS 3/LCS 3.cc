#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory>
#include <cmath>

using namespace std;

int lcs[101][101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            for (int k = 1; k <= s3.length(); k++)
            {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                {
                    lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    lcs[i][j][k] = max(max(lcs[i - 1][j][k], lcs[i][j - 1][k]), lcs[i][j][k - 1]);
                }
            }
        }
    }
    cout << lcs[s1.length()][s2.length()][s3.length()];
}