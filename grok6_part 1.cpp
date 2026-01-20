// grok6_part 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, F;
    cin >> N >> S >> F;

    // Проверяем базовые границы (по условию S,F должны быть 1..N)
    if (N <= 0 || S < 1 || S > N || F < 1 || F > N) {
        cout << -1 << "\n";
        return 0;
    }

    S--; // перевод в 0-индексацию
    F--;

    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(N, INF);

    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

    dist[S] = 0;              // старт
    pq.push({ 0, S });          // (расстояние, вершина)

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) continue;  // пропуск устаревших записей

        for (int to = 0; to < N; to++) {
            if (a[v][to] == -1) continue;     // ребра нет
            long long w = a[v][to];           // вес ребра (>=0)

            if (dist[to] > dist[v] + w) {     // релаксация
                dist[to] = dist[v] + w;
                pq.push({ dist[to], to });
            }
        }
    }

    cout << (dist[F] == INF ? -1 : dist[F]) << "\n";
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
