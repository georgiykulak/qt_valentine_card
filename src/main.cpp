#include "ValentineCard.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QPushButton { background-color: gray }");
    ValentineCard w;

    if (!w.IsValid())
    {
        w.close();
        return 1;
    }

    w.show();
    return a.exec();
}
