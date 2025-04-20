// BFS, DFS on grid
/// Bai toan 1: Đếm số thành phần liên thông trên lưới
/// Bai toan 2: Kiếm tra đường đi giữa 2 điểm trên lưới
/// Bai toan 3: Tim số bước đi tối thiểu giữa 2 ôn trên lưới

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <map>
#define maxn 1001
using namespace std;
using ll = long long;

int n, m;
char a[maxn][maxn];
bool visited[maxn][maxn];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

// DFS
void dfs(int i, int j)
{
    cout << i << ' ' << j << endl;
    visited[i][j] = true;
    // Duyet cac dinh ke
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 and i1 <= n and j1 >= 1 and j1 <= m and a[i1][j1] == 'x' and !visited[i1][j1])
        {
            dfs(i1, j1);
        }
    }
}

// BFS
void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        cout << a[p.first][p.second];
        // duyet cac dinh ke
        for (int k = 0; k < 4; k++)
        {
            int i1 = p.first + dx[k];
            int j1 = p.second + dy[k];
            if (i1 >= 1 and i1 <= n and j1 >= 1 and j1 <= m and a[i1][j1] == 'x' and !visited[i1][j1])
            {
                visited[i1][j1] = true;
                q.push({i1, j1});
            }
        }
    }
}

/// Bai toan 1: Đếm số thành phần liên thông trên lưới
void solve()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == ' x' and !visited[i][j])
            {
                cnt++;
                dfs(i, j); // bfs(i,j)
            }
        }
    }
    cout << cnt;
}

/// Bai toan 2: Kiếm tra đường đi giữa 2 điểm trên lưới

void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    memset(visited, false, sizeof(visited));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
    }
}