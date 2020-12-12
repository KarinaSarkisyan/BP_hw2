#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

using Coordinates = std::pair<int, int>;

class Representer;

class Figure {
public:
    Figure() {}

    ~Figure() {}

    virtual Coordinates getPoint()=0;

    virtual void drawFigure(Representer* representer)=0;

    virtual bool isPointInFigure(int x, int y)=0;

    int getHeight() {
        return height;
    }

    int getWidth() {
         return width;
    }

protected:
    int x_c;
    int y_c;
    int width;
    int height;
};

#endif // FIGURE_H
