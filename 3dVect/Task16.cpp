#include <iostream>
#include <vector>
using namespace std;
class Vector3D {
private:
    double startX;
    double startY;
    double startZ;
    double endX;
    double endY;
    double endZ;

public:
    Vector3D(double startX = 0.0, double startY = 0.0, double startZ = 0.0,
        double endX = 0.0, double endY = 0.0, double endZ = 0.0)
        : startX(startX), startY(startY), startZ(startZ), endX(endX), endY(endY), endZ(endZ) {}

    double getStartX() const { return startX; }
    double getStartY() const { return startY; }
    double getStartZ() const { return startZ; }
    double getEndX() const { return endX; }
    double getEndY() const { return endY; }
    double getEndZ() const { return endZ; }

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(startX + other.startX, startY + other.startY, startZ + other.startZ,
            endX + other.endX, endY + other.endY, endZ + other.endZ);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(startX - other.startX, startY - other.startY, startZ - other.startZ,
            endX - other.endX, endY - other.endY, endZ - other.endZ);
    }

    Vector3D operator*(double scalar) const {
        return Vector3D(startX * scalar, startY * scalar, startZ * scalar,
            endX * scalar, endY * scalar, endZ * scalar);
    }

    Vector3D operator*(const Vector3D& other) const {
        double resultStartX = startY * other.endZ - startZ * other.endY;
        double resultStartY = startZ * other.endX - startX * other.endZ;
        double resultStartZ = startX * other.endY - startY * other.endX;
        double resultEndX = endY * other.startZ - endZ * other.startY;
        double resultEndY = endZ * other.startX - endX * other.startZ;
        double resultEndZ = endX * other.startY - endY * other.startX;
        return Vector3D(resultStartX, resultStartY, resultStartZ, resultEndX, resultEndY, resultEndZ);
    }

    bool operator==(const Vector3D& other) const {
        return (startX == other.startX && startY == other.startY && startZ == other.startZ &&
            endX == other.endX && endY == other.endY && endZ == other.endZ);
    }   

    double get_length() const {
        double dx = endX - startX;
        double dy = endY - startY;
        double dz = endZ - startZ;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    double get_multi_product(double k, const Vector3D* vectors, int size) const {
        double product = 1.0;
        for (int i = 0; i < size; i++) {
            const Vector3D& vector = vectors[i];
            if (vector.get_length() > k) {
                product *= vector.get_length();
            }
        }
        return product;
    }

    double get_multi_sum(double k, const Vector3D* vectors, int size) const {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            const Vector3D& vector = vectors[i];
            if (vector.get_length() > k) {
                sum += vector.get_length();
            }
        }
        return sum;
    }

    double get_multi_diff(double k, const Vector3D* vectors, int size) const {
        double diff = 0.0;
        for (int i = 0; i < size; i++) {
            const Vector3D& vector = vectors[i];
            if (vector.get_length() > k) {
                diff -= vector.get_length();
            }
        }
        return diff;
    }
    void setStartX(double x) { startX = x; }
    void setStartY(double y) { startY = y; }
    void setStartZ(double z) { startZ = z; }
    void setEndX(double x) { endX = x; }
    void setEndY(double y) { endY = y; }
    void setEndZ(double z) { endZ = z; }
};
double get_multi_sum(double k, const Vector3D* vectors, int size);
double get_multi_diff(double k, const Vector3D* vectors, int size);
double get_multi_product(double k, const Vector3D* vectors, int size);


int main()
{
    int n;
    cout << "Enter number of vectors: " << endl;
    cin >> n;
    Vector3D* vectors;
    vectors = new Vector3D[n];
    cout << "Enter coordinates" << endl;
    for (int i = 0; i < n; i++)
    {
        int xx1, xx2, yy1, yy2, zz1, zz2;
        cout << "Enter x of start: ";
        cin >> xx1;
        cout << endl;
        cout << "Enter x of end: ";
        cin >> xx2;
        cout << endl;
        cout << "Enter y of start: ";
        cin >> yy1;
        cout << endl;
        cout << "Enter y of end: ";
        cin >> yy2;
        cout << endl;
        cout << "Enter z of start: ";
        cin >> zz1;
        cout << endl;
        cout << "Enter z of end: ";
        cin >> zz2;
        cout << endl;
        Vector3D v(xx1, yy1, zz1, xx2, yy2, zz2);
        vectors[i] = v;
        v.get_length();
        cout << endl;
    };
    cout << "Enter k: " << endl;
    double k;
    cin >> k;
    double sum = get_multi_sum(k, vectors, n);
    double diff = get_multi_diff(k, vectors, n);
    double product = get_multi_product(k, vectors, n);
    cout << "Mulpi Product is: " << product;
    cout << "Mulpi Diff is: " << diff;
    cout << "Mulpi Sum is: " << sum;
}

