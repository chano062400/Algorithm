#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0, sum=0;
    for(auto k : arr) sum +=k;
    return answer = sum / arr.size();
}