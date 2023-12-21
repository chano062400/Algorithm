#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
using namespace std;

struct Node 
{
    int value;
    Node* Left;
    Node* Right;
};

struct BST
{
    Node* Root = nullptr;

public:

    void Insert(int value)
    {
        if (!Root) Root = new Node{ value, NULL,NULL };
        else Insert_Implementation(Root, value);
    }

    void PostOrder()
    {
        PostOrder_Implementation(Root);
    }

private:

    void Insert_Implementation(Node* Cur, int Value)
    {
        if (Cur->value < Value)
        {
            if (!Cur->Right) Cur->Right = new Node{ Value, NULL, NULL };
            else Insert_Implementation(Cur->Right, Value);
        }
        else
        {
            if (!Cur->Left) Cur->Left = new Node{ Value, NULL, NULL };
            else Insert_Implementation(Cur->Left, Value);
        }
    }

    void PostOrder_Implementation(Node* Start)
    {
        if (!Start) return;
        PostOrder_Implementation(Start->Left);
        PostOrder_Implementation(Start->Right);
        cout << Start->value << '\n';
    }

};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    BST* Root = new BST();

    int Key;

    while (cin >> Key)
    {
        if (Key == EOF) break;
        Root->Insert(Key);
    }
    
    Root->PostOrder();
}
