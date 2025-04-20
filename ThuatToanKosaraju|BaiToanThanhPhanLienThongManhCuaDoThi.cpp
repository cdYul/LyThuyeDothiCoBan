//Thuat toan Kosaraju
//Ap dung: Tim so thanh phan lien thong manh cua do thi 
//hoac la kiem tra xem do thi co lien thong manh hay khong

//B1: dfs tren do thi ban dau G -> luu vao 1 stack
//B2: Xay dung do thi lat nguoc TG
//B3: pop cac dinh trong satck o b1 va goi dfs tren TG
//O(2*(V+E))
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
vector<int> G[maxn], TG[maxn];
bool  visited[maxn];
stack <int> s;

void dfs1(int u){
    visited[u] = true;
    for(int v: G[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    s.push(u);
}
void dfs(int u){
    visited[u] = true;
    cout << u <<' ';
    for(int v: TG[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
//Kiem tra do thi co lien thong manh khong
void kasaraju(){
    int tmp = 0;
    memset(visited, false, sizeof(visited));
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!visited[v]){
            dfs(v);
            cout << endl;
            tmp++;
        }
    }
    cout << tmp;
}

void inp()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        G[i].clear();
        TG[i].clear();
    }
    for(int i = 1; i<= m; i++){
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        TG[y].push_back(x); //  Xay dung TG
    }
    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    kasaraju();
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
