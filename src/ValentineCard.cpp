#include "ValentineCard.hpp"
#include "ui_ValentineCard.h"

ValentineCard::ValentineCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ValentineCard)
{
    ui->setupUi(this);
}

ValentineCard::~ValentineCard()
{
    delete ui;
}
