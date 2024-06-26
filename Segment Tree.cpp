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
    int Xor;
};


struct segTree{
    int size;
    vector < item > Seg_Tree;
    item NEUTRAL_ITEM = {0};

    item Merge(const item & First_Item , const item & Second_Item){
        return {
            First_Item.Xor ^ Second_Item.Xor
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

    item calc(int l , int r){
        return calc(l , r , 1 , 0 , size - 1);
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