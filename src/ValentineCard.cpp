#include "ValentineCard.hpp"
#include "ui_ValentineCard.h"

#include <QMovie>
#include <QLabel>
#include <QMovie>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

ValentineCard::ValentineCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ValentineCard)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    // TODO: Make window resizeable taking into account layouts and buttons
    setMinimumSize(600, 500);
    setMaximumSize(600, 500);

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

    m_buttonNo = new QPushButton("Ні", this);
    m_buttonNo->move(50, 470);
    m_buttonYes = new QPushButton("Так", this);
    m_buttonYes->move(450, 470);
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
