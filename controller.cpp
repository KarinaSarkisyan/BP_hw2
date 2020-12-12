#include <controller.h>

enum eFigure {
    RECTANGLE,
    CIRCLE,
    FIG_NUMBER
};


Controller::Controller() {
    figures = new std::vector<Figure*>();
}

Controller::~Controller() {
    for (auto ptr : *figures) {
        delete ptr;
    }
    delete figures;
}

void Controller::addNewFigure(int x_c, int y_c) {
    Figure* newFigure = generateFigure(x_c, y_c);
    figures->push_back(newFigure);
}

std::vector<Figure*>* Controller::getFigures() {
    return figures;
}

Figure* Controller::generateFigure(int x_c, int y_c) {
    int type = rand() % FIG_NUMBER;
    eFigure figure = static_cast<eFigure>(type);
    Figure* newFigure = nullptr;

    switch(figure) {
        case RECTANGLE : {
            int width = rand() % MAX_WIDTH;
            int height = rand() % MAX_HEIGHT;
            newFigure = new Rectangle(x_c, y_c, width, height);
            break;
        }
        case CIRCLE : {
            int radius = rand() % MAX_RADIUS;
            newFigure = Circle::createCircle(x_c, y_c, radius);
            break;
        }
        default :{
            throw "Bad figure type";
        }
    }
    return newFigure;
}

void Controller::deleteFigure(int x_Click, int y_Click) {
    std::vector<Figure*>::iterator it;
    it = figures->begin();
    while(it != figures->end()) {
        Figure* i = *it;
        if(i->isPointInFigure(x_Click, y_Click)) {
            figures->erase(it);
        }else{
            ++it;
        }
    }
}
