#include "end.h"
#include "ui_end.h"
#include <QDebug>
#include <quiz.h>

End::End(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);

    qDebug()<<"Jestem w end";
    /*ui->label_2->setText(QString::number());
    connect(ui->)*/
    //Quiz temp;
    //temp.get_score(this);
    //score=
    //qDebug()<<;

}

End::~End()
{
    delete ui;
}


void End::set_score(int value){
    score=value;
    //qDebug()<<"Score in end"<<score;
    ui->label_2->setText(QString::number(score));
}
