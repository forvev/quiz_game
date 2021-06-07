#include "end.h"
#include "ui_end.h"
#include <QDebug>
#include <quiz.h>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

End::End(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);

    //qDebug()<<"Jestem w end"<<result_score;
}

End::~End()
{
    delete ui;
}


void End::set_score(int value){
    score=value;
    //qDebug()<<"Score in end"<<score;
    ui->label_2->setText(QString::number(score));
   qDebug()<<"J11estem w end"<<score;
}

void End::write_date(){
    //zapisujemy do pliku nasz wynik
   qDebug()<<"Jestem w end"<<score;
   QString filename="C:/Users/Artur/Desktop/studia/II semestr/C++ obiektowy/lab10QT/Project/quiz_game/result.txt";
    QFile file(filename);
    // Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly | QFile::Append | QFile::Text)){
        qDebug() << " Could not open file for writing";
        return;
    }

    QTextStream out(&file);
    qDebug()<<"Name:"<<player_name;
    out<<player_name<<": "<<score<<"| "<<QDateTime::currentDateTime().toString()<<"\n";

    //out<<ui->label_2;

    file.flush();
    file.close();
    //----------------------------------------

}

void End::read_date(){
    //odczytujemy z pliku wszystkie wyniki
    QString filename="C:/Users/Artur/Desktop/studia/II semestr/C++ obiektowy/lab10QT/Project/quiz_game/result.txt";
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Nie mozna otworzyc pliku!";
        return;
    }


    QTextStream in(&file);

    while(!in.atEnd()){
        QString line=in.readLine();
            //ui->listWidget->setText(line);
            ui->listWidget->addItem(line);
        }



    file.close();
}

void End::set_player_name(QString temp){
    player_name=temp;
}
