// Thuat toan tim kiem theo chieu rong
//  BFS: Tư tưởng của thuật toán là tìm kiếm ưu tiên theo chiều rộng.
/// Thuật toán sẽ tìm kiếm xung quanh để mở rộng trước khi xuống sâu hơn
// Pseudocode:

// BFS(u){
///     Step 1: Khỏi tạo
///     queue = rỗng; tạo một hàng đợi rỗng
///     push(queue, u); Đảy u vào hàng đợi
///     visited[u] = true; Đánh dấu đỉnh u đã được thăm
///     Step 2: Lặp khi mà hàng đợi vẫn còn phần tử
/// while(queue != rỗng){
///     v = queue.front(); Lấy ph/tu ở đầu hàng đợi
///     queue.pop(); Xoa đỉnh khỏi hàng đợi
///     <Thăm đỉnh v>;
///     Duyệt các đỉnh kề với v mà chưa được thăm và đẩy vào hàng đợi
///     for(auto x: ke[v]){
///         if(!visited[x]){
///             push(pueue, x);
///             visited[x] = true;

// Note: Voi do thi ko co trong so -> duong di voi bfs la duong di ngan nhat

// Su Dung HANG DOI : queue


#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;
using ll = long long;

int n, m, a[1001][1001];
vector<int> ke[1001];
bool visited[1001];

void bfs(int u)
{
    // Buoc khoi tao
    queue<int> q;
    q.push(u);
    visited[u] = true;
    // Buoc lap
    while (!q.empty())
    {
        int v = q.front(); //  Lay dinh o dau
        q.pop();
        cout << v << ' ';
        for (auto x : ke[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true; // danh dau x da dc tham
            }
        }
    }
}

int inp()
{
    cin >> n >> m;
    // test do thi vo huong
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    bfs(1);
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