#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<arr1.size(); i++)
    {
        int size = arr1.size() -1;
        char ch1, ch2;
        string str="";
        while(size >= 0)
        {
            int div = pow(2,size);
            if(arr1[i] / div >= 1) ch1 ='#', arr1[i] %= div;
            else ch1 = '0';
            if(arr2[i] / div >= 1) ch2 ='#', arr2[i] %= div;
            else ch2 = '0';
            if(ch1 == '#' || ch2 == '#') str+="#";
            else str+=" ";
            size--;
        }
        answer.push_back(str);
    }

    return answer;
}