#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Point.h"
#include "Square.h"

using namespace std;

/* ------------ Point 정의 ------------ */
Point::Point(int px, int py) : x(px), y(py) {}
int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(int px) { x = px; }
void Point::setY(int py) { y = py; }

/* ------------ Square 정의 ------------ */
Square::Square(const std::string n, int px, int py, unsigned int s)
    : Point(px, py), side(s), area(s* s), name(n) {
}

unsigned int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return area; }
std::string Square::getName() const { return name; }

void Square::setSide(unsigned int s) { side = s; area = s * s; }
void Square::setArea(unsigned int a) { area = a; }
void Square::setName(std::string n) { name = n; }

/* ------------ 출력 유틸 ------------ */
static void printAreaOrder(const vector<Square>& v) {
    cout << "Squares in increasing order of area\n";
    for (const auto& s : v) {
        cout << s.getName()
            << "(" << s.getX() << ", " << s.getY() << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << "\n";
    }
    cout << "\n";
}

static void printMaxXOrder(const vector<Square>& v) {
    cout << "Squares in increasing order of max x-coordinate\n";
    for (const auto& s : v) {
        cout << s.getName()
            << "(" << s.getX() + static_cast<int>(s.getSide()) << ", " << s.getY() << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << "\n";
    }
    cout << "\n";
}

static void printMaxYOrder(const vector<Square>& v) {
    cout << "Squares in increasing order of max y-coordinate\n";
    for (const auto& s : v) {
        cout << s.getName()
            << "(" << s.getX() << ", " << s.getY() + static_cast<int>(s.getSide()) << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << "\n";
    }
}

/* ------------ main ------------ */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<Square> squares;
    squares.reserve(n);

    for (int i = 0; i < n; ++i) {
        string name;
        int x, y;
        unsigned int side;
        cin >> name >> x >> y >> side;
        squares.emplace_back(name, x, y, side);
    }

    cout << "\n";

    // 1) 면적 오름차순 (면적, x, y)
    {
        auto v = squares;
        sort(v.begin(), v.end(), [](const Square& a, const Square& b) {
            if (a.getArea() != b.getArea()) return a.getArea() < b.getArea();
            if (a.getX() != b.getX())    return a.getX() < b.getX();
            return a.getY() < b.getY();
            });
        printAreaOrder(v);
    }

    // 2) 최대 x 오름차순 (x+side, x, y)
    {
        auto v = squares;
        sort(v.begin(), v.end(), [](const Square& a, const Square& b) {
            int ax = a.getX() + static_cast<int>(a.getSide());
            int bx = b.getX() + static_cast<int>(b.getSide());
            if (ax != bx)               return ax < bx;
            if (a.getX() != b.getX())   return a.getX() < b.getX();
            return a.getY() < b.getY();
            });
        printMaxXOrder(v);
    }

    // 3) 최대 y 오름차순 (y+side, x, y)
    {
        auto v = squares;
        sort(v.begin(), v.end(), [](const Square& a, const Square& b) {
            int ay = a.getY() + static_cast<int>(a.getSide());
            int by = b.getY() + static_cast<int>(b.getSide());
            if (ay != by)               return ay < by;
            if (a.getX() != b.getX())   return a.getX() < b.getX();
            return a.getY() < b.getY();
            });
        printMaxYOrder(v);
    }

    return 0;
}
