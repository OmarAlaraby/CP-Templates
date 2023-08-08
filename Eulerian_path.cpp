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

// Eulerian Path for Directed graphs
template < typename T = int > struct Eulerian_Directed_Path{
    vector < vector < T > > adj;
    vector < T > in, out , path;
    map < pair < int , int > , bool > visited;

    T n, m;
    Eulerian_Directed_Path(T n, T m) : n(n), m(m){
        adj.resize(n + 5);
        in.resize(n + 5);
        out.resize(n + 5);
    }

    void add_edge(T u, T v){
        adj[u].push_back(v);
        out[u]++;
        in[v]++;
    }

    bool hasEulerianPath(){
        T start_nodes = 0, end_nodes = 0;
        for(int i = 1; i <= n; i++){
            if(abs(in[i] - out[i]) > 1) return false;
            if(out[i] - in[i] == 1) start_nodes++;
            if(in[i] - out[i] == 1) end_nodes++;
        }
        return (start_nodes == 1 and end_nodes == 1 and m > 2);
    }

    int find_start_node(){
        int start = 0;
        for(int i=0; i<n; i++){
            if(out[i] - in[i] == 1) return i;
            if(out[i] > 0) start = i;
        }
        return start;
    }

    void dfs(T u){
        stack < T > st;
        st.push(u);

        while(not st.empty()){
            T v = st.top();
            
            if(adj[v].empty()){
                path.push_back(v);
                st.pop();
            }
            else{
                T w = adj[v].back();
                adj[v].pop_back();
                st.push(w);
            }
        }
    }

    vector < T > get_path(){
        if(!hasEulerianPath())
            return path; // return an empty path

        dfs(find_start_node());

        if(sz(path) != m + 1)
            return {};

        reverse(all(path));
        return path;
    }
};


// Eulerian Path for directed graphs of strings
template < typename T = int > struct Eulerian_Directed_Path{
    map < string , vector < string > > adj;
    map < string , T > in, out;
    vector < string > path;
    set < string > subs;
    map < string , bool > connected;
 
    T n, m;
    Eulerian_Directed_Path(T n, T m) : n(n), m(m){}
 
    void add_edge(string u, string v){
        adj[u].push_back(v);
        subs.emplace(u);
        subs.emplace(v);
        out[u]++;
        in[v]++;
    }
 
    bool hasEulerianPath(){
        T start_nodes = 0, end_nodes = 0;
        for(auto &i : subs){
            if(abs(in[i] - out[i]) > 1) return false;
            if(out[i] - in[i] == 1) start_nodes++;
            if(in[i] - out[i] == 1) end_nodes++;
        }
        return (start_nodes == 0 and end_nodes == 0) or (start_nodes == 1 and end_nodes == 1);
    }
 
    string find_start_node(){
        string start;
        for(auto &i : subs){
            if(out[i] - in[i] == 1) return i;
            if(out[i] > 0) start = i;
        }
        return start;
    }
 
    void dfs(string u){
        stack < string > st;
        st.push(u);
 
        while(not st.empty()){
            string v = st.top();
            connected[v] = true;
            
            if(adj[v].empty()){
                if(sz(path)){
                    string &fix = path.back();
                    reverse(all(fix));
                    fix.pop_back();
                    reverse(all(fix));
                }
                path.push_back(v);
                st.pop();
            }
            else{
                string w = adj[v].back();
                adj[v].pop_back();
                st.push(w);
            }
        }
    }
 
    vector < string > get_path(){
        if(!hasEulerianPath())
            return {}; // return an empty path
 
        dfs(find_start_node());
 
        for(auto &i : subs)
            if(not connected[i])
                return {};
 
        // if(sz(path) != m + 1)
        //     return {};
 
        reverse(all(path));
        return path;
    }
};


// Eulerian Path for Undirected graphs
template < typename T = int > struct Eulerian_Undirected_Path{
    vector < vector < T > > adj;
    vector < T > degree , path;
    map < pair < int ,int > , bool > visited;

    T n, m;
    Eulerian_Undirected_Path(T n, T m) : n(n), m(m){
        adj.resize(n + 1);
        degree.resize(n + 1);
    }

    void add_edge(T u, T v){
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    bool hasEulerianPath(){
        T odd_nodes = 0;
        for(int i = 1; i <= n; i++){
            if(degree[i] & 1) odd_nodes++;
        }
        return odd_nodes == 2 or odd_nodes == 0;
    }

    void get_path(T u){
        stack < T > st;
        st.push(u);

        while(not st.empty()){
            T u = st.top();
            bool ok = false;

            while(not adj[u].empty()){
                T v = adj[u].back();
                adj[u].pop_back();

                if(not visited[{v , u}]){
                    visited[{v , u}] = visited[{u , v}] = true;
                    st.push(v);
                    ok = true;
                    break;
                }
            }
            if(not ok){
                st.pop();
                path.push_back(u);
            }
        }
    }

    vector < T > get_path(){
        if(!hasEulerianPath())
            return path; // return an empty path

        get_path(1);
        
        if(sz(path) != m + 1)
            return {};

        return path;
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
