#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;

void Omar_Alaraby(char * input , char * output){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen(input, "r", stdin), freopen(output, "w", stdout);
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

const ll Mod = 998244353;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

//------------------------------------------------------------------------------------------------



template < typename T = int > struct Coordinate_Compression {

    vector < T > compressed;
    bool is_build = true;

    Coordinate_Compression(){}

    Coordinate_Compression(vector < T > &vec) {
        compressed = vec;
        build();
    }

    void add(T x) {
        compressed.push_back(x);
        is_build = false;
    }

    void build() {
        sort(all(compressed));
        compressed.resize(unique(all(compressed)) - compressed.begin());
        is_build = true;
    }

    T get(T x) {
        if(!is_build) build();
        return upper_bound(all(compressed), x) - compressed.begin();
    }

    vector < T > get_compressed(vector < T > &vec) {
        if(!is_build) build();
        vector < T > ret;
        for (auto &x : vec) 
            ret.push_back(get(x));
        return ret;
    }

    vector < T > get_mapping(vector < T > &vec) {
        if(!is_build) build();
        vector < T > ret(sz(compressed) + 5);
        for (auto &x : vec)
            ret[get(x)] = x;
        return ret;
    }

    int size(){
        if(!is_build) build();
        return sz(compressed);
    }

};



//--------------------------------------------------------------------------------------------
void Solve(){

}

int main(){
    Omar_Alaraby("input.txt" , "output.txt");

    int tc = 1;
    //cin >> tc;

    for(int i=1; i<=tc; i++){
        //cout << "Scenario #" << i << ":" << dl;
        Solve();
    }

    Time
    return 0;
}
