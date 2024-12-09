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
	
	vector<long long> tree;
	vector<long long> arr;
	int n;

	SegmentTree(const vector<long long>& input)
	{
		n = input.size();
		arr = input;
		int height = ceil(log2(n));
		tree.resize((1 << (height + 1)));
		build(0, 0, n - 1);
	}

	void build(int node, int start, int end)
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

			tree[node] = tree[leftnode] + tree[rightnode];
		}
	}

	long long query(int node, int start, int end, int left, int right)
	{
		if (right < start || left > end) return 0;
		if (left <= start && end <= right) return tree[node];

		int mid = (start + end) / 2;
		long long leftresult = query(2 * node + 1, start, mid, left, right);
		long long rightresult = query(2 * node + 2, mid + 1, end, left, right);

		return leftresult + rightresult;
	}

	long long query(int left, int right)
	{
		return query(0, 0, n - 1, left, right);
	}

	void update(int node, int start, int end, int idx, long long dif)
	{
		if (start == end)
		{
			tree[node] += dif;
			return;
		}

		int mid = (start + end) / 2;
		int leftnode = 2 * node + 1;
		int rightnode = 2 * node + 2;

		if (idx <= mid)
		{
			update(leftnode, start, mid, idx, dif);
		}
		else
		{
			update(rightnode, mid + 1, end, idx, dif);
		}

		tree[node] = tree[leftnode] + tree[rightnode];
	}

	void update(int idx, long long value)
	{
		long long dif = value - arr[idx];
		arr[idx] = value;
		update(0, 0, n - 1, idx, dif);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	SegmentTree SegTree(v);

	for (int i = 0; i < m + k; i++)
	{
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			SegTree.update(b - 1, c);
		}
		else
		{
			cout << SegTree.query(b - 1, c - 1) << '\n';
		}
	}
}

