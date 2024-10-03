#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
#include <set>
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

map<string, float> trees;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	float sum = 0.f;
	while (1)
	{
		string str;
		getline(cin, str);
		
		if (cin.eof() == true) break;
		
		if (trees.find(str) == trees.end())
		{
			trees.insert({ str,1.f });
		}
		else trees[str] += 1.f;
		sum += 1.f;
	}

	cout << fixed;
	cout.precision(4);

	for (const auto& tree : trees)
	{
		float divide = (tree.second / sum) * 100.f;

	
		cout << tree.first << " " << divide << '\n';
	}
}

