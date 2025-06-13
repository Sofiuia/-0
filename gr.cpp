#include <iostream>
#include <vector>
using namespace std;

// Матриця суміжності для ненапрямленого графа
void addEdgeMatrix(vector<vector<int>> &mat, int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1; // для ненапрямленого графа
}

void displayMatrix(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

// Список суміжності для ненапрямленого графа
void addEdgeList(vector<vector<int>> &adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void displayAdjList(const vector<vector<int>> &adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << i << ": ";
        for (int val : adj[i])
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    int V = 4;
    
    cout << "Adjacency Matrix:\n";
    vector<vector<int>> mat(V, vector<int>(V, 0));
    addEdgeMatrix(mat, 0, 1);
    addEdgeMatrix(mat, 0, 2);
    addEdgeMatrix(mat, 1, 2);
    addEdgeMatrix(mat, 2, 3);
    displayMatrix(mat);
    
    cout << "\nAdjacency List:\n";
    vector<vector<int>> adj(V);
    addEdgeList(adj, 0, 1);
    addEdgeList(adj, 0, 2);
    addEdgeList(adj, 1, 2);
    addEdgeList(adj, 2, 3);
    displayAdjList(adj);
    
    return 0;
}
