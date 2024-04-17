#include <bits/stdc++.h> // E
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
 
void Omar_Alaraby(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("business.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define dl "\n"
#define ordered_set tree<int ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>
#define int long long
#define all(v) v.begin(), v.end()
#define INF 2000000000000000000
#define Mod 998244353

struct edge{
    int from , to;
    double w;

    edge(int from, int to , double w) : from(from), to(to), w(w) {}

    bool operator < (const edge &rhs) const{
        return w - rhs.w > 1e-9;
    }
};

struct unionFind{
    vector < int > parent, rank;

    unionFind(int n){
        parent = rank = vector < int > (n , 0);
        for(int i=1; i<n; i++)
            parent[i] = i, rank[i] = 1;
    }

    int findSet(int v){
        if(parent[v] == v)
            return v;
        
        return parent[v] = findSet(parent[v]);
    }

    void link(int x, int y){
        if(rank[x] > rank[y])
            swap(x, y);
        parent[x] = y;
        rank[y] += (rank[x] == rank[y]);
    }

    bool unionSets(int x, int y){
        x = findSet(x) , y = findSet(y);
        if(x != y)
            link(x, y);

        return x != y;
    }
};

void Solve(){

    
} 

int32_t main(){
    Omar_Alaraby();
    
    int testCases=1;
    cin >> testCases;
    
    bool first = true;
    while(testCases--){
        if(not first)
            cout << dl;
        Solve();

        first = false;
    }
 
    return 0;
}