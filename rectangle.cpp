#include <rectangle.h>
#include <representer.h>

Coordinates Rectangle::getPoint() {
    return Coordinates(x_c - width/2, y_c - height/2);
}

Rectangle::Rectangle(int x_c, int y_c, int width, int height) {
    this->x_c = x_c;
    this->y_c = y_c;
    this->width = width;
    this->height = height;
}

void Rectangle::drawFigure(Representer* representer) {
    representer->draw(this);
}

bool Rectangle::isPointInFigure(int x, int y) {
    return (x >= x_c - width/2) && (x <= x_c + width/2) && (y >= y_c - height/2) && (y <= y_c + height/2);
}
