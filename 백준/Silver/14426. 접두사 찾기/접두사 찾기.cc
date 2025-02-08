#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include "memory.h"
#include <set>
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <numeric>
#include <limits.h>
#include <list>
using namespace std;

int n, m, res = 0;

struct Trie
{
private:
    map<char, Trie*> TrieNode;

public:

    void insert(const string& str, int index)
    {
        if (index == str.length()) return;

        char ch = str[index];
        if (TrieNode.find(ch) == TrieNode.end())
        {
            TrieNode[ch] = new Trie();
        }
        TrieNode[ch]->insert(str, index + 1);
    }

    void find(const string& str, int index)
    {
        if (index == str.length()) res++;

        if (TrieNode.find(str[index]) != TrieNode.end())
        {
            TrieNode[str[index]]->find(str, index + 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;

    Trie* Root = new Trie();
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        Root->insert(str, 0);
    }
    
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;

        Root->find(str, 0);
    }

    cout << res;
}