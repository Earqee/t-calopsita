#include <bits/stdc++.h>
#include <ilcplex/ilocplex.h>
#define E 1e-7
using namespace std;
ILOSTLBEGIN

int main() {

    try {
        IloEnv env;
        IloModel model(env);
        IloCplex blackBox(model);

        long N, M;
        cin >> N >> M;
        long K[N][M] = {0}, in, out;
        for(long j=0;j<M;j++) {
            cin >> in >> out;
            K[in][out] = 1;
        }

        IloBoolVarArray x(env, N);
        for(long i=0; i<N; i++) {
            IloExpr expr(env);
            for(long j=i+1; j<N; j++) {
                if(i == j) continue;
                if(K[i][j])
                    model.add(x[i] + x[j] >= 1);
            }
        }

        IloExpr obj;
        for(long i=0; i<N; i++)
            obj += x[i];
        model.add(IloMinimize(env, obj));

        if(blackBox.solve() == IloTrue)
            cout << "Opt: " << blackBox.getObjValue() << endl;
        else
            printf("No solution.");
        env.end();
    }
    catch(IloException &e) {
        cerr << "Exception: " << e << endl;
    }

    return 0;
}


