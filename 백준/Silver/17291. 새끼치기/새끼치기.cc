#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = INT_MAX;

int N;
int dp[20];

int main()
{
    ios_base::sync_with_stdio(0); 
	cin.tie(0);

    cin >> N;

    dp[0] = dp[1] = 1; //초기값
    for(int i=2; i<=N; i++)
    {
        dp[i] = dp[i-1] * 2; //매번 분열
        if(i%2==0) dp[i] -= (dp[i-4] + dp[i-5]); //짝수 일때만 감소
    }

    cout << dp[N];

    return 0;
}