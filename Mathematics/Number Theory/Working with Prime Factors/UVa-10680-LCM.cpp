//Hello!
//If you're having problems tring to solve this problem, see this:
//https://math.stackexchange.com/questions/659799/lcm-of-first-n-natural-numbers
//If you know how to proof any of theses LCM(1..n) algorithms and want to share it
//please email me tjss@ic.ufal.br, thank you

#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define mp make_pair
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define e_min min_element
#define e_max max_element
#define bin_s binary_search
#define ff find

using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

#define MAX ((ll)1e6+1)
#define ZER ((ll)1e10)

ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a, b));}

VL sieve_ls;
vct primes, power, LCM;

void Sieve() {
    sieve_ls.set(); power.assign(MAX, 1);
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < MAX; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < MAX; j+=i)
                sieve_ls[j] = 0;
            for(ll j = i; j < MAX; j*=i)
                power[j] = i;
            primes.pb(i);
        }
    } return;
}

void Calc() {
    LCM.resize(MAX); LCM[1] = 1;
    //Use DP and the property of
    //Modular arithmetic: (a*b*...*z)%N = ((a%10)*(b%10)*...*(z*10))%N
    for(ll i = 1; i < MAX - 1; i++)
        LCM[i+1] = (power[i+1] * LCM[i]) % ZER;
    return;
}

int main() {
    Sieve(), Calc();
    ll N;
    while(cin >> N, N != 0) {
        while(LCM[N] % 10 == 0) LCM[N] /= 10;
        printf("%lld\n", LCM[N] % 10);
    } return 0;
}
