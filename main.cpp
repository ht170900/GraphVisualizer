#include "graphvisualizer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GraphVisualizer window;
    window.show();
    return app.exec();
}
