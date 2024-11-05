#include <bits/stdc++.h>
using namespace std;

int priorities[6][3] = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};

int getpriority(char op, int idx)
{
    int idx1;
    if (op == '+') idx1 = 0;
    else if (op == '-') idx1 = 1;
    else idx1 = 2;

    return priorities[idx][idx1];
}

long long calc(long long n1, long long n2, char op)
{
    if (op == '+') return n1 + n2;
    else if (op == '-') return n1 - n2;
    else return n1 * n2;
}

long long solution(string expression) {
    long long answer = 0;
    vector<char> operators;
    vector<long long> nums;
    int idx = 0;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        if (!isdigit(ch))
        {
            operators.push_back(ch);
            string num = expression.substr(idx, i - idx);
            idx = i + 1;
            nums.push_back(stoll(num));
        }
    }
    nums.push_back(stoll(expression.substr(idx, expression.length() - idx)));

    for (int i = 0; i < 6; i++)
    {
        vector<char> optemp = operators;
        vector<long long> numstemp = nums;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < optemp.size();)
            {
                if (getpriority(optemp[k], i) == j)
                {
                    long long value = calc(numstemp[k], numstemp[k + 1], optemp[k]);
                    numstemp[k] = value;
                    numstemp.erase(numstemp.begin() + k + 1);
                    optemp.erase(optemp.begin() + k);
                }
                else k++;
            }
        }
        answer = max(answer, abs(numstemp[0]));
    }

    return answer;
}
