#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
using namespace std;

class SegmentTree
{
public:

	vector<int> mintree;
	vector<int> maxtree;
	vector<int> arr;
	int n;

	SegmentTree(const vector<int>& input)
	{
		n = input.size();
		arr = input;
		int height = (int)ceil(log2(n));
		mintree.resize(1 << (height + 1));
		maxtree.resize(1 << (height + 1));
		build(0, 0, n - 1);
	}

	void build(int node, int start, int end)
	{
		// 맨 밑 자식노드
		if (start == end)
		{
			mintree[node] = arr[start];
			maxtree[node] = arr[start];
		}
		else
		{
			int mid = (start + end) / 2;
			// 왼쪽 자식 노드
			int leftnode = 2 * node + 1;
			// 오른쪽 자식 노드
			int rightnode = 2 * node + 2;

			build(leftnode, start, mid);
			build(rightnode, mid + 1, end);

			// 현재 노드의 값은 자식 노드의 결과의 합.
			mintree[node] = min(mintree[leftnode], mintree[rightnode]);
			maxtree[node] = max(maxtree[leftnode], maxtree[rightnode]);
		}
	}

	int minquery(int node, int start, int end, int left, int right)
	{
		// 범위가 다름.
		if (right < start || left > end) return INT_MAX;
		// [left, right]이 현재 구간을 완전히 포함.
		if (left <= start && end <= right) return mintree[node];

		int mid = (start + end) / 2;
		int leftmin = minquery(2 * node + 1, start, mid, left, right);
		int rightmin = minquery(2 * node + 2, mid + 1, end, left, right);

		return min(leftmin, rightmin);
	}

	int minquery(int left, int right)
	{
		return minquery(0, 0, n - 1, left, right);
	}
	
	int maxquery(int node, int start, int end, int left, int right)
	{
		// 범위가 다름.
		if (right < start || left > end) return INT_MIN;
		// [left, right]이 현재 구간을 완전히 포함.
		if (left <= start && end <= right) return maxtree[node];

		int mid = (start + end) / 2;
		int leftmax = maxquery(2 * node + 1, start, mid, left, right);
		int rightmax = maxquery(2 * node + 2, mid + 1, end, left, right);

		return max(leftmax, rightmax);
	}

	int maxquery(int left, int right)
	{
		return maxquery(0, 0, n - 1, left, right);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	SegmentTree SegTree(v);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << SegTree.minquery(a - 1, b - 1) << " " << SegTree.maxquery(a - 1, b - 1) << '\n';
	}

}

