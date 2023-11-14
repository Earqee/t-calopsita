#include <bits/stdc++.h>
using namespace std;

typedef vector<long> v1ct;
typedef vector<v1ct> v2ct;
typedef vector<v2ct> v3ct;
typedef vector<v3ct> v4ct;
typedef vector<v4ct> v5ct;
typedef vector<v5ct> v6ct;

void ComputeMinimumChangeBetweenEachPairOfNodes(v1ct tree, v1ct parent, long N, long M, v6ct E, v2ct costChanging) {
    vector<vector<long> > minimumCostChanging;

    minimumCostChanging.resize(N+1);
    for(long i=1; i<=N; i++)
        minimumCostChanging[i].resize(M+1);
    //CC[1,1] = 0;
    minimumCostChanging[1][1] = 0;
    //CC[i,1] = i
    for(long i=2; i<=N; i++)
        minimumCostChanging[i][1] = i;
    //CC[1,j] = j
    for(long j=2; j<=M; j++)
        minimumCostChanging[1][j] = j;
    for(long i=2; i<=N; i++)
        for(long j=2; j<=M; j++) {
            minimumCostChanging[i][j] = (long)1e6;
            for(long s=i; s != -1; s = parent[s])
                for(long t=j; t!= -1; t = parent[t])
                    minimumCostChanging[i][j] =
                        min(
                            minimumCostChanging[i][j],
                            minimumCostChanging[s][j] + E[s][parent[i]][i-1][t][parent[j]][j-1] - costChanging[tree[s]][tree[t]]
                           );
            minimumCostChanging[i][j] += costChanging[tree[i]][tree[j]];
        }
}

int main() {

    return 0;
}
