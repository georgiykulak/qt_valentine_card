#include "ValentineCard.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ValentineCard w;

    if (!w.IsValid())
    {
        w.close();
        return 1;
    }

    w.show();
    return a.exec();
}
