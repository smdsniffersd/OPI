#include <iostream>
#include <vector>
#include <utility>
#include "input_key.h"

using std::pair;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<pair<int, int>> input_from_console() {
    int n;
    cout << "Enter total number of points:" << endl;
    cin >> n;
    vector<pair<int, int>> points;
    points.reserve(n); // Выделение памяти заранее, чтобы избежать лишних копирований
    for (int i = 0; i < n; i++) {
        int x, y;
        cout << "Enter x-coordinate for point " << i + 1 << ": ";
        cin >> x;
        cout << "Enter y-coordinate for point " << i + 1 << ": ";
        cin >> y;
        points.emplace_back(x, y); // Добавляем точку в конец вектора
    }
    return points;
}
