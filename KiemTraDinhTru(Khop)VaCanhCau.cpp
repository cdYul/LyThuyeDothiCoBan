//Dinh Tru: loai bo dinh lam tang so thanh phan lien thong
//Canh cau :  lam tang so tp lien thong cua do thi
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
vector<pair<int, int>> egde;//Luu Danh sach canh


void dfs(int u){
    visited[u] = true;
    for(int i: adj[u]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

//Dinh tru
void solve(){
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    int tmp = 0;
    // dem so tplt ban dau
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    for(int i = 1; i <= n; i++){
        memset(visited,false, sizeof(visited));
        visited[i] = true;
        int dem = 0;
        //dem so tplt sau khi loai bo dinh
        for(int j = 1; j <= n; j++){
            if(!visited[j]){
                dfs(j);
                dem++;
            }
        }
        if(dem > tmp){
            cnt++;
            cout << i <<' ';
        }
    }

}


//dfs loai bo canh 
void dfs2(int u, int s, int t){
    visited[u] = true;
    for(int i: adj[u]){
        if((i == s and u == t) or (i == t and u == s)) continue;
        if(!visited[i]) dfs2(i, s , t);
    }
}

//Canh cau
void canhcau(){
    int ans = 0;
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            dfs(i);
            tplt++;
        }
    }
    for(auto it:  egde){
        int x = it.first; int y = it.second;
        memset(visited, false, sizeof(visited));
        int dem = 0;
        for(int  i =1; i<= n; i++){
            if(!visited[i]){
                dfs2(i, x, y);
                dem++;
            }
        }
        if(dem > tplt) ans++;
    }
    cout << ans;

}


void inp()
{
    cin >> n >> m;
    for(int i = 1; i<= n; i++){
        adj[i].clear();
    }
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        egde.push_back({x,y});
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