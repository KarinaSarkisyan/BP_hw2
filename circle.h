#ifndef CIRCLE_H
#define CIRCLE_H

#include <figure.h>

using Coordinates = std::pair<int, int>;

class Representer;

class Circle : public Figure {
public:
    Circle(int x_c, int y_c, int width, int height);

    static Circle* createCircle(int x_c, int y_c, int radius);

    Coordinates getPoint();

    void drawFigure(Representer *representer);

    bool isPointInFigure(int x, int y);
};

#endif // CIRCLE_H
