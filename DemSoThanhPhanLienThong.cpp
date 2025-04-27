//DemSoThanhPhanLienThong

//Trên đồ thị vô hướng:
///Mã Giả:
/// ConnectedComponent(){
///     Khởi tạo số thành phần liên thông ban đầu của đồ thị = 0;
///     cnt = 0;
///     Lặp
///     for(int i = 1; i <= n; i++){
///         if(!vsited[i]){
///             cnt++; Tăng số thành phần liên thông
///             dfs(i); //bfs(i)
///         }
///     }
///     return cnt;
///}

#include <bits/stdc++.h>
#define maxn 1001
using namespace std;
using ll = long long;

int n, m;
vector<int> ke[1001];
bool visited[1001];
//DFS
void dfs(int u)
{
    visited[u] = true;
    for (auto v : ke[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}
//BFS
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << ' ';
        for (auto x : ke[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
//Kiem tra so tp lien thong:
int ConnectedComponent()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            bfs(i);
            cout << endl;
        }
    }
    return cnt;
}
void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ke[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    cout << ConnectedComponent();
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
