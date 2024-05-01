#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int DP[1001][1001];
    int lenA, lenB, ans = 0;
    string A, B;
    string ret = "";

    cin >> A;
    cin >> B;
    lenA = A.size();
    lenB = B.size();

    for (int i = 0; i <= lenA; i++) {
        for (int j = 0; j <= lenB; j++) {
            DP[i][j] = 0;
        }
    }

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (A[i - 1] == B[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }


    int i = lenA;
    int j = lenB;
    while (i >= 1 && j >= 1) { //대각선으로 이동할 때만 ret에 추가
        if (DP[i][j] > DP[i - 1][j] && DP[i - 1][j] == DP[i][j - 1] && DP[i][j - 1] == DP[i - 1][j - 1]) {
            ret += B[j - 1];
            i--;
            j--;
        } else if (DP[i - 1][j] > DP[i][j - 1] && DP[i - 1][j] == DP[i][j]) {
            i--;
        } else if (DP[i - 1][j] < DP[i][j - 1] && DP[i][j - 1] == DP[i][j]) {
            j--;
        }
        else {
            j--;
        }
    }

    reverse(ret.begin(), ret.end());

    if (DP[lenA][lenB] != 0)
        cout << DP[lenA][lenB] << "\n" << ret;
    else
        cout << "0";

    return 0;
}