#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) {
    visited[node] = true;
    cout << "Відвідали вершину: " << node << endl;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int v, e;
    cout << "Введіть кількість вершин і ребер: ";
    cin >> v >> e;

    cout << "Введіть пари вершин для кожного ребра:\n";
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // якщо граф орієнтований — прибрати цей рядок
    }

    dfs(0); // Починаємо з вершини 0
    return 0;
}
