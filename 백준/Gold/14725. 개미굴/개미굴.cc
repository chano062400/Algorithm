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

int n;

struct Trie
{
private:

    map<string, Trie*> TrieNode;
    
public:

    void Insert(const vector<string>& foods, int index)
    {
        if (index == foods.size()) return;

        string food = foods[index];
        if (TrieNode.find(food) == TrieNode.end())
        {
            TrieNode[food] = new Trie();
        }
        TrieNode[food]->Insert(foods, index + 1);
    }

    void print(int depth)
    {
        for (const auto& Node : TrieNode)
        {
            for (int i = 0; i < depth; i++)
            {
                cout << "--";
            }
            cout << Node.first << '\n';
            Node.second->print(depth + 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    Trie* Root = new Trie();
    for (int i = 0; i < n; i++)
    {
        int k; 
        cin >> k;
        vector<string> foods(k);
        for(int i = 0; i < k; i++)
        {
            cin >> foods[i];
        }

        Root->Insert(foods, 0);
    }

    Root->print(0);
}