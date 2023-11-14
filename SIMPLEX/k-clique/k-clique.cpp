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

        #define V (N)
        #define cliques (N)

        // (1)
        // Each vertex in at least 1 clique
        for(long i=0; i<V; i++) {
            IloExpr expr(env);
            for(long c=0;c<cliques;c++)
                expr += y[i][cliques];
            model.add(expr >= 1);
        }

        // (2)
        // Must be in a different clique if there's
        // no edge between them
        for(long i=0;i<V;i++)
            for(long j=i+1;j<V;j++)
                for(long k=0; k<cliques; k++)
                    if(!P[i][j])
                        model.add(y[i][k] + y[j][k] <= 1);

        // (3)
        // Belongs to clique number j implies clique j existence
        for(long j=0;j<V;j++)
            for(long i=0;i<cliques;i++)
                model.add(y[i][j]<=x[j]);

        IloExpr obj;
        for(long j=0;j<cliques;j++)
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


