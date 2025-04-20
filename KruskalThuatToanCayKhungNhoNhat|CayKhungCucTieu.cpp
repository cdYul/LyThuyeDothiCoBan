// Kruskal : Tim cay khung cuc tieu| Bai toan cay khung nho nhat

// Dinh nghia cay khung: 
/// Nhiem vu: ket noi tat ca cac dinh trong do thi

// n dinh -> n - 1 canh

/// Vo huong co trong so :  Tim cay khung ket noi all  dinh trong do thi  ma co trong so nho nhat
/// MST : Minimum spanning tree (Cay khung)
//Ma gia :  Kruskal (n: so dinh)
// <b1> Khoi tao:
// MST = ∅; E: tap canh
// d(MST) = 0;
// <b2> Sap sep 
// <sort cac canh thuoc do dai>
// <b3> Lap
// While(|MST| < n -1 or  E khac ∅){
//      e = <canh ngan nhat thuoc E>;
//      E = E|{e};
//      if(MST  U (e) khong tao thanh chu trinh){
//          MST = MST U e
//          d(MST) += d(e)

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
using namespace std;
using ll = long long;
const int maxn = 1001;
struct DAC{
    int u, v;
    int w;
};
int n,  m, parent[maxn], size[maxn];
vector<DAC> canh;
void make_set(){
    for(int i = 1; i<= n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int a){
    if(a == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
    return false;
}

bool cmp (DAC a, DAC b){
    return a.w < b.w;
}

void Kruskal(){
    //Tao cay khung cuc tieu
    vector<DAC> mst;
    int d = 0;
    //Sort danh sach canh theo chieu dai tang dan
    sort(begin(canh), end(canh), cmp);
    //Lap
    for(int i = 0; i < m; i++){
        if(mst.size() == n -1) break;
        DAC e = canh[i]; //  chon canh nho nhat
        if(Union(e.u, e.v)){
            mst.push_back(e);
            d += e.w;
        }
    }
    //Tra ve ket qua
    //...
}
void inp(){
    cin >> n >> m;
    for(int i = 1; i<= m; i++){
        int x, y, z; cin >> x >> y >> z;
        DAC egde = {x,y,z};
        canh.push_back(egde);
    }
}