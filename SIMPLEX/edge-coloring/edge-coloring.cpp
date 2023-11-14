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

        long N, M, in, out;
        cin >> N >> M;
        long P[N][M] = {0};
        for(long j=0;j<M;j++) {
            cin >> in >> out;
            P[in][out]=P[out][in]=1;
        }

        IloBoolVarArray x(env, N);
        IloArray<IloArray<IloBoolVarArray> > y(env, N);
        for(long i=0;i<N;i++) {
            y[i]=IloArray<IloBoolVarArray>(env, N);
            for(long j=0;j<N;j++)
                y[i][j]=IloBoolVarArray(env, M+1);
        }

        #define V (N)
        #define color (M+1)

        for(long i=0;i<V;i++) {
            for(long j=i+1;j<V;j++) {
                IloExpr expr(env);
                for(long c=0;c<color;c++)
                    expr += y[i][j][c];
                model.add(expr == 1);
            }
        }

        for(long i=0;i<V;i++)
            for(long j=i+1;j<V;j++)
                for(long k=j+1; k<V; k++)
                    for(long c=0; c<color; c++)
                        if(P[i][j])
                            model.add(y[i][j][c] + y[i][k][c] <= 1);

        for(long c=0;c<color;c++)
            for(long i=0;i<V;i++)
                for(long j=i+1;j<V;j++)
                    model.add(y[i][j][c]<=x[c]);

        IloExpr obj;
        for(long c=0;c<color;c++)
            obj+=x[c]*c;
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


