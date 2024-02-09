#include "ValentineCard.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ValentineCard w;
    w.show();
    return a.exec();
}
