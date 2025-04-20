//Disjoint set  union : DSU | Union Find (Tim Gop)
// Coi moi p/tu ban dau thanh mot dinh tren do thi

// make_set(a) : tao mot tap hop chua p/tu a
// union (a,b) : gop hai tap hop voi nhau (a thuoc tap hop thu 1, b thuoc tap hop thu 2)
// Find (a) : Tim ra p/tu dai dien ma a thuoc tap hop do

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

int n, parent[maxn], size[maxn];

///make_set
void make_set(){
    for(int i = 1; i<= n; i++){
        parent[i] = i;
        size[i] = 1;
    }

}

//find
int find(int a){
    if(a  == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

//union
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if( a != b){
        if(size[a] < size[b]) swap(a,b);
        parent[a] = b;
        size[a] += size[b];
    }
}
