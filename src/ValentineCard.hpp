#ifndef VALENTINECARD_HPP
#define VALENTINECARD_HPP

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ValentineCard;
}
QT_END_NAMESPACE

class ValentineCard : public QWidget
{
    Q_OBJECT

public:
    ValentineCard(QWidget *parent = nullptr);
    ~ValentineCard();

private:
    Ui::ValentineCard *ui;
};
#endif // VALENTINECARD_HPP
