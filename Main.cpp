#include <iostream>

#include "Menu.h"
#include "config.h"
#include "input_key.h"
#include "input_txt.h"

using namespace std;

int main()
{
    std::vector<std::pair<int, int>> points;
    std::vector<std::pair<int, int>> numbers;
    int choise = menu();

    while (choise != 0) {
        switch (choise) {
        case 1: numbers = input_from_txt(); break;
        case 2: points = input_from_console(); break;
        case 3:
            if (!points.empty()) {
                pair<pair<int, int>, pair<int, int>> optimal_points = search_min_points(points);

                cout << "Optimal points: (" << optimal_points.first.first << ", " << optimal_points.first.second << ") and ("
                    << optimal_points.second.first << ", " << optimal_points.second.second << ")" << endl;
            }
            else {
                pair<pair<int, int>, pair<int, int>> optimal_pointsNum = search_min_points_txt(numbers);

                cout << "Optimal points: (" << optimal_pointsNum.first.first << ", " << optimal_pointsNum.first.second << ") and ("
                    << optimal_pointsNum.second.first << ", " << optimal_pointsNum.second.second << ")" << endl;
            }
            break;
        }

        choise = menu(); 
    }

    cout << "Thanks for using our program!";
    return 0;
}
