#include "end.h"
#include "ui_end.h"
#include <QDebug>
#include <quiz.h>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <start.h>
#include <mainwindow.h>

End::End(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);

    //qDebug()<<"Jestem w end"<<result_score;
    //start start_2;
    /*MainWindow obj;
    ui->stackedWidget->insertWidget(0, &obj);*/



    //connect(&start_2, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    //connect()
    //connect(&start_2, SIGNAL(moveHome()), this, SLOT(on_pushButton_clicked()));
}

End::~End()
{
    qDebug()<<"Usuwam end";
    delete ui;
    //delete [] read_file;
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
    out<<player_name<<": "<<score<<" | "<<QDateTime::currentDateTime().toString()<<"\n";

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

    //int i=0;
    while(!in.atEnd()){
        QString line=in.readLine();
            //ui->listWidget->setText(line);
            ui->listWidget->addItem(line);
            file_lines_count++;
            //read_file[i]=line;
            //i++;
        }



    file.close();
}

void End::set_player_name(QString temp){
    player_name=temp;
}



/*void End::on_pushButton_clicked()
{
    //ui->stackedWidget->setCurrentIndex(1);
    //emit HomeClicked();


}*/


void End::on_pushButton_clicked()
{
   /*start open_2;
   ui->stackedWidget->insertWidget(1,&open_2);
   ui->stackedWidget->setCurrentIndex(1);*/
   //QWidget::close();
}
