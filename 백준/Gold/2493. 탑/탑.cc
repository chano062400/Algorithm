#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

long long arr[500001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int n,height;
    
    cin >> n;
    
    stack<pair<int,int>> st;
    
    for (int i = 1; i <=n; i++)
    {
        cin >> height;
        if (st.empty()) st.push(make_pair(1000000000, 0));

        while (st.top().first < height) st.pop();

        cout << st.top().second << " ";

        st.push(make_pair(height, i));
    }

   
   
}