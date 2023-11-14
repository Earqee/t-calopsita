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

ll gdc(ll a, ll b) {return b==0?a:gdc(b, a%b);}

vct my_ls;

int main() {
    ll T; string my_str;
    cin >> T; getchar();
    while(T--) {
        my_ls.clear();
        getline(cin, my_str);
        stringstream my_ss(my_str);
        ll num, gdci;
        while(my_ss >> num)
            my_ls.pb(num);
        gdci = 1;
        for(ll i = 0; i < my_ls.size(); i++)
            for(ll j = i+1; j < my_ls.size(); j++)
                gdci = max(gdci, gdc(max(my_ls[i], my_ls[j]), min(my_ls[i], my_ls[j])));
        printf("%ld\n", gdci);
    }
}
