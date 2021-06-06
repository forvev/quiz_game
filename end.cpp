#include "end.h"
#include "ui_end.h"
#include <QDebug>

End::End(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);

    qDebug()<<"Jestem w end";
}

End::~End()
{
    delete ui;
}
