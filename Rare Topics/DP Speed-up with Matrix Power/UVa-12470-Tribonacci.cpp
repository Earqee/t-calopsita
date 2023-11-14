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

#define MOD 1000000009

ll A[3][3] = { {0,0,0}, {1,0,0}, {2,0,0} };
ll B[3][3] = { {0,1,0} ,{0,0,1}, {1,1,1} };

class Matrix {
private:
public:
    ll M[3][3];
    Matrix(bool null) {
        for(ll i = 0; i < 3; i++)
            for(ll j = 0; j < 3; j++) {
                if(!null)
                    this->M[i][j] = B[i][j];
                else this->M[i][j] = 0;
            }
    }
    void Mult(ll (&C)[3][3]) {
        Matrix *result = new Matrix(true);
        for(ll i = 0; i < 3; i++)
            for(ll j = 0; j < 3; j++) {
                for(ll k = 0; k < 3; k++)
                    result->M[i][j] += (this->M[i][k] * C[k][j]) % MOD;
                result->M[i][j] %= MOD;
            }

        for(ll i = 0; i < 3; i++)
            for(ll j = 0; j < 3; j++)
                this->M[i][j] = result->M[i][j];
    }
    void fastExp(ll N) {
        if(N <= 1)
            return;
        fastExp(N/2);
        Mult(this->M);
        if(N & 1)
            Mult(B);
    }
};

int main() {
    ll N;
    while(cin >> N, N != 0) {
        Matrix *answer = new Matrix(false);
        answer->fastExp(N-1);
        answer->Mult(A);
        switch(N) {
            case 1: cout << 0 ; break;
            case 2: cout << 1 ; break;
            default: cout << answer->M[0][0];
        }
        cout << endl;
        free(answer);
    }
    return 0;
}
