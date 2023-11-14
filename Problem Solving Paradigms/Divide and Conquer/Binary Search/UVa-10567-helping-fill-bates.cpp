/* Resolvi este problema criando um vector de vector que guarda na posição[letra]'..
os índices sempre que [letra] aparece no texto.
Depois, como o vector em [letra] é ordenado naturalmente pela ordem em que eles aparecem,
resta fazer uma busca binária por toda a palavra atualizando a posição mínima possível 
de cada letra e fazendo tal busca por upper_bound. */

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

bool is_subset(vvct &data, string &beta, vct &sol) {
 	ll last_i;
 	vct::iterator low;

 	last_i = -1;
 	for(ll i = 0; i < beta.size(); i++) {
 			low = upb(all(data[beta[i]]), last_i);
			if(low != data[beta[i]].end()) {
 				last_i = data.at(beta[i]).at(low - data.at(beta[i]).begin());
 				if(i == 0 || i + 1 == beta.size())
 					sol.pb(data.at(beta[i]).at(low - data.at(beta[i]).begin()));
 			}
 			else return false;
 		}
 		return true;
 }

int main() { 
	vct sol; vvct data; data.resize(1 << 8);
	string alpha, beta;
	ll Q;
		
	cin >> alpha;
	for(ll i = 0; i < alpha.size(); i++) 
		data.at(alpha[i]).pb(i);	
	cin >> Q;
	while(Q--) {
		cin >> beta;
		if(is_subset(data, beta, sol)) {
			printf("Matched ");
			printf("%ld %ld\n", sol.front(), sol.back());
		}
		else
			printf("Not matched\n");
		beta.clear(); sol.clear();
	}
	return 0;
}
