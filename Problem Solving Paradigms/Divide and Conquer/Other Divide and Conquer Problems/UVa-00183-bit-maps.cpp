#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>

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
typedef bitset<1 << 8> VL;
  
string sol, ans;

char **M;

bool is_that(char ch, ll i_L, ll f_L, ll i_C, ll f_C) {
    for(ll i = i_L; i <= f_L; i++)
        for(ll j = i_C; j <= f_C; j++)
            if(M[i][j] != ch) return false;
    return true;
}

void conquer(ll i_L, ll f_L, ll i_C, ll f_C) {
    if(i_L <= f_L && i_C <= f_C) {
        if(is_that('0', i_L, f_L, i_C, f_C)) {
            sol.pb('0');
        } else if(is_that('1', i_L, f_L, i_C, f_C)) {
            sol.pb('1');
        } else {
            sol.pb('D'); 
            ll mid_L = (i_L + f_L)/2;
            ll mid_C = (i_C + f_C)/2;
            conquer(i_L, mid_L, i_C, mid_C);
            conquer(i_L, mid_L, mid_C + 1, f_C);
            conquer(mid_L + 1, f_L, i_C, mid_C);
            conquer(mid_L + 1, f_L, mid_C + 1, f_C);
        }
    } return;
}

void reverse_conquer(ll i_L, ll f_L, ll i_C, ll f_C) {
    if(i_L <= f_L && i_C <= f_C && ans.size()) {
        if(ans[0] == 'D') {
            ans.erase(ans.begin());
            ll mid_L = (i_L + f_L)/2;
            ll mid_C = (i_C + f_C)/2;
            reverse_conquer(i_L, mid_L, i_C, mid_C);
            reverse_conquer(i_L, mid_L, mid_C + 1, f_C);
            reverse_conquer(mid_L + 1, f_L, i_C, mid_C);
            reverse_conquer(mid_L + 1, f_L, mid_C + 1, f_C);                
        } else {
            for(ll i = i_L; i <= f_L; i++) 
                for(ll j = i_C; j <= f_C; j++) 
                    M[i][j] = ans[0];                 
            ans.erase(ans.begin());
        }
    } 
    return;
}

int main() {
    ll count, P, Q; string cmd; 

    while(cin >> cmd, cmd != "#")
    {
        cin >> P >> Q; getchar();
        cout << (cmd == "B" ? "D" : "B") << setw(4) << right << P <<
        setw(4) << right << Q << endl;
        count = 0;         

        M = new char*[P + 1];
            for(ll i = 0; i < P; i++)
                M[i] = new char[Q + 1];

        if(cmd == "B") {
            for(ll i = 0; i < P; i++)
                for(ll j = 0; j < Q; j++)
                    cin >> M[i][j];
            
            conquer(0, P - 1, 0, Q - 1);
            while(count < sol.size()) {
                cout << sol.at(count++);
                if(!(count % 50)) cout << endl;
            }             
        } else {
            cin >> ans;            
            reverse_conquer(0, P - 1, 0, Q - 1);
            for(ll i = 0; i < P; i++)
                for(ll j = 0; j < Q; j++) {
                    cout << M[i][j];
                    if(!(++count % 50)) cout << endl;
                }
        }         
        if(count % 50) cout << endl; 
        sol.clear(); ans.clear(); delete[] M;       
    } 
    return 0;
}