#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0, sum = 0;
    vector<int> v(10);
    for(auto s : numbers) sum += s;
    answer = 45 - sum;
    return answer;
}