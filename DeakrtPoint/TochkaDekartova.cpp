#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class Point
{
public:
    Point(T x, T y) : _x(x), _y(y) {}

    void display() const
    {
        cout << "X: " << _x << endl;
        cout << "Y: " << _y << endl;
    }

    T getX() const
    {
        return _x;
    }

    T getY() const
    {
        return _y;
    }

    void setX(T x)
    {
        _x = x;
    }

    void setY(T y)
    {
        _y = y;
    }

    T calculating_p(T x, T y)
    {
        T result = sqrt(x * x + y * y);
        return result;
    }

    T calculating_q(T x, T y)
    {
        T result = atan2(y, x);
        return result;
    }

    T calculating_distance(T x1, T x2, T y1, T y2)
    {
        T s1 = x2 - x1;
        T s2 = y2 - y1;
        return sqrt(s1 * s1 + s2 * s2);
    }

    Point operator+(const Point& other) const
    {
        return Point(_x + other._x, _y + other._y);
    }

    Point operator-(const Point& other) const
    {
        return Point(_x - other._x, _y - other._y);
    }
    bool isInSecondQuadrant() const
    {
        return (_x < 0 && _y > 0);
    }

private:
    T _x;
    T _y;
};

template <typename T>
class PointWithName : public Point<T>
{
public:
    PointWithName(T x, T y, const string& name) : Point<T>(x, y), name(name) {}

    string getName() const
    {
        return name;
    }

    void setName(const string& newName)
    {
        name = newName;
    }

private:
    string name;
};
template <typename T>
void readPointsFromFile(const string& filename, vector<Point<T>>& points)
{
    ifstream file(filename);
    if (file.is_open())
    {
        T x, y;
        while (file >> x >> y)
        {
            Point<T> point(x, y);
            points.push_back(point);
        }
        file.close();
    }
}

template <typename T>
void displayPoints(const vector<Point<T>>& points)
{
    for (const auto& point : points)
    {
        point.display();
    }
}

template <typename T>
int countPointsInSecondQuadrant(const vector<Point<T>>& points)
{
    int count = 0;
    for (const auto& point : points)
    {
        if (point.isInSecondQuadrant())
            count++;
    }
    return count;
}

template <typename T>
void sortByPolarAngle(vector<Point<T>>& points)
{
    sort(points.begin(), points.end(), []( Point<T>& p1,  Point<T>& p2) {
        T q1 = p1.calculating_q(p1.getX(), p1.getY());
        T q2 = p2.calculating_q(p2.getX(), p2.getY());
        return q1 < q2;
        });
}


int main()
{
    cout << "Enter coordinates for point A:" << endl;
    double x_a, y_a;
    cin >> x_a >> y_a;
    PointWithName<double> pointA(x_a, y_a, "A");

    cout << "Enter coordinates for point B:" << endl;
    double x_b, y_b;
    cin >> x_b >> y_b;
    PointWithName<double> pointB(x_b, y_b, "B");

    cout << "Enter coordinates for point C:" << endl;
    double x_c, y_c;
    cin >> x_c >> y_c;
    PointWithName<double> pointC(x_c, y_c, "C");

    double x_d = pointA.getX() + pointC.getX() - pointB.getX();
    double y_d = pointA.getY() + pointC.getY() - pointB.getY();
    PointWithName<double> pointD(x_d, y_d, "D");

    cout << "Coordinates of point D :" << endl;
    pointD.display();

    double diagonalLengthBD = pointA.calculating_distance(pointB.getX(), pointD.getX(), pointB.getY(), pointD.getY());
    cout << "Length of the diagonal BD: " << diagonalLengthBD << endl;
    double diagonalLengthAC = pointD.calculating_distance(pointA.getX(), pointC.getX(), pointA.getY(), pointC.getY());
    cout << "Length of the diagonal AC: " << diagonalLengthAC << endl;

    cout << "Vertices with polar angle Pi/4 or 5Pi/4:" << endl;
    if (abs(pointA.calculating_q(pointA.getX(), pointA.getY()) - M_PI_4) < 1e-6)
        cout << "Vertex A has polar angle Pi/4" << endl;

    if (abs(pointB.calculating_q(pointB.getX(), pointB.getY()) - M_PI_4) < 1e-6)
        cout << "Vertex B has polar angle Pi/4" << endl;

    if (abs(pointC.calculating_q(pointC.getX(), pointC.getY()) - M_PI_4) < 1e-6)
        cout << "Vertex C has polar angle Pi/4" << endl;

    if (abs(pointA.calculating_q(pointA.getX(), pointA.getY()) - (5 * M_PI_4)) < 1e-6)
        cout << "Vertex A has polar angle 5Pi/4" << endl;

    if (abs(pointB.calculating_q(pointB.getX(), pointB.getY()) - (5 * M_PI_4)) < 1e-6)
        cout << "Vertex B has polar angle 5Pi/4" << endl;

    if (abs(pointC.calculating_q(pointC.getX(), pointC.getY()) - (5 * M_PI_4)) < 1e-6)
        cout << "Vertex C has polar angle 5Pi/4" << endl;
    vector<Point<int>> points;
    readPointsFromFile("tochki.txt", points);

    cout << "Points from the file:" << endl;
    displayPoints(points);

    int secondQuadrantCount = countPointsInSecondQuadrant(points);
    cout << "Number of points in the second quadrant: " << secondQuadrantCount << endl;

    sortByPolarAngle(points);
    cout << "Points sorted by distance from the origin:" << endl;
    displayPoints(points);

    return 0;
}
