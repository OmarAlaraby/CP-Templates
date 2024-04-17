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