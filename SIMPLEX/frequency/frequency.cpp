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
        IloArray<IloBoolVarArray> y(env, N);
        for(long i=0;i<N;i++)
            y[i]=IloBoolVarArray(env, N);

        #define ant N
        #define color N

        for(long i=0; i<ant; i++) {
            IloExpr expr(env);
            for(long j=0;j<color;j++)
                expr += y[i][j];
            model.add(expr == 1);
        }

        for(long i=0;i<ant;i++)
            for(long j=i+1;j<ant;j++)
                for(long k=0; k<color; k++)
                    if(P[i][j])
                        model.add(y[i][k] + y[j][k] <= 1);

        for(long j=0;j<color;j++)
            for(long i=0;i<ant;i++)
                model.add(y[i][j]<=x[j]);

        IloExpr obj;
        for(long j=0;j<color;j++)
            obj+=x[j];
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


