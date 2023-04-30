#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
 
void Omar_Alaraby(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
 
#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec , n , m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define cout_map(mp) for(auto& [first, second] : mp) cout << first << " --> " << second << "\n";
#define put(s) return void(cout << s << dl);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define ll long long
#define ull unsigned long long
#define dl "\n"
#define ordered_set tree<ll ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>
 
const ll Mod = 1e9 + 7;
 
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

struct item{
    ll Xor;
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

    void build(vector < ll > &v , int idx , int l , int r){
        if(l == r){
            if(l < sz(v))
                Seg_Tree[idx] = Single(v[l]);
            return;
        }

        int mid = l + (r - l) / 2;
        build(v , 2 * idx , l , mid);
        build(v , 2 * idx + 1, mid + 1 , r);
        Seg_Tree[idx] = Merge(Seg_Tree[2 * idx] , Seg_Tree[2 * idx + 1]);
    }

    void build(vector < ll > &v){
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
 
    cout << (5 ^ 0) << dl;
}
 
int main(){
    Omar_Alaraby();
 
    int tc = 1;
    //cin >> tc;
 
    for(int i=1; i<=tc; i++){
        //cout << "Scenario #" << i << ":" << dl;
        Solve();
    }
 
    Time
    return 0;
}
