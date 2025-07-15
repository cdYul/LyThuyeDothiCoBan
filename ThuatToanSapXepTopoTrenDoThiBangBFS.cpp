// Thuat toan sap xep topo tren do thi

///
#include <bits/stdc++.h>
#define endl "\n"
#define maxn 1001
using namespace std;
using ll = long long;

int n, m;
vector<int> adj[maxn], pos;
bool visited[maxn];
int cnt[1001];
//DFS
void dfs(int u){
    visited[u] =  true;
    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    ///Dinh da duoc duyet xong
    pos.push_back(u);// luu vao cuoi danh sach
}

void bfs(int u){

}

void topo(){
    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(begin(pos), end(pos));
    for(auto x: pos) cout << x <<' ';
}

//Thuat toan kahn(note) : dem ban bac vao -> xet cac dinh co ban bac vao 0 push vao danh sach
void kahn(){
    queue<int> q;
    for(int i = 1; i<= n; i++){
        if(cnt[i]== 0) q.push(i);
    }
    while(!q.empty()){
        int v = q.front();
        pos.push_back(v);
        q.pop();
        for(auto x: adj[v]){
            cnt[x]--;
            if(cnt[x] == 0){
                q.push(x);
            }
        }
    }
    for(auto x: pos) cout << x <<' ';
}
//Tren do thi co huong
void inp()
{
    cin >> n >> m;
    for(int i = 1; i<= n; i++){
        adj[i].clear();
    }
    for(int j = 1; j <=  m; j++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        cnt[y]++;
    }

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
