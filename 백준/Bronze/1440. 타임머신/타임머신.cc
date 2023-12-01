#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> strs)
{
	int count = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			{
				if (i != j && j != k && k != i)
				{
					if ((stoi(strs[i]) >= 1 && stoi(strs[i]) <= 12) &&
							stoi(strs[j]) >= 0 && stoi(strs[j]) <= 59 &&
							stoi(strs[k]) >= 0 && stoi(strs[k]) <= 59)
						count++;
				}
			}
	return count;
}

int main(void)
{
	string input;
	vector<string> strs;

	cin >> input;
	strs.push_back(input.substr( 0, 2));
	strs.push_back(input.substr( 3, 2));
	strs.push_back(input.substr( 6, 2));

	cout << solution(strs) << endl;
}