#include "UnaccessibleButton.hpp"

#include <QEvent>

UnaccessibleButton::UnaccessibleButton(QString buttonName, QWidget *parent)
    : QPushButton{buttonName, parent}
{
    installEventFilter(this);
    setMouseTracking(true);
}

bool UnaccessibleButton::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this && event->type() == QEvent::Enter)
    {
        emit moveButton();
    }

    return false;
}
