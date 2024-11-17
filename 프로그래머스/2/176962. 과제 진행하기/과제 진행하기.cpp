#include <bits/stdc++.h>

using namespace std;

struct info
{
    string subject;
    int start, cost;
};

struct cmp
{
    bool operator()(const info& i1, const info& i2)
    {
        return i1.start > i2.start;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<info, vector<info>, cmp> pq;
    stack<info> st;
    int mintime = 2359;
    for(int i = 0; i < plans.size(); i++)
    {
        // 모두 분으로 바꿔서 계산
        int h = stoi(plans[i][1].substr(0,2));
        int m = stoi(plans[i][1].substr(3,2));
        int minutes = h * 60 + m;
        int duration = stoi(plans[i][2]);
        pq.push({plans[i][0], minutes, stoi(plans[i][2])});
    }
    
    int thistime = pq.top().start;
    while(!pq.empty())
    {
        string subject = pq.top().subject;
        int start = pq.top().start;
        int cost = pq.top().cost;
        pq.pop();
        
        int interval = start - thistime;
        // 다른 과목 시작 전까지 남은 시간이 있음 - 진행중이던 다른 과제 이어서 시작
        if(interval > 0)
        {
            while(interval > 0 && !st.empty())
            {
                string stsubject = st.top().subject;
                int ststart = st.top().start;
                int stcost = st.top().cost;
                st.pop();
                
                // 진행중이던 과제 끝
                if(stcost <= interval)
                {
                    answer.push_back(stsubject);
                    interval -= stcost;
                    thistime += stcost;
                }
                // 남은 시간 만큼 진행하고 다시 stack에 넣음
                else
                {
                    st.push({stsubject, ststart, stcost - interval});
                    thistime += interval;
                    interval = 0;
                }
                thistime = start;
            }
        }
        else 
        {
            thistime = start;
        }

        // 다음 과목 시작 시간
        int nextstart = pq.empty() ? INT_MAX : pq.top().start;
        // 현재 과목 끝나는 시간
        int finishtime = start + cost;
        // 다음 과목 시작 시간 전까지 끝나면 answer에 넣음
        if(finishtime <= nextstart)
        {
            answer.push_back(subject);
            thistime = finishtime;
        }
        // 다음 과목 시작 시간 전까지 끝나지 않으면 - 진행 중인 과목 배열에 넣음(stack)
        else
        {
            st.push({subject, start, cost - (nextstart - start)});
            thistime = nextstart;
        }        
    }
    
    while(!st.empty())
    {
        answer.push_back(st.top().subject);
        st.pop();
    }
    
    return answer;
}