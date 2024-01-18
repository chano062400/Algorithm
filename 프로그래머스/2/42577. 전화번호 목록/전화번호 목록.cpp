#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true, isfind= false;
    map<string, bool> number;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size(); i++)
    {
        for(int j=0; j<phone_book[i].length(); j++)
        {
            string str = phone_book[i].substr(0,j+1);
            if(number.size() > 0 && number.count(str) > 0) 
            {
                answer = false;
                isfind = true;
                break;
            }
        }
        number.insert({phone_book[i], true});
        if(isfind) break;
    }
    return answer;
}