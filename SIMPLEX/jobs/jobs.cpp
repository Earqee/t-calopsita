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

        long N, K;
        cin >> N >> K;
        long T[N];
        for(long i=0;i<N;i++)
            cin >> T[i];

        IloArray<IloBoolVarArray> x(env, N);
        IloIntVar z(env, 0, IloInfinity);


        for(long i=0; i<N;i++)
            x[i]=IloBoolVarArray(env, K);

        #define J (N)

        for(long j=0;j<J;j++) {
            IloExpr expr(env);
            for(long k=0;k<K;k++)
                expr += x[j][k];
            model.add(expr == 1);
        }

        for(long k=0;k<K;k++) {
            IloExpr expr(env);
            for(long j=0;j<J;j++)
                expr = T[j]*x[j][k];
            model.add(expr <= z);
        }

        model.add(IloMinimize(env, z));

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


