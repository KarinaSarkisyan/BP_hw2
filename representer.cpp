#include <representer.h>

Representer::Representer(){}

Representer::~Representer() {
    delete painter;
}

void Representer::representFigures(QWidget* widget, std::vector<Figure*> *figures) {
    painter = new QPainter(widget);
    painter -> setRenderHint(QPainter::Antialiasing, true);
    painter -> setPen(QPen(Qt::black));
    for(auto fig : *figures) {
        painter->setBrush(QBrush(QColor(rand()%256, rand()%256, rand()%256)));
        fig->drawFigure(this);
    }
    painter->end();
}

void  Representer::draw(Circle* circle){
    Coordinates center = circle -> getPoint();
    painter -> drawEllipse(center.first, center.second, circle->getWidth(), circle -> getHeight());
}

void  Representer::draw(Rectangle* rectangle){
    Coordinates left_top = rectangle -> getPoint();
    painter -> drawRect(left_top.first, left_top.second, rectangle->getWidth(), rectangle -> getHeight());
}
