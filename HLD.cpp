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

struct item{
    int val;
};
 
 
struct segTree{
    int size;
    vector < item > Seg_Tree;
    item NEUTRAL_ITEM = {0};
 
    item Merge(const item & First_Item , const item & Second_Item){
        return {
            First_Item.val + Second_Item.val
        };
    }
 
    item Single(int value){
        return {
            value
        };
    }
 
    void init(int n){
        size = n;
        Seg_Tree.assign(4 * size , NEUTRAL_ITEM);
    }
 
    void build(vector < int > &v , int idx , int l , int r){
        if(l == r){
            if(l < v.size())
                Seg_Tree[idx] = Single(v[l]);
            return;
        }
 
        int mid = l + (r - l) / 2;
        build(v , 2 * idx , l , mid);
        build(v , 2 * idx + 1, mid + 1 , r);
        Seg_Tree[idx] = Merge(Seg_Tree[2 * idx] , Seg_Tree[2 * idx + 1]);
    }
 
    void build(vector < int > &v){
        build(v , 1 , 0 , size - 1);
    }
 
    void set(int pos , int value , int idx , int l , int r){
        if(l == r){
            Seg_Tree[idx] = Single(value);
            return;
        }
 
        int mid = l + (r - l) / 2;
        if(pos <= mid)
            set(pos , value , 2 * idx  , l , mid);
        else
            set(pos , value , 2 * idx + 1 , mid + 1 , r);
 
        Seg_Tree[idx] = Merge(Seg_Tree[2 * idx] , Seg_Tree[2 * idx + 1]);
    }
 
    void set(int pos , int value){
        set(pos , value , 1 , 0 , size - 1);
    }
 
    item calc(int l , int r , int idx , int SegL , int SegR){
        if(SegL > r or SegR < l)
            return NEUTRAL_ITEM;
        if(SegL >= l and SegR <= r)
            return Seg_Tree[idx];
 
        int mid = SegL + (SegR - SegL) / 2;
        return Merge( calc(l , r , 2 * idx , SegL , mid) , calc(l , r , 2 * idx + 1 , mid + 1 , SegR));
    }
 
    int calc(int l , int r){
        return calc(l , r , 1 , 0 , size - 1).val;
    }
};
 
struct HLD{
 
    #define VAL_ON_EDGES 0 // 1 => if values are on edges , 0 => otherwise
    vector < vector < int > > adj;
    vector < int > depth, parent, leader, pos, size, heavyEdge;
    int nextPos;
 
    HLD(int n, const vector < vector < int > > &G, int treeRoot = 1, int startLabel = 0){
        nextPos = startLabel;
        adj = G;
        depth = parent = leader = pos = size = heavyEdge = vector < int > (n + 5);
        init(treeRoot);
        build(treeRoot);
    }
 
    void init(int curr, int par = -1, int currDepth = 0){
        depth[curr] = currDepth;
        parent[curr] = par;
        size[curr] = 1;
        for(auto &child : adj[curr]) if(child != par) {
            init(child, curr, currDepth + 1);
            size[curr] += size[child];
            if(size[child] > size[heavyEdge[curr]])
                heavyEdge[curr] = child;
        }
    }
 
    void build(int curr, bool isNewChain = true){
        leader[curr] = isNewChain ? curr : leader[parent[curr]];
        pos[curr] = nextPos++;
 
        if(heavyEdge[curr])
            build(heavyEdge[curr], false);
 
        for(auto &child : adj[curr]) if(child != parent[curr] and child != heavyEdge[curr]) {
            build(child, true);
        }
    }
 
    pair < int , int > moveUp(int &v){
        pair < int , int > ans = {pos[leader[v]] , pos[v]};
        v = parent[leader[v]];
        return ans;
    }
 
    void makeULower(int &u , int &v){
        if(depth[leader[u]] < depth[leader[v]] or (leader[u] == leader[v] and depth[u] < depth[v]))
            swap(u, v);
    }
 
    vector < pair < int , int > > queryPath(int u , int v){
        vector < pair < int , int > > ans;
        while(leader[u] != leader[v]){
            makeULower(u , v);
            ans.push_back(moveUp(u));
        }
 
        makeULower(u, v);
        if(!VAL_ON_EDGES)
            ans.push_back({pos[v], pos[u]});
        else
            ans.push_back({pos[v] + 1, pos[u]});
        
        return ans;
    }

    int getChild(int u , int v){
        if(parent[u] == v)
            return u;
        return v;
    }
};

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