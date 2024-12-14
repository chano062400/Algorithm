#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap; // 최소 힙
priority_queue<int> max_heap; // 최대 힙
unordered_map<int, int> sync_map; // 값의 개수를 기록하는 동기화 맵

vector<int> solution(vector<string> arguments) {
    vector<int> answer;

    for (const string& argument : arguments) 
    {
        char o = argument[0]; 
        int n = stoi(argument.substr(2));

        if (o == 'I') 
        {
            min_heap.push(n);
            max_heap.push(n);
            sync_map[n]++;
        } else if (o == 'D') 
        {
            if (n == 1) 
            { 
                while (!max_heap.empty() && sync_map[max_heap.top()] == 0) 
                {
                    max_heap.pop(); 
                }
                if (!max_heap.empty()) 
                {
                    int max_val = max_heap.top();
                    max_heap.pop();
                    sync_map[max_val]--;
                }
            } 
            else 
            { 
                while (!min_heap.empty() && sync_map[min_heap.top()] == 0) 
                {
                    min_heap.pop(); 
                }
                if (!min_heap.empty()) 
                {
                    int min_val = min_heap.top();
                    min_heap.pop();
                    sync_map[min_val]--;
                }
            }
        }
    }

    while (!max_heap.empty() && sync_map[max_heap.top()] == 0) 
    {
        max_heap.pop();
    }
    while (!min_heap.empty() && sync_map[min_heap.top()] == 0) 
    {
        min_heap.pop();
    }

    if (min_heap.empty() || max_heap.empty()) 
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else 
    {
        answer.push_back(max_heap.top());
        answer.push_back(min_heap.top());
    }

    return answer;
}