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

        long N, M, in, out, weight;
        cin >> N;
        #define MAX_T (1e6)
        long long W[N][N] = {(long)MAX_T};
        for(long i=0;i<M;i++) {
            cin >> in >> out >> weight;
            W[in][out] = weight;
        }

        IloIntVarArray u(env, N, 0, IloInfinity);
        IloArray<IloBoolVarArray> x(env, N);
        for(long i=0; i<N; i++)
            x[i]=IloBoolVarArray(env, N);


        for(long j=0;j<N;j++) {
            IloExpr expr(env);
            for(long i=0; i<N;i++)
                if(i!=j)
                    expr+=x[i][j];
            model.add(expr == 1);
        }

        for(long i=0;i<N;i++) {
            IloExpr expr(env);
            for(long j=0; j<N;j++)
                if(i!=j)
                    expr+=x[i][j];
            model.add(expr == 1);
        }

        for(long i=1; i<N;i++) {
            for(long j=1; j<N;j++)
                model.add(u[i]-u[j]+N*x[i][j] <= N-1);
        }

        for(long i=1;i<N;i++)
            model.add(u[i]<=N-1);

        IloExpr obj;
        for(long i=0;i<N;i++) {
            IloExpr expr(env);
            for(long j=0;j<N;j++)
                if(i!=j)
                    expr+=W[i][j]*x[i][j];
            obj += expr;
        }
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


