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

template < typename T = int > struct matrix{

    vector < vector < T > > v;

    int n, m;
    matrix(T N , T M){
        n = N , m = M;
        v.assign(n , vector < T >(m, 0));
    }

    vector < T >& operator[](int i) {
        return v[i];
    }

    const vector < T >& operator[](int i) const {
        return v[i];
    }

    friend ostream& operator << (ostream &out, const matrix < T > &mat){
        for(int i = 0; i < mat.n; i++, out << "\n")
            for(int j = 0; j < mat.m; j++)
                out << mat[i][j] << " ";
        return out;
    }

    friend istream& operator >> (istream &in, matrix < T > &mat){
        for(int i = 0; i < mat.n; i++)
            for(int j = 0; j < mat.m; j++)
                in >> mat[i][j];
        return in;
    }


    matrix operator * (const matrix &other){
        matrix < T > ret(n, other.m);
        int r1 = n , c1 = m , c2 = other.m;

        for(int i = 0; i < r1; ++i)
            for(int j = 0; j < c2; ++j)
                for(int k = 0; k < c1; ++k)
                    ret[i][j] += v[i][k] * other.v[k][j];
        return ret;
    }

    matrix power(T x){
        matrix < T > ret(n , m);

        for(int i = 0; i < n; i++)
            ret[i][i] = 1;

        while(x){
            if(x & 1)
                ret = ret * (*this);
            (*this) = (*this) * (*this);
            x >>= 1;
        }
        return ret;
    }
};


void Solve(){

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
