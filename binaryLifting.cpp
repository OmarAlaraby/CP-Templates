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
#define Mod 1000000007

void Solve(){

    int n , q; cin >> n >> q;
    vector < int > v(n - 1);

    for(auto &i : v)
        cin >> i;

    int Log = 0;
    while((1 << Log) <= n)
        Log++;

    vector < vector < int > > parent(n + 1, vector < int > (Log));
    parent[1][0] = -1;
    for(int i=2; i<=n; i++)
        parent[i][0] = v[i - 2];

    
    for(int j=1; j<Log; j++)
        for(int i=1; i<=n; i++)
            parent[i][j] = parent[i][j - 1] == -1 ? -1 : parent[ parent[i][j - 1] ][j - 1];

    while(q--){
        int node, k; cin >> node >> k;

        for(int i=0; i<Log and node != -1; i++)
            if(k & (1 << i))
                node = parent[node][i];
    
        cout << node << dl;
    }
} 

int32_t main(){
    Omar_Alaraby();
    
    int testCases=1;
    // cin >> testCases;
    
    // bool first = true;
    while(testCases--){
        // if(not first)
        //     cout << dl;
        Solve();

        // first = false;
    }
 
    return 0;
}