#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "insert n, m";
    cin >> n >> m;

    int adj_matrix[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "insert u, v";
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    return 0;
}
