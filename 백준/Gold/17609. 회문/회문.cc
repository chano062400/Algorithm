#include <iostream>
#include <vector>
using namespace std;

bool ispal(const string& str, int left, int right)
{
	while (left < right)
	{
		if (str[left] != str[right]) return false;
		left++;
		right--;
	}
	return true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		int left = 0, right = str.length() - 1;
		bool flag = false;
		while (left < right)
		{
			if (str[left] != str[right])
			{
				if (ispal(str, left + 1, right) || ispal(str, left, right - 1))
				{
					flag = true;
				}
				else
				{
					cout << 2 << '\n';
					break;
				}

				cout << 1 << '\n';
				break;
			}
			else
			{
				left++;
				right--;
			}
		}

		if (left >= right)
		{
			cout << 0 << '\n';
		}
	}
}