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
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));}

vct divis;

int main() {
    ll N;
    while(cin >> N, N != 0) {
        divis.clear();
        ll sqrtN = sqrt(N);
        for(ll i = 1; i <= sqrtN; i++) {
            if(N % i == 0) {
                divis.pb(i);
                if(i != N/i) divis.pb(N/i);
            }
        }
        ll count = 1; //(N, N)
        for(ll i = 0; i < divis.size()-1; i++)
            for(ll j = i+1; j < divis.size(); j++)
                if(lcm(divis[i], divis[j]) == N)
                    count++;
        printf("%ld %ld\n", N, count);
    } return 0;
}

