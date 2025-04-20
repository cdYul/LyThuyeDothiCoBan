// Thuat toan tim kiem theo chieu sau tren do thi
// DFS: Depth First Search
/// Thuật toán tìm kiếm theo chiều sâu: Ưu tiên duyệt xuống nhất có thể trước khi quay lại
// Pseudocode:

// Bắt đầu duyệt tùe đỉnh u:
/// DFS(u){
///      <Tham Dinh u>;
///      visited[u] = true; Danh dấu đã được thăm
///      Duyet cac dinh ke voi dinh u
///      for(v : adj[u]){
///          if(!visited[v]){ Nếu v chưa được thăm
///              DFS(v);
///          }
///      }
///  }

// Cac loại cây tìm kiếm DFS
/// Tree Edge: La cạnh mà theo đó từ một đỉnh ta đến thăm một đỉnh mới
/// Back Edge(Note): Cạnh Ngược là cạnh đi từ con cháu -> tổ tiên
/// Forwark Edge: Cạnh tới cạnh từ tổ tiên tới hậu duệ
/// Cross Edge: Cạnh vòng là cạnh nối 2 đỉnh không có quan hệ hộ hàng

// Su Dung NGAN SEP : stack, quay lui

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
using namespace std;
using ll = long long;

int n, m, a[1001][1001];
vector<int> adj[1001];
bool visited[1001];

void DFS(int u)
{
    cout << u << ' ';
    // Danh dua u da duoc tham
    visited[u] = true;
    for (auto v : adj[u])
    {
        // Neu dinh v chua duoc tham
        if (!visited[v])
        {
            DFS(v);
        }
    }
}

int inp()
{
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    // test do thi co huong
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    DFS(1);
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
