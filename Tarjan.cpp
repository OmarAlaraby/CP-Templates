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

int n , m;
vector < vector < int > > adj, comps;
vector < int > inStack, depth, lowLink, comp;
stack < int > st;
int currDepth = 0;

void tarjan(int curr){
    lowLink[curr] = depth[curr] = currDepth++;
    inStack[curr] = 1;
    st.push(curr);

    for(auto &i : adj[curr]){
        if(depth[i] == -1){
            tarjan(i);
            lowLink[curr] = min(lowLink[curr], lowLink[i]);
        }
        else if(inStack[i])
            lowLink[curr] = min(lowLink[curr], lowLink[i]);
    }

    if(lowLink[curr] == depth[curr]){
        comps.push_back(vector < int > ());

        int x = -1;
        while(x != curr){
            x = st.top();
            st.pop();
            inStack[x] = 0;
            comps.back().push_back(x);
            comp[x] = comps.size() - 1;
        }
    }
}

void Solve(){

    
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