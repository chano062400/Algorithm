#include <iostream>
using namespace std;

char arr[3072][6143];
int n;

void dfs(int x, int y, int len)
{
    if (len == 3)
    {
        arr[x][y] = '*';
        arr[x + 1][y - 1] = arr[x + 1][y + 1] = '*';
        arr[x + 2][y - 2] = arr[x + 2][y - 1] = arr[x + 2][y] = arr[x + 2][y + 1] = arr[x + 2][y + 2] = '*';
        return;
    }

    dfs(x, y, len / 2);
    dfs(x + len / 2, y - len / 2, len / 2);
    dfs(x + len / 2, y + len / 2, len / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            arr[i][j] = ' ';
        }
    }

    dfs(0, n - 1, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}