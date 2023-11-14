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

vct arr(5);

bool test(ll k, ll res) {
    if(k == 4) {
        if(res == 23)
            return true;
        return false;
    }
    if(k+1 < 5)
        return test(k+1, res+arr[k+1]) || test(k+1, res-arr[k+1]) ||
            test(k+1, res*arr[k+1]);
}

int main() {
    string str;
    while(getline(cin, str)) {
        istringstream ss(str);
        for(ll i=0; i<5; i++)
            ss >> arr[i];
        if(!arr[0]) return 0;
        sort(all(arr));
        bool possible = false;
        do {
            possible |= test(0, arr[0]);
        } while(next_permutation(all(arr)));
        if(possible)
            cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}
