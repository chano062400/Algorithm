#include <string>
#include <vector>

using namespace std;

char num[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<char> v;
    v.push_back('0');
    for(int i=1; ; i++)
    {
        int number = i;
        string str = "";
        while(number >= 1)
        {
            str = str + num[number % n]; 
            number /= n;
        }
        
        for(int i = str.length()-1; i>=0; i--) v.push_back(str[i]);
        
        if(v.size() >= t * m) break;
    }
    
    int cnt = 0;
    for(int i= p-1; i < v.size(); i+=m)
    {
        if(cnt >= t) break;
        answer += v[i];
        cnt++;
    }
    return answer;
}