#ifndef VALENTINECARD_HPP
#define VALENTINECARD_HPP

#include <QWidget>

class QMovie;
class QLabel;
class QPushButton;
class UnaccessibleButton;

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

    bool IsValid() const noexcept;

public slots:
    void OnButtonYesClicked();
    void OnButtonNoHovered();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::ValentineCard *ui;
    QMovie* m_firstMovie;
    QMovie* m_finalMovie;
    QLabel* m_centralGif;
    UnaccessibleButton* m_buttonNo;
    QPushButton* m_buttonYes;
    bool m_valid = false;
    bool m_onFinalPage = false;
};
#endif // VALENTINECARD_HPP
