// grok6-part2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N <= 0) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> price(N + 1);
    for (int i = 1; i <= N; i++) cin >> price[i];

    int M;
    cin >> M;

    vector<vector<int>> g(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        // защита от некорректных вершин во входе
        if (u < 1 || u > N || v < 1 || v > N) continue;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(N + 1, INF);

    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) continue;

        for (int to : g[v]) {
            long long cost = price[v];        // платим бак в текущем городе v
            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                pq.push({ dist[to], to });
            }
        }
    }

    cout << (dist[N] == INF ? -1 : dist[N]) << "\n";
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
