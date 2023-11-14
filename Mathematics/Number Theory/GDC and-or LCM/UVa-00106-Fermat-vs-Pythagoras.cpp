//Euclid's formula
//a = m^2-n^2, b = 2mn, c = m^2+n^2
//a < N and c < N implies m^2-n^2 <= m^2+n^2
//which implies 2m^2<2N that implies m <= sqrt(N)
//m <= sqrt(N) implies n <= sqrt(N - sqrt(N))

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
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*(b/gcd(b, a%b));}

ll N, counter, tuples;
vct used;

void Euclid() {
    ll sqrtN = sqrt(N);
    ll sqrt2N = sqrt(N - sqrtN);
    for(ll n = 1; n <= sqrt2N; n++) {
        for(ll m = n+1; m <= sqrtN; m++) {
            ll a = m*m-n*n, b = 2*m*n, c = m*m+n*n;
            if(c > N) break;
            if(gcd(c, lcm(a,b)) == 1) {
                tuples++;
                for(ll p = 1; p*c <= N; p++) {
                    if(!used[p*a]) used[p*a] = 1, counter++;
                    if(!used[p*b]) used[p*b] = 1, counter++;
                    if(!used[p*c]) used[p*c] = 1, counter++;
                }
            }
        }
    } return;
}

int main() {
    while(cin >> N) {
        counter = tuples = 0;
        used.assign(N+1, 0);        
        Euclid();
        printf("%ld %ld\n", tuples, N - counter);
    }
    return 0;
}

