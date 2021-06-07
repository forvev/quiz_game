#include "start.h"
#include "ui_start.h"
#include <QTimer>
#include "quiz.h"
#include <QDebug>
#include <quiz.h>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

class quiz;

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);

    /*qDebug()<<ui->label_3->text();
    ui->label_3->setText(ui->lineEdit->text());
    qDebug()<<ui->label_3->text();*/

    QString filename="C:/Users/Artur/Desktop/studia/II semestr/C++ obiektowy/lab10QT/Project/quiz_game/question.txt";
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Nie mozna otworzyc pliku!";
        return;
    }

    //QString line;
    QTextStream in(&file);

    number_of_question = in.readLine().toInt();

    file.close();

    ui->label_6->setText(QString::number(number_of_question));//pokazujemy graczowi ile ma pytan w bazie
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



    //quiz_start->
    if( ui->lineEdit->text()=="" ){//gdy wpiszemy wartosc i potem usuniemy
        quiz_start = new Quiz;

        if(ui->lineEdit_2->text().toInt()!=0) quiz_start->setTime_for_quiz(ui->lineEdit_2->text().toInt());
        if(ui->lineEdit->text().toInt()!=0) quiz_start->setQuestions_for_quiz(ui->lineEdit->text().toInt());
        quiz_start->setName_for_quiz(ui->lineEdit_3->text());

        ui->stackedWidget->insertWidget(2,quiz_start);

        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(ui->lineEdit->text().toInt() > number_of_question || ui->lineEdit->text().toInt() <= 0){
        QMessageBox msgBox;
        qDebug()<< ui->lineEdit->text();
        msgBox.information(this,"Information","There aren't that many questions.",QMessageBox::Ok);
    }

    else {
        quiz_start = new Quiz;

        if(ui->lineEdit_2->text().toInt()!=0) quiz_start->setTime_for_quiz(ui->lineEdit_2->text().toInt());
        if(ui->lineEdit->text().toInt()!=0) quiz_start->setQuestions_for_quiz(ui->lineEdit->text().toInt());
        quiz_start->setName_for_quiz(ui->lineEdit_3->text());

        ui->stackedWidget->insertWidget(2,quiz_start);

        ui->stackedWidget->setCurrentIndex(2);
    }
}



void start::on_lineEdit_editingFinished()//liczba pytan
{
    qDebug()<<ui->lineEdit->text();


}



void start::on_lineEdit_2_editingFinished()//w jakim czasie
{
    //Quiz q;
    //q.setTime_for_quiz(ui->lineEdit_2->text().toInt());

    qDebug()<<"time:"<<ui->lineEdit_2->text().toInt();

}

/*void start::get_time(){
    //ui->lineEdit_2->setText(ui->lineEdit_2->text());
    qDebug()<<"time:"<<ui->lineEdit_2->text();
    //return ui->lineEdit_2->text().toInt();
}*/
