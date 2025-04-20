// Kiểm Tra chu trình trên đồ thị vô hướng và có hướng

// mã giả:
/// bool DFS(int u, int par){
///     visited[u] = true;
///     for(int v: adj[u]){
///         if(!visited[v]){
///             if(DFS(v,u)) return true;
///         }
///         else if(v != par) return true; Tồn tại cạnh ngược (v,u)
///     return false;
///}


#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <map>
#include <stack>
#include <math.h>
#include <algorithm>
#define endl "\n"
#define maxn 1001
using namespace std;
using ll = long long;

int n, m;
vector<int> adj[maxn];
bool visited[maxn];
int parent[maxn];
int color[maxn], cnt[maxn];

//Vo hướng
//dsf kiem tru chu trinh
// Note: Chi dung voi do thi lien thong 
//-> neu kho thi xet het thanh phan lien thong
bool dfs(int u, int par){
    visited[u] = true;
    for(int v: adj[u]){
        if(!visited[v]){
            if(dfs(v,u)) return true; // Kiem tra xem da co chu trinh chua
        }
        else if(v != par) return true; // co chu trinh
    }
    return false;
}


//bfs
bool bfs(int u){
    queue<int> q;
    visited[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int x: adj[v]){
            if(!visited[x]){
                q.push(x);
                parent[x] = v;
                visited[x] = true;
            }
            else if(x != parent[v]) return true;
        }
    }
    return false;
}

//có hướng
//dfs
bool DFS(int u){
    color[u] = 1;// mau xam: dinh chua tham xong
    for(int v: adj[u]){
        if(color[v] == 0){// chua duoc tham
            if(DFS(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2;//da duoc tham
    return false;
}

//kahn
bool kahn(){
    queue<int> q;
    for(int i = 1; i<= n; i++){
        if(cnt[i] == 0) q.push(i);
    }
    int tmp = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        tmp++;
        for(int x: adj[v]){
            cnt[x]--;
            if(cnt == 0) q.push(x);
        }
    }
    return tmp == n;
}

void inp()
{
    cin >> n >>m;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }
    for(int i = 1; i<= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    if(dfs(1,0)) cout <<1;
    else cout << 0;

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