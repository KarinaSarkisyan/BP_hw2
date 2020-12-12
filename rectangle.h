#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <figure.h>

using Coordinates = std::pair<int, int>;

class Representer;

class Rectangle : public Figure {
public:

    Rectangle(int x_c, int y_c, int width, int height);

    Coordinates getPoint();

    void drawFigure(Representer* representer);

    bool isPointInFigure(int x, int y);
};

#endif // RECTANGLE_H
