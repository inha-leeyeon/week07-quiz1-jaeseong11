#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(int px = 0, int py = 0);
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
private:
    int x;
    int y;
};

#endif
