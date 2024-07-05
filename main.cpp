#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

double distance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point point1 = { 0.0, 0.0 };
    Point point2 = { 3.0, 4.0 };

    double dist = distance(point1, point2);

    cout << "Distance between points: " << dist << endl;

    return 0;
}
