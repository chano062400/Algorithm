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

int n;
vector<string> sen;

void back(int depth, int target, string str)
{
    if (depth == target)
    {
        vector<int> v;
        vector<char> op;

        // ' ' 공백을 붙인 수식으로 변환
        string temp = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ') temp += str[i];
        }

        // 바꾼 수식을 기호와 숫자로 따로 담음
        string num = "";
        for (int i=0; i<temp.length(); i++)
        {
            if (temp[i] == '+' || temp[i] == '-')
            {   
                v.push_back(stoi(num));
                op.push_back(temp[i]);
                num = "";
                continue;
            }
            num += temp[i];
        }
        v.push_back(stoi(num));
        
        // 계산   
        int total = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (op[i - 1] == '+') total += v[i];
            else total -= v[i];
        }

        if (total == 0) sen.push_back(str);
        return;
    }

	back(depth + 1, target, str + '+' + to_string(depth + 1));
	back(depth + 1, target, str + '-' + to_string(depth + 1));
	back(depth + 1, target, str + ' ' + to_string(depth + 1));

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        back(1, num, "1");

        sort(sen.begin(), sen.end());

        for (auto s : sen)
        {
            cout << s << '\n';
        }
        sen.clear();
        cout << '\n';
    }
}
