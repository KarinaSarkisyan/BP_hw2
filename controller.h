#ifndef CLICKHANDLER_H
#define CLICKHANDLER_H

#include <representer.h>
#include <figure.h>
#include <circle.h>
#include <rectangle.h>
#include <cstdlib>
#include <iostream>


class Controller {
public:
    Controller();
    ~Controller();

    void addNewFigure(int x_c, int y_c);

    void deleteFigure(int x_Click, int y_Click);

    std::vector<Figure*>* getFigures();

private:
    int MAX_WIDTH = 200;
    int MAX_HEIGHT = 200;
    int MAX_RADIUS = 200;

    std::vector<Figure*> *figures;

    Figure* generateFigure(int x_c, int y_c);
};

#endif // CLICKHANDLER_H
