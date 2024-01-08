#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

string lower(string city)
{
    string str = "";
    for(auto& s : city)
    {
        str += tolower(s);
    }
    
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) answer = cities.size() * 5;
    else
    {
        for(auto& city : cities) city = lower(city);
        
        list<string> cache; // 캐시    
        
        for(int i=0; i<cities.size(); i++)
        {
            string city = cities[i];
            
            auto itr = find(cache.begin(), cache.end(), city);
            if(itr == cache.end()) // 캐시에 없을 때
            {
                answer += 5;
                if(cache.size() == cacheSize)
                {
                    cache.erase(cache.begin()); // 가장 오래된 데이터 뺌.
                }
            }
            else // 캐시에 있을 때
            {
                answer += 1;
                cache.erase(itr); // 해당 데이터 뺌
            }
            
            cache.push_back(city); // 캐시에 있다면 해당 데이터 다시 추가 / 없다면 새로운 데이터 추가.
            
        }
    }
    
    return answer;
}