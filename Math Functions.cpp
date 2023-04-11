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

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Mod 1000000007

typedef vector<int> vi;
typedef vector<ll> vl;

// get the number of perfect square between l and r

ll num_of_pref_squares(ll l, ll r){
    return ((ll)(sqrtl(r)) - ceil(sqrtl(l)) + 1);
}



ll GCD(ll a, ll b){
    return (!b ? a : GCD(b, a % b));
}

// least common multiplication between two numbers

ll LCM(ll a, ll b){
    return a / GCD(a, b) * b;
}

// Get vector with the prime factors of number

vector < int > prime_factorization(ll n){
    vector < int > factors;
    while(n % 2 == 0) factors.push_back(2), n /= 2;
    for(int i = 3; i <= sqrt(n); i += 2)
        while(n % i == 0) factors.push_back(i), n /= i;
    if(n > 2) factors.push_back(n);
    return factors;
}

//Get the factorst of the a number

vi factors(ll n){
    vi factors;
    while(n % 2 == 0) factors.push_back(2), n /= 2;
    for(int i = 3; i <= sqrt(n); i++)
        while(n % i == 0) factors.push_back(i), n /= i;
    if(n > 2) factors.push_back(n);
    return factors;
}

// nCr with Mod using dp

ll nCr(ll n, ll r){

    if(n == 0 or r < 0)
        return r == 0;

    ll &ret = dp[n][r];
    if(~ret)
        return ret % Mod;

    return ret = (nCr(n - 1, r - 1) % Mod + nCr(n - 1 , r) % Mod) % Mod;
}

// Combination

ll nCr(ll n, ll r){
    if(r > n) return 0;
    ll p = 1, k = 1;
    if (n - r < r) r = n - r;
    // condition for minimum choose
    if(n < 1) return 0;
    while (r > 0){
        p *= n, k *= r;
        ll m = __gcd(p, k);
        p /= m, k /= m, n--, r--;
    }
    return p;
}

// Permutation

ll nPr(ll n, ll r){
    if(r > n) return 0;
    ll npr = 1;
    while(r-- > 0)
        npr *= n--;
    return npr;
}

// get a mod for big int

ll Big_Mod(string s, ll mod){
    ll res = 0;
    for(auto& c : s)
        res = (res * 10 + (c - '0')) % mod;
    return res;
}

// add two number and take mod for them

void add(ll& a, ll b, ll mod = 1e9 + 7){
    a += b;
    if(a >= mod)
        a -= mod;
}

// multiply two number and take mod for them

void mul(ll& a, ll b, ll mod = 1e9 + 7){
    a = ((a % mod) * (b % mod)) % mod;
}

// b power e in O(log(n))

ll fast_pow(ll b, ll e){
    ll power = 1;
    while(e){
        if(e & 1) power *= b;
        e >>= 1;
        b *= b;
    }
    return power;
}

// b power e % mod in O(log(e))

ll fast_pow(ll b, ll e, ll mod){
    ll power = 1;
    while(e){
        if(e & 1) mul(power, b, mod);
        e >>= 1;
        mul(b, b, mod);
    }
    return power % mod;
}

// b multiply e % mod in O(log(e))

ll fast_mul(ll b, ll e, ll mod){
    ll mult = 0;
    while(e){
        if(e & 1) add(mult, b, mod);
        e >>= 1;
        add(b, b, mod);
    }
    return mult % mod;
}

// Check if number is prime or not

bool is_prime(ll n){
    if(n < 2 || (n % 2 == 0 && n != 2)) return false;
    for(int i = 3; i <= sqrt(n); i += 2)
        if(n % i == 0) return false;
    return true;
}

// get the number of divisors for n

int number_of_divisors(ll n){
    int divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) divisors += 2;
    return divisors + (sqrt(n) == (int)sqrt(n));
}

// get Summation of divisors for n

ll sum_of_divisors(ll n){
    ll sum_divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) sum_divisors += ((n / i) + i);
    ll sq = sqrt(n);
    return sum_divisors + (sq * sq == n ? sq : 0);
}

// get vector with the divisors for n

vector < ll > Get_Divisors(ll n){
    vector < ll > divisors;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) divisors.push_back(i), divisors.push_back(n / i);
    if(sqrt(n) == int(sqrt(n))) divisors.push_back(sqrt(n));
    return divisors;
}

// print all permutation of an array

void Print_Permutation(vector < int >& nums){
    sort(all(nums));
    do {
        for(auto& i : nums)
            cout << i << " ";
        cout << "\n";
    } while(next_permutation(nums.begin(), nums.end()));
}

// print all permutation of a string

void Print_Permutation(string s){
    sort(all(s));
    do {
        cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));
}

// get the summation between two numbers or the summation between 1 and n

ll Summation(ll r, ll l = 0){
    if(l > r) swap(l, r);
    return (r * (r + 1) / 2) - (l * (l - 1) / 2);
}

// Get how many number divisable by c between a and b

ll how_many_divisors(ll a, ll b, ll c){
    return (b / c) - ((a - 1) / c);
}

// Get summation of numbers divisable by c between a and b

ll Summation_of_Devisors(ll a, ll b, ll c){
    ll right = Summation(b / c);
    ll left = Summation((a - 1) / c);
    return (right - left) * c;
}

// get logb(a)

double get_log(ll a, int b){
    return log(a) / log(b);
}

// Check if number power of another or not

bool is_power(ll number, int base = 2){
    return (get_log(number, base) - (ll) get_log(number, base) <= EPS);
}

// Distination Between two points

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Check if it valid triangle with 3 length sides

bool is_triangle(ll a, ll b, ll c){
    return (a + b > c) && (a + c > b) && (b + c > a) && (a && b && c);
}

// Get Slope of two points

double slope(double x1, double y1, double x2, double y2){
    if(x2 == x1) return 0;
    return (y2 - y1) / (x2 - x1);
}

// Check if three points in the same line

bool is_same_line(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
}

// Check if is perfect square

bool is_perfect_square(ll n){
    ll sq = sqrt(n);
    return sq * sq == n;
}

// Convert Decimal to any base

string decimal_to_any_base(ll decimal, ll base){
    if(decimal == 0) return "0";
    string num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;
    do{
        result.push_back(num[decimal % base]);
        decimal /= base;
    }while(decimal != 0);
    return string(result.rbegin(), result.rend());
}

// Convert any base to decimal

ll  any_base_to_decimal(string str, int base) {
    auto val = [](char c){
        return (c >= '0' && c <= '9' ? (int) c - '0' : (int) c - 'A' + 10);
    };
    ll len = sz(str), power = 1, num = 0, i;
    for (i = len - 1; i >= 0; i--) {
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}



// seive primes

Seive(int n){
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i <= sqrt(n); i++)
        if(is_prime[i])
            for(ll j = i * i; j <= n; j += i) is_prime[j] = false;
}


// fast power function
ll fpow(ll base, ll ex){
    ll res = 1;

    while (ex){
        if(ex & 1)
            res *= base;
        base *= base;
        ex >>= 1;
    }
    return res;
}

// Mod inverse
void mul(ll& a, ll b, ll mod = 1e9 + 7){
    a = ((a % mod) * (b % mod)) % mod;
}


ll fast_pow(ll b, ll e, ll mod){
    ll power = 1;
    while(e){
        if(e & 1) mul(power, b, mod);
        e >>= 1;
        mul(b, b, mod);
    }
    return power % mod;
}

ll modInv(ll n){
    return fast_pow(n, Mod - 2, Mod);
}

// sieve factorization
ll N = 4e6;
vector < int > factors(N + 1 , 2);

void factorization(){
    factors[1] = 1 , factors[0] = 0;
    for(ll i = 2; i<= N; i++){
        for(ll j = i + i; j <=N; j += i){
            factors[j]++;
        }
    }
}

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
