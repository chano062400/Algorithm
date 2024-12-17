#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
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

	vector<long long> tree;
	vector<long long> arr;

	SegmentTree(const vector<long long>& input)
	{
		arr = input;
		int n = arr.size();
		int height = ceil(log2(n));
		tree.resize(1 << (height + 1));
		build(0, 0, n - 1);
	}

	void build(int node, int start , int end)
	{
		if (start == end)
		{
			tree[node] = arr[start];
		}
		else
		{
			int mid = (start + end) / 2;
			int leftnode = 2 * node + 1;
			int rightnode = 2 * node + 2;

			build(leftnode, start, mid);
			build(rightnode, mid + 1, end);

			tree[node] = min(tree[leftnode], tree[rightnode]);
		}
	}

	long long query(int node, int start, int end, int left, int right)
	{
		if (right < start || end < left) return LLONG_MAX;
		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		long long leftresult = query(2 * node + 1, start, mid, left, right);
		long long rightresult = query(2 * node + 2, mid + 1, end, left, right);

		return min(leftresult, rightresult);
	}
};

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, l;
	cin >> n >> l;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	SegmentTree SegTree(v);

	for (int i = 0; i < n; i++)
	{
		int left = max(0, i - l + 1);
		int right = i;
		cout << SegTree.query(0, 0, n - 1, left, right) << " ";
	}
}

