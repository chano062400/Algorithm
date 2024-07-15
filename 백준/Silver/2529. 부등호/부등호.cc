#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include "algorithm"

using namespace std;

int n;
long long minres = 999876543210, maxres = 0;
char arr[100];
bool visited[100];
vector<int> v;

void back(int index ,int prev)
{
	if (v.size() == n + 1)
	{	
		string str = "";
		for (auto s : v)
		{	
			str += to_string(s);
		}
		minres = min(minres, stoll(str));
		maxres = max(maxres, stoll(str));
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (v.empty() && !visited[i])
		{
			v.push_back(i);
			visited[i] = 1;
			back(0, i);
			v.pop_back();
			visited[i] = 0;
		}

		if (!visited[i])
		{
			if (arr[index] == '<')
			{
				if (i > prev)
				{
					visited[i] = 1;
					v.push_back(i);
					back(index + 1, i);
					v.pop_back();
					visited[i] = 0;
				}
			}

			if (arr[index] == '>')
			{
				if (i < prev)
				{
					visited[i] = 1;
					v.push_back(i);
					back(index + 1, i);
					v.pop_back();
					visited[i] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	back(0,0);

	cout << setw(n + 1) << setfill('0') << to_string(maxres);
	cout << '\n';
	cout << setw(n+1) << setfill('0') << to_string(minres);

	return 0;
}