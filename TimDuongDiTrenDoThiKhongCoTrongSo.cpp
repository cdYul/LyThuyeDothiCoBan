// Tim đường đi giữa 2 đỉnh (vô hướng và có hướng):
/// code tương tự thuật toán dfs và bfs nhưng duy trig thêm
/// mảng "parent" để truy vết đường đi. Giả sử tìm đường đi s - > t ta gọi dfs(s) hoặc bfs(s)
#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
using ll = long long;

int n, m, s, t;
vector<int> adj[maxn];
bool visited[maxn];
int parent[maxn];

// DFS
void dfs(int u)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            // danh dau u la cha cua v
            parent[v] = u;
            dfs(v);
        }
    }
}

// BFS
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto x : adj[v])
        {
            if (!visited[x])
            {
                // danh dau v la cha cua x
                parent[x] = v;
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

/// Truy van duong di
void Path(int s, int t)
{
    if (parent[t] == 0)
    {
        return;
    }
    else
    {
        // Lua truy van
        vector<int> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(begin(path), end(path));
        for (auto x : path)
            cout << x << ' ';
    }
}

void inp()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    bfs(s);
    Path(s, t);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        cout << endl;
    }
}
