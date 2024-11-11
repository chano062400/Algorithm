#include <string>
#include <vector>

using namespace std;

long long calc(const vector<int>& diffs, const vector<int>& times, int level, long long limit)
{
    long long sum = times[0];
    for(int i = 1; i < diffs.size(); i++)
    {
        if(diffs[i] <= level) sum += times[i];
        else
        {
            sum += (times[i - 1] + times[i]) * (diffs[i] - level) + times[i];
        }
        if(sum > limit) return limit + 1;
    }
    return sum;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 100000, start = 1, end = 100000;
    
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(calc(diffs, times, mid, limit) <= limit)
        {
            answer = min(answer, mid);
            end = mid -1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return answer;
}