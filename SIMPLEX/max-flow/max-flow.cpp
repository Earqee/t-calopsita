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

        long N, M, S, T;
        cin >> N >> M >> S >> T;
        long C[N][M] = {0}, in, out;
        for(long j=0;j<M;j++)
            cin >> in >> out >> C[in][out];

        IloArray<IloIntVarArray> x(env, N);
        for(long i=0; i<N; i++)
            x[i]=IloIntVarArray(env, N, 0, IloInfinity);

        for(long i=0;i<N;i++) {
            if(i == S || i == T)
                continue;
            IloExpr inf(env), outf(env);
            for(long k=0; k<N;k++)
                outf += x[i][k];
            for(long k=0; k<N;k++)
                inf += x[k][i];
            model.add(inf == outf);
        }

        for(long i=0;i<N;i++)
            for(long j=0;j<N;j++)
                model.add(x[i][j] <= C[i][j]);

        IloExpr obj(env);
        for(long i=0;i<N;i++)
            obj += x[S][i];
        model.add(IloMaximize(env, obj));

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


