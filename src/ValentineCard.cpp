#include "ValentineCard.hpp"
#include "ui_ValentineCard.h"
#include "UnaccessibleButton.hpp"

#include <QMovie>
#include <QLabel>
#include <QMovie>
#include <QPainter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QRandomGenerator>

ValentineCard::ValentineCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ValentineCard)
{
    ui->setupUi(this);

    setWindowTitle("Валентинка 💕");
    setAttribute(Qt::WA_DeleteOnClose);
    // TODO: Make window resizeable taking into account layouts and buttons
    setMinimumSize(600, 600);
    setMaximumSize(600, 600);

    // TODO: Add to resources
    m_firstMovie = new QMovie("../res/first.gif");
    m_finalMovie = new QMovie("../res/final.gif");
    if (!m_firstMovie->isValid() || !m_finalMovie->isValid())
    {
        QMessageBox::critical(
            this, tr("Error"), tr("Can't load assets"), QMessageBox::Close
        );
        return;
    }

    setAutoFillBackground(true);
    QPalette pal = QPalette();
    // Set background to match first GIF (almost white color)
    pal.setColor(QPalette::Window, Qt::white); // TODO: Adjust color to GIF's bg
    setPalette(pal);

    auto* vLayout = new QVBoxLayout;
    vLayout->setAlignment(Qt::AlignHCenter);

    m_centralGif = new QLabel(this);
    m_centralGif->setMovie(m_firstMovie);

    vLayout->addWidget(m_centralGif);
    setLayout(vLayout);

    m_firstMovie->start();

    m_buttonNo = new UnaccessibleButton("Ні", this);
    m_buttonNo->move(50, 550);
    connect(m_buttonNo, &UnaccessibleButton::pressed,
            this, [this](){ m_buttonNo->hide(); });
    connect(m_buttonNo, &UnaccessibleButton::moveButton,
            this, &ValentineCard::OnButtonNoHovered);

    m_buttonYes = new QPushButton("Так", this);
    m_buttonYes->move(450, 550);
    connect(m_buttonYes, &QPushButton::pressed,
            this, &ValentineCard::OnButtonYesClicked);

    m_valid = true;
}

ValentineCard::~ValentineCard()
{
    delete ui;
}

bool ValentineCard::IsValid() const noexcept
{
    return m_valid;
}

void ValentineCard::OnButtonYesClicked()
{
    m_onFinalPage = true;

    m_buttonNo->hide();
    m_buttonYes->hide();
    QPalette pal = QPalette();
    // Set background to match final GIF (black color - Qt::black)
    pal.setColor(QPalette::Window, Qt::black);
    setPalette(pal);

    m_firstMovie->stop();
    m_centralGif->setMovie(m_finalMovie);
    m_finalMovie->start();
}

void ValentineCard::OnButtonNoHovered()
{
    quint32 randomX =
        QRandomGenerator::global()->bounded((quint32)0,
        (quint32)(width() - m_buttonNo->width()));
    quint32 randomY =
        QRandomGenerator::global()->bounded((quint32)0,
        (quint32)(height() - m_buttonNo->height()));
    m_buttonNo->move(randomX, randomY);
}

void ValentineCard::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // TODO: Use layouts as much as possible
    if (!m_onFinalPage)
    {
        painter.drawText(5, 15, "Від: Гоші");
        painter.drawText(5, 35, "До:  Маші");
    }
    else
    {
        QPen pen1;
        QFont bigFont;
        pen1.setColor(Qt::lightGray);
        bigFont.setPointSize(35);
        painter.setPen(pen1);
        painter.setFont(bigFont);
        painter.drawText(70, 80, "Правильний вибір 😘");

        QPen pen2;
        QFont smallFont;
        pen2.setColor(Qt::gray);
        painter.setPen(pen2);
        painter.setFont(smallFont);
        painter.drawText(width() - 200, height() - 15, "powered by @georgiykulak");
    }

    QWidget::paintEvent(event);
}
