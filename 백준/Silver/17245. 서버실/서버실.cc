#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	int arr[1000][1000];

	cin >> N;

	int MAX = -1;
	
    double sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			MAX = max(MAX, arr[i][j]);
			sum += arr[i][j];
		}
	}

	int left = 0;
	int right = MAX;

	int answer = 21e8;

	while (left <= right) {
		long long cnt = 0;

		int middle = (left + right) / 2;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cnt += min(middle, arr[i][j]);
			}
		}

		if (cnt >= round(sum / 2)) {
			answer = min(middle, answer);

			right = middle - 1;
		}

		else {
			left = middle + 1;
		}

	}

	cout << answer;

	return 0;
}