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
ll lcm(ll a, ll b) {return a*(b/gcd(a, b));}

vct my_ls;

int main() {
    ll T, num, den, lcmi, N;
    string my_str;
    cin >> T;
    for(ll i = 0; i < T; i++) {
        my_ls.clear();
        den = 0; lcmi = -1;
        ll P; cin >> P;
        while(P--) {
            cin >> N;
            my_ls.pb(N);
            if(my_ls.size() > 1)
                lcmi = lcm(lcmi, N);
            else lcmi = my_ls[0];
        }
        num = lcmi * my_ls.size();
        for(ll j = 0; j < my_ls.size(); j++)
            den += lcmi/my_ls[j];
        ll gcdi = gcd(max(num, den), min(den, num));
        printf("Case %ld: %ld/%ld\n", i+1, num/gcdi, den/gcdi);
    } return 0;
}
