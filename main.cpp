#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Point {
public:
    Point(double x, double y) : x(x), y(y) {}
    double distanceToOrigin() const {
        return std::sqrt(x * x + y * y);
    }
    bool operator<(const Point& other) const {
        return distanceToOrigin() < other.distanceToOrigin();
    }
    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }
private:
    double x, y;
};

int main() {
    std::vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));
    std::sort(v.begin(), v.end());
    for (auto& point : v)
        std::cout << point << '\n';
    return 0;
}
