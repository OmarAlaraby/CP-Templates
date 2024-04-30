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

pair < int , int > findDiameter(int curr, int parent, vector < vector < int > > &adj){
    int maxDiameter = 0;
    int heights[3] = {-1 , -1 ,-1};

    for(auto &i : adj[curr]) if(i != parent) {
        auto [childDiameter , childMaxHeight] = findDiameter(i, curr, adj);
        maxDiameter = max(maxDiameter , childDiameter);
        heights[0] = childMaxHeight;
        sort(heights, heights + 3);
    }

    for(auto &height : heights)
        height = height == -1 ? 0 : height;

    return make_pair(max(maxDiameter, heights[1] + heights[2]) , heights[2] + 1);
}

int treeDiameter(int n, vector < vector < int > > &adj){
    return findDiameter(1, -1, adj).first;
}

void Solve(){

    int n; cin >> n;
    vector < vector < int > > adj(n + 1);

    for(int i=1; i<n; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << treeDiameter(n , adj) << dl;
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