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

        long N;
        cin >> N;
        double W[N];
        for(long i=0;i<N;i++)
            cin >> W[i];

        IloBoolVarArray x(env, N);
        IloArray<IloBoolVarArray> y(env, N);
        for(long i=0; i<N; i++)
            y[i]=IloBoolVarArray(env, N);

        #define B (N)

        for(long j=0;j<B;j++) {
            IloExpr expr(env);
            for(long i=0;i<N;i++)
                expr += W[i]*y[i][j];
            model.add(expr <= x[j]);
        }

        for(long i=0;i<N;i++) {
            IloExpr expr(env);
            for(long j=0;j<B;j++)
                expr += y[i][j];
            model.add(expr == 1);
        }

        IloExpr obj;
        for(long i=0;i<N;i++)
            obj+=x[i];
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


