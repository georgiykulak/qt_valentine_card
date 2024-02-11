#ifndef UNACCESSIBLEBUTTON_HPP
#define UNACCESSIBLEBUTTON_HPP

#include <QPushButton>

class UnaccessibleButton : public QPushButton
{
    Q_OBJECT
public:
    explicit UnaccessibleButton(QString buttonName, QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void moveButton();
};

#endif // UNACCESSIBLEBUTTON_HPP
