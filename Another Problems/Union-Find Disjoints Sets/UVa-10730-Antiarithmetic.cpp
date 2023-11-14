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

int main() {
    ll N;
    vct arr(10010), present(10010);
    while(cin >> N, N != 0) {
        getchar();
        for(ll i = 0; i < N; i++)
            present[i] = 0;
        for(ll i = 0; i < N; i++) {
            cin >> arr[i];
            present[arr[i]]++;
        }
        bool antiarithmetic = true;
        for(ll i = 0; i < N && antiarithmetic; i++) {
            present[arr[i]]--;
            for(ll j = i+1; j < N; j++) {
                present[arr[j]]--;
                ll diff = arr[j] - arr[i];
                if(arr[j] + diff >= 0 && arr[j] + diff < N &&
                        present[arr[j] + diff])
                    antiarithmetic = false;
                if(arr[j] - diff >= 0 && arr[j] - diff < N &&
                        present[arr[j] - diff])
                    antiarithmetic = false;
            }
            for(ll j = i+1; j < N; j++)
                present[arr[j]]++;
        }

        if(antiarithmetic)
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
    return 0;
}
