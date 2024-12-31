#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int size = A.size(), a = 0, b = 0;
    while(a < size && b < size)
    {
        if(A[a] < B[b]) 
        {
            answer++;
            a++;
            b++;
        }
        else
        {
            a++;
        }
    }
	return answer;
}