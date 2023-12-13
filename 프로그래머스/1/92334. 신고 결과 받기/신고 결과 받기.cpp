#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    multimap<string,string> reported;
    map<string, int> cnt;
    for(auto id : id_list) cnt.insert({id,0}); // cnt {id, 신고한 사람 중 정지된 사람 수}
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end()); // 중복 신고 제거
    for(auto rep : report) 
    {
        for(int i=0; i<rep.length(); i++) 
        {
            // reported{신고받은 사람, 신고한 사람}
            if(rep[i] == ' ') reported.insert({rep.substr(i+1, rep.length() - i), rep.substr(0, i)});
        }
    }
    // k 이상으로 신고를 받았다면 = 정지, cnt[rep.value]++ 
    for(auto rep : reported) if(reported.count(rep.first) >= k) cnt[rep.second]++;
    for(auto id : id_list) // id_list의 id와 cnt의 key값이 같으면 value값을 answer에 추가
    {
        for(auto reportid : cnt)
        {
            if(id == reportid.first) answer.push_back(reportid.second);
        }
    }
    
    return answer;
}