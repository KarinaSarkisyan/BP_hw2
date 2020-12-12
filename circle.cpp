#include <circle.h>
#include <representer.h>
#include <cmath>


Circle::Circle(int x_c, int y_c, int width, int height) {
    this->x_c= x_c;
    this->y_c = y_c;
    this->width = width;
    this->height = height;
}

Circle* Circle::createCircle(int x_c, int y_c, int radius) {
    Circle* newCircle = new Circle(x_c, y_c, radius * 2, radius * 2);
    return newCircle;
}

void Circle::drawFigure(Representer *representer) {
    representer->draw(this);
}

Coordinates Circle::getPoint() {
    return Coordinates(x_c - width/2, y_c - height/2);
}

bool Circle::isPointInFigure(int x, int y) {
    return (pow((x - x_c), 2) + pow((y - y_c), 2)) <= pow(width / 2, 2);
}
