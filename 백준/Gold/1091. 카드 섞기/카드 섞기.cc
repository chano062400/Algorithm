#include <iostream>
#include <memory>
#include "memory.h"
using namespace std;
const int MAX = 50;

int n, input[MAX], arr[MAX], arr2[MAX], result[MAX], p[MAX], s[MAX];

bool check() {
	int p_num = 0;
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) p_num = 0;
		result[arr[i]] = p_num++;
	}

	for (int i = 0; i < n; i++) {
		if (result[i] != p[i]) return false;
	}
	return true;
}

void mix_card() {
	for (int i = 0; i < n; i++) {
		arr2[s[i]] = arr[i];
	}
	
	for (int i = 0; i < n; i++) arr[i] = arr2[i];
	memset(arr2, 0, sizeof(arr2));
}

bool check_input() {
	for (int i = 0; i < n; i++) {
		if (arr[i] != input[i]) return false;
	}
	return true;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		input[i] = i;
		arr[i] = i;
	}
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> s[i];

	int time = 0;
	bool flag = true;
	while (1) {
		if (check()) break;

		if (time > 0 && check_input()) {
			flag = false;
			break;
		}
		mix_card();
		time++;
	}
	
	if (!flag) cout << -1;
	else cout << time;
	return 0;
}