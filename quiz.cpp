#include "quiz.h"
#include "ui_quiz.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <time.h>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <start.h> //get_time - pobieramy czas od uzytkownika na quiz
#include <end.h>

Quiz::Quiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Quiz), fatal_value(0), time_for_quiz(4)
{
    ui->setupUi(this);
    qDebug()<<"Jestem w quiz!";


    //start *a=new start;
    //time_for_quiz=a->on_lineEdit_2_editingFinished();

    qDebug()<<time_for_quiz;

    select_question();
    //ui->label->setText("fdsf");//odczytuje
    ui->label->setText(question[0]);
    ui->checkBox->setText(answer[0]);
    ui->checkBox_2->setText(answer_2[0]);
    ui->checkBox_3->setText(answer_3[0]);
    ui->checkBox_4->setText(answer_4[0]);

    quiz_end = new End;

    ui->stackedWidget->insertWidget(2, quiz_end);

    //tworzymy zegar
    s1_timer = new QTimer(this);
    QObject::connect(s1_timer, SIGNAL(timeout()),this,SLOT(UpdateTime()));
    s1_timer->start(1000);


}

Quiz::~Quiz()
{
    delete ui;
    delete [] question;
    delete [] answer;
    delete [] answer_2;
    delete [] answer_3;
    delete [] answer_4;
    delete [] cur_answer;
    delete quiz_end;
    delete s1_timer;
}

void Quiz::on_pushButton_clicked()
{

    //else if(ui->checkBox->isChecked()==true && cur_answer[current_count]==1)
    //select_question();
    //ui->stackedWidget->setCurrentIndex(1);


    //if(!fatal_value) on_pushButton_clicked(); //???
    //qDebug()<<fatal_value;
    //if(current_count==0) check_answer();

    qDebug()<<"current count: "<<current_count<<"question count: "<<qs_count;
    check_answer();
    qDebug()<<"Punkty: "<<points_scored;
    quiz_end->set_score(points_scored);//na biezaco zmieniamy wynik przy koncowym wyswietleniu
    if(fatal_value==0 && current_count<qs_count){
        current_count++;
        ui->label_2->clear();
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);
        if(current_count!=qs_count) fill_in();
   }
    if(qs_count==current_count){
        qDebug()<<"current count:fsdfsdf ";
       ui->stackedWidget->setCurrentIndex(2);
   }
}

void Quiz::fill_in(){
    //czyscimy ikonki
    //wypelniamy pola pytaniem i odpowiedziami
    ui->label->setText(question[current_count]);
    ui->checkBox->setText(answer[current_count]);
    ui->checkBox_2->setText(answer_2[current_count]);
    ui->checkBox_3->setText(answer_3[current_count]);
    ui->checkBox_4->setText(answer_4[current_count]);
}

void Quiz::check_answer(){
    if(ui->checkBox->isChecked()==true && ui->checkBox_2->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox->isChecked()==true && ui->checkBox_3->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox->isChecked()==true && ui->checkBox_4->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox_2->isChecked()==true && ui->checkBox_3->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox_2->isChecked()==true && ui->checkBox_4->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox_3->isChecked()==true && ui->checkBox_4->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox->isChecked()==true && ui->checkBox_2->isChecked()==true && ui->checkBox_3->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox->isChecked()==true && ui->checkBox_2->isChecked()==true && ui->checkBox_4->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox_2->isChecked()==true && ui->checkBox_3->isChecked()==true && ui->checkBox_4->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox->isChecked()==true && ui->checkBox_2->isChecked()==true && ui->checkBox_3->isChecked()==true && ui->checkBox_4->isChecked()==true){
        ui->label_2->setText("Tylko jedna odpowiedz jest prawdziwa!");
        fatal_value++;
    }
    else if(ui->checkBox->isChecked()==true && cur_answer[current_count]==1){
        points_scored++;
        //if(fatal_value>0) ui->label_2->clear();//usuwamy komentarz
        fatal_value=0;//tylko taka wartosc pozwoli przejsc nam do nastepnego pytania
        //ui->checkBox->setChecked(false);

    }
    else if(ui->checkBox_2->isChecked()==true && cur_answer[current_count]==2){
        points_scored++;
        //if(fatal_value>0) ui->label_2->clear();
        fatal_value=0;
        //ui->checkBox_2->setChecked(false);

    }
    else if(ui->checkBox_3->isChecked()==true && cur_answer[current_count]==3){
        points_scored++;
        //if(fatal_value>0) ui->label_2->clear();
        fatal_value=0;
        //ui->checkBox_3->setChecked(false);
    }
    else if(ui->checkBox_4->isChecked()==true && cur_answer[current_count]==4){
        points_scored++;
        //if(fatal_value>0) ui->label_2->clear();
        fatal_value=0;
        //ui->checkBox_4->setChecked(false);
    }
    //gdy znaznaczymy np. dwie odpowiedzi, a potem zaznaczymi jedna, ale zla
    else if(ui->checkBox->isChecked()==true && cur_answer[current_count]!=1) fatal_value=0;
    else if(ui->checkBox_2->isChecked()==true && cur_answer[current_count]!=2) fatal_value=0;
    else if(ui->checkBox_3->isChecked()==true && cur_answer[current_count]!=3) fatal_value=0;
    else if(ui->checkBox_4->isChecked()==true && cur_answer[current_count]!=4) fatal_value=0;
}

//ODCZYT
void Quiz::select_question(){
    QString filename="C:/Users/Artur/Desktop/studia/II semestr/C++ obiektowy/lab10QT/Project/quiz_game/question.txt"; //C:\\Users\\Artur\\Desktop\\studia\\II semestr\\C++ obiektowy\\lab10QT
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Nie mozna otworzyc pliku!";
        return;
    }

    //QString line;
    QTextStream in(&file);
    int i=0, temp=0;//wyznacza linie do zapisu
    qs_count = in.readLine().toInt();

    question= new QString[qs_count];
    answer = new QString[qs_count];
    answer_2 = new QString[qs_count];
    answer_3 = new QString[qs_count];
    answer_4 = new QString[qs_count];
    cur_answer = new int[qs_count];

    while(!in.atEnd()){
        QString line=in.readLine();

        /*if(i==0) ui->label->setText(line);
        else if(i==1) ui->checkBox->setText(line);
        else if(i==2) ui->checkBox_2->setText(line);
        else if(i==3) ui->checkBox_3->setText(line);
        else{
            ui->checkBox_4->setText(line);
            i=0;
        }*/
        if(i==0) {question[temp]=line; i++;}
        else if(i==1) {answer[temp]=line; i++;}
        else if(i==2) {answer_2[temp]=line; i++;}
        else if(i==3) {answer_3[temp]=line; i++;}
        else if(i==4) {answer_4[temp]=line; i++;}
        else if(i==5){
            cur_answer[temp]=line.toInt();
            i=0;
            temp++;
        }

    }
    file.close();
//------------------------
}

void Quiz::active_timer(){

}

void Quiz::UpdateTime(){
   //qDebug()<<"sas";
    time_for_quiz--;
    QString hh, mm, ss;
    int hours=time_for_quiz/3600;
    hh=QString::number(hours);
    if(hours<10) hh="0"+hh;

    int minutes=(time_for_quiz-hours*3600)/60;
    mm=QString::number(minutes);
    if(minutes<10) mm="0"+mm;

    int seconds=time_for_quiz - hours*3600 -minutes*60;
    ss=QString::number(seconds);
    if(seconds<10) ss="0"+ss;

    ui->label_3->setText(hh+":"+mm+":"+ss);

    if(time_for_quiz<=0){
        //QMessageBox::information(this,"Information", "Time is gone.");
        //QMessageBox::warning(this,"Information", "Time is gone.");
        //QMessageBox msgBox(QMessageBox::warning,"Information","Time has gone.",QMessageBox::Ok);
        //qDebug()<<"Xxx";
        //QMessageBox::warni;
        QMessageBox msgBox;

        msgBox.information(this,"Information","Time has gone.",QMessageBox::Ok);
        s1_timer->stop();

        ui->stackedWidget->setCurrentIndex(2);

    }

}

void Quiz::setTime_for_quiz(int time){
    time_for_quiz=time;
}

/*void Quiz::get_score(End *temp){
    temp->score=points_scored;
}*/

void Quiz::setQuestions_for_quiz(int value){
    max_question=value;
}
