#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include "config.h"

using std::cout;
using std::pair;
using std::vector;
using std::min;
//using namespace std;


int search_points(pair<int, int> point1, pair<int, int> point2, const vector<pair<int, int>>& points) {

	int counter1 = 0, counter2 = 0;

	for (const auto& point : points) {
		int vector_multi = (point.second - point1.second) * (point2.first - point1.first) -
			(point.first - point1.first) * (point2.second - point1.second);

		if (vector_multi > 0) {
			counter1++;
		}
		else if (vector_multi < 0) {
			counter2++;
		}
	}
	return min(counter1, counter2);
}
	pair<pair<int, int>, pair<int, int>> search_min_points(const vector<pair<int, int>>&points) {

		int min_meaning = INT_MAX;
		pair<pair<int, int>, pair<int, int>> optimal_points;
		for (size_t i = 0; i < points.size(); ++i) {
			for (size_t j = i + 1; j < points.size(); ++j) {
				int difference = abs(search_points(points[i], points[j], points));
				if (difference < min_meaning) {
					min_meaning = difference;
					optimal_points = { points[i], points[j] };
					cout << "Optimal points: (" << optimal_points.first.first << ", " << optimal_points.first.second << ") and ("
						<< optimal_points.second.first << ", " << optimal_points.second.second << ")" << std::endl;
					
				}
			}
		}
		return optimal_points;
	}
	
	int search_points_txt(pair<int, int> number1, pair<int, int> number2, const vector<pair<int, int>>& numbers) {

		int counterNum1 = 0, counterNum2 = 0;

		for (const auto& number : numbers) {
			int vector_multiNum = (number.second - number1.second) * (number2.first - number1.first) -
				(number.first - number1.first) * (number2.second - number1.second);

			if (vector_multiNum > 0) {
				counterNum1++;
			}
			else if (vector_multiNum < 0) {
				counterNum2++;
			}
		}
		return min(counterNum1, counterNum2);
	}
	pair<pair<int, int>, pair<int, int>> search_min_points_txt(const vector<pair<int, int>>& numbers) {

		int min_meaningNum = INT_MAX;
		pair<pair<int, int>, pair<int, int>> optimal_pointsNum;
		for (size_t i = 0; i < numbers.size(); ++i) {
			for (size_t j = i + 1; j < numbers.size(); ++j) {
				int difference = abs(search_points_txt(numbers[i], numbers[j], numbers));
				if (difference < min_meaningNum) {
					min_meaningNum = difference;
					optimal_pointsNum = { numbers[i], numbers[j] };
					cout << "Optimal points: (" << optimal_pointsNum.first.first << ", " << optimal_pointsNum.first.second << ") and ("
						<< optimal_pointsNum.second.first << ", " << optimal_pointsNum.second.second << ")" << std::endl;

				}
			}
		}
		return optimal_pointsNum;
	}
