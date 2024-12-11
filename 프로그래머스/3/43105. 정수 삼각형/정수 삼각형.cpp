#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int size = triangle.size();
    vector<int> dp(triangle[size - 1]);

    for (int i = size - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            // 현재 위치에서 바로 아래와 오른쪽 아래 중 최대값을 선택
            dp[j] = max(dp[j], dp[j + 1]) + triangle[i][j];
        }
    }
    return dp[0];
}