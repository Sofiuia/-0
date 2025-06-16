#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // Граф: кожен номер — це "людина", а список — її друзі
    vector<vector<int>> graph = {
        {1, 2},     // 0 спілкується з 1 і 2
        {0, 2, 3},  // 1 з 0, 2, 3
        {0, 1, 4},  // 2 з 0, 1, 4
        {1, 4},     // 3 з 1, 4
        {2, 3}      // 4 з 2, 3
    };

    int n = graph.size();           // Скільки всього "людей"
    vector<bool> visited(n, false); // Хто вже відвіданий
    queue<int> q;                   // Черга
    q.push(0);                      // Починаємо з "людини 0"
    visited[0] = true;

    while (!q.empty()) {
        int person = q.front(); q.pop(); // Беремо наступного з черги
        cout << person << " ";           // Виводимо його номер

        // Додаємо друзів цієї людини в чергу
        for (int friend_id : graph[person]) {
            if (!visited[friend_id]) {
                visited[friend_id] = true; // Відмічаємо як відвіданого
                q.push(friend_id);
            }
        }
    }

    return 0;
}
