#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define MAX 9

int N,M;
int first[MAX];
int arr[MAX];
bool visited[MAX];
set<vector<int>> s;

void dfs(int num, int k) {
    if(k==M) { 
        vector<int> v;
        for(auto i=0;i<M;i++)
            v.push_back(arr[i]);
        s.insert(v);
        v.clear();
    }else { 
        for(auto i=num; i<N;i++) {
            if(!visited[i]) { 
                visited[i]=true;
                arr[k]=first[i]; 
                dfs(i+1, k+1); 
                visited[i]=false; 
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++)
        cin >> first[i];
    
    sort(first,first+N);

    dfs(0, 0);

    for(auto vector:s) {
        for(auto temp:vector)
            cout << temp << " ";
        cout << "\n";
    }
}