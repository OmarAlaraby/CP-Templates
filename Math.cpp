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
// #define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define dl "\n"
#define ordered_set tree<int ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>
#define int long long
#define all(v) v.begin(), v.end()
#define INF 2000000000000000000
#define Mod 998244353

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define Mod 1000000007

// get the number of perfect square between l and r

int num_of_pref_squares(int l, int r){
    return ((int)(sqrtl(r)) - ceil(sqrtl(l)) + 1);
}



int GCD(int a, int b){
    return (!b ? a : GCD(b, a % b));
}

// least common multiplication between two numbers

int LCM(int a, int b){
    return a / GCD(a, b) * b;
}

// Get vector with the prime factors of number

vector < int > prime_factorization(int n){
    vector < int > factors;
    while(n % 2 == 0) factors.push_back(2), n /= 2;
    for(int i = 3; i <= sqrt(n); i += 2)
        while(n % i == 0) factors.push_back(i), n /= i;
    if(n > 2) factors.push_back(n);
    return factors;
}

//Get the factorst of the a number

vector < int > factors(int n){
    vector < int > factors;
    while(n % 2 == 0) factors.push_back(2), n /= 2;
    for(int i = 3; i <= sqrt(n); i++)
        while(n % i == 0) factors.push_back(i), n /= i;
    if(n > 2) factors.push_back(n);
    return factors;
}

// nCr with Mod using dp

int nCr(int n, int r){

    if(n == 0 or r < 0)
        return r == 0;

    int &ret = dp[n][r];
    if(~ret)
        return ret % Mod;

    return ret = (nCr(n - 1, r - 1) % Mod + nCr(n - 1 , r) % Mod) % Mod;
}

// Combination

int nCr(int n, int r){
    if(r > n) return 0;
    int p = 1, k = 1;
    if (n - r < r) r = n - r;
    // condition for minimum choose
    if(n < 1) return 0;
    while (r > 0){
        p *= n, k *= r;
        int m = __gcd(p, k);
        p /= m, k /= m, n--, r--;
    }
    return p;
}

// Permutation

int nPr(int n, int r){
    if(r > n) return 0;
    int npr = 1;
    while(r-- > 0)
        npr *= n--;
    return npr;
}

// get a mod for big int

int Big_Mod(string s, int mod){
    int res = 0;
    for(auto& c : s)
        res = (res * 10 + (c - '0')) % mod;
    return res;
}

// add two number and take mod for them

void add(ll& a, int b, int mod = 1e9 + 7){
    a += b;
    if(a >= mod)
        a -= mod;
}

// multiply two number and take mod for them

void mul(ll& a, int b, int mod = 1e9 + 7){
    a = ((a % mod) * (b % mod)) % mod;
}

// b power e in O(log(n))

int fast_pow(int b, int e){
    int power = 1;
    while(e){
        if(e & 1) power *= b;
        e >>= 1;
        b *= b;
    }
    return power;
}

// b power e % mod in O(log(e))

int fast_pow(int b, int e, int mod){
    int power = 1;
    while(e){
        if(e & 1) mul(power, b, mod);
        e >>= 1;
        mul(b, b, mod);
    }
    return power % mod;
}

// b multiply e % mod in O(log(e))

int fast_mul(int b, int e, int mod){
    int mult = 0;
    while(e){
        if(e & 1) add(mult, b, mod);
        e >>= 1;
        add(b, b, mod);
    }
    return mult % mod;
}

// Check if number is prime or not

bool is_prime(int n){
    if(n < 2 || (n % 2 == 0 && n != 2)) return false;
    for(int i = 3; i <= sqrt(n); i += 2)
        if(n % i == 0) return false;
    return true;
}

// get the number of divisors for n

int number_of_divisors(int n){
    int divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) divisors += 2;
    return divisors + (sqrt(n) == (int)sqrt(n));
}

// get Summation of divisors for n

int sum_of_divisors(int n){
    int sum_divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) sum_divisors += ((n / i) + i);
    int sq = sqrt(n);
    return sum_divisors + (sq * sq == n ? sq : 0);
}

// get vector with the divisors for n

vector < int > Get_Divisors(int n){
    vector < int > divisors;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) divisors.push_back(i), divisors.push_back(n / i);
    if(sqrt(n) == int(sqrt(n))) divisors.push_back(sqrt(n));
    return divisors;
}

// print aint permutation of an array

void Print_Permutation(vector < int >& nums){
    sort(all(nums));
    do {
        for(auto& i : nums)
            cout << i << " ";
        cout << "\n";
    } while(next_permutation(nums.begin(), nums.end()));
}

// print aint permutation of a string

void Print_Permutation(string s){
    sort(all(s));
    do {
        cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));
}

// get the summation between two numbers or the summation between 1 and n

int Summation(int r, int l = 0){
    if(l > r) swap(l, r);
    return (r * (r + 1) / 2) - (l * (l - 1) / 2);
}

// Get how many number divisable by c between a and b

int how_many_divisors(int a, int b, int c){
    return (b / c) - ((a - 1) / c);
}

// Get summation of numbers divisable by c between a and b

int Summation_of_Devisors(int a, int b, int c){
    int right = Summation(b / c);
    int left = Summation((a - 1) / c);
    return (right - left) * c;
}

// get logb(a)

double get_log(int a, int b){
    return log(a) / log(b);
}

// Check if number power of another or not

bool is_power(int number, int base = 2){
    return (get_log(number, base) - (ll) get_log(number, base) <= EPS);
}

// Distination Between two points

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Check if it valid triangle with 3 length sides

bool is_triangle(int a, int b, int c){
    return (a + b > c) && (a + c > b) && (b + c > a) && (a && b && c);
}

// Get Slope of two points

double slope(double x1, double y1, double x2, double y2){
    if(x2 == x1) return 0;
    return (y2 - y1) / (x2 - x1);
}

// Check if three points in the same line

bool is_same_line(int x1, int y1, int x2, int y2, int x3, int y3){
    return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
}

// Check if is perfect square

bool is_perfect_square(int n){
    int sq = sqrt(n);
    return sq * sq == n;
}

// Convert Decimal to any base

string decimal_to_any_base(int decimal, int base){
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

int  any_base_to_decimal(string str, int base) {
    auto val = [](char c){
        return (c >= '0' && c <= '9' ? (int) c - '0' : (int) c - 'A' + 10);
    };
    int len = sz(str), power = 1, num = 0, i;
    for (i = len - 1; i >= 0; i--) {
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}



// seive primes
vector < int > is_prime;
void Seive(int n){
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= sqrt(n); i++)
        if(is_prime[i])
            for(int j = i * i; j <= n; j += i) is_prime[j] = false;
}


// fast power function

int fpow(int base, int ex){
    int res = 1;

    while (ex){
        if(ex & 1)
            res *= base;
        base *= base;
        ex >>= 1;
    }
    return res;
}



// Mod inverse

void mul(ll& a, int b, int mod = 1e9 + 7){
    a = ((a % mod) * (b % mod)) % mod;
}


int fast_pow(int b, int e, int mod){
    int power = 1;
    while(e){
        if(e & 1) mul(power, b, mod);
        e >>= 1;
        mul(b, b, mod);
    }
    return power % mod;
}

int modInv(int n){
    return fast_pow(n, Mod - 2, Mod);
}





// sieve factorization
int N = 4e6;
vector < int > factors(N + 1 , 2);

void factorization(){
    factors[1] = 1 , factors[0] = 0;
    for(int i = 2; i<= N; i++){
        for(int j = i + i; j <=N; j += i){
            factors[j]++;
        }
    }
}


// Extended Euclidean Algorithm
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int ret = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return ret;
}

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