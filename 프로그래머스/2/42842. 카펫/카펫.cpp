#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for(int i=1; i<=sum; i++)
    {
        int rem = sum % i, div = sum / i;
        
        if(rem == 0 && i >= div && i*2 + (div-2) * 2 >= brown)
        {
            answer.push_back(i);
            answer.push_back(sum / i );
            break;
        }
    }
    return answer;
}