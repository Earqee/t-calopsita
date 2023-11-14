//Count the number of negatives and zeros until that point with Fenwick Tree (frequency table)
//If the count of zeros until the query > 0, answer is zero
//Else if number of negatives is odd the answer is negative, Else positive


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

class FenwickTree {
private:
    vct ft;
public:
    FenwickTree(ll N) { ft.assign(N+1, 0); }
    ll RSQ(ll b) {
        ll sum = 0;
        for(; b; b -= (b & -b)) sum += ft[b];
        return sum;
    }
    ll RSQ(ll a, ll b) {
        return RSQ(b) - (a == 0 ? 0 : RSQ(a-1));
    }
    ll adjust(ll idx, ll val) {
        for(; idx < ft.size(); idx += (idx & -idx)) ft[idx] += val;
    }
};

int main() {
    string my_str;
    ll N, K, I, V, num;
    while(cin >> N >> K) {
        vct my_arr(N+1);
        FenwickTree zer(N+1);
        FenwickTree neg(N+1);
        for(ll i = 1; i <= N; i++) {
            cin >> num;
            my_arr[i] = num;
            if(num == 0) zer.adjust(i, 1);
            else if(num < 0) neg.adjust(i, 1);
        }
        for(ll i = 0; i < K; i++) {
            cin >> my_str >> I >> V;
            if(my_str == "C") {
                if(V == 0 && my_arr[I] != 0) {
                    if(my_arr[I] < 0)
                        neg.adjust(I, -1);
                    zer.adjust(I, 1);
                } else if(V < 0 && my_arr[I] >= 0) {
                    if(my_arr[I] == 0)
                        zer.adjust(I, -1);
                    else
                        neg.adjust(I, 1);
                } else if(V > 0 && my_arr[I] <= 0) {
                    if(my_arr[I] == 0)
                        zer.adjust(I, -1);
                    else
                        neg.adjust(I, -1);
                }
                my_arr[I] = V;
            } else {
                ll zeros = zer.RSQ(I, V);
                ll negati = neg.RSQ(I, V);
                if(zeros) printf("0");
                else printf("%c", negati % 2 ? '-' : '+');
            }
        }
        cout << endl;
    } return 0;
}


