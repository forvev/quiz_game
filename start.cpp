#include "start.h"
#include "ui_start.h"
#include <QTimer>
#include "quiz.h"
#include <QDebug>
#include <quiz.h>

class quiz;

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);

    /*qDebug()<<ui->label_3->text();
    ui->label_3->setText(ui->lineEdit->text());
    qDebug()<<ui->label_3->text();*/
}

start::~start()
{
    delete ui;
    delete quiz_start;
}

void start::on_pushButton_clicked()
{
    //Quiz q;
    //q.active_timer();
    quiz_start = new Quiz;

    ui->stackedWidget->insertWidget(2,quiz_start);

    ui->stackedWidget->setCurrentIndex(2);


}



void start::on_lineEdit_editingFinished()//liczba pytan
{
    qDebug()<<ui->lineEdit->text();

}



void start::on_lineEdit_2_editingFinished()//w jakim czasie
{
    //Quiz q;
    //q.setTime_for_quiz(ui->lineEdit_2->text().toInt());
}
