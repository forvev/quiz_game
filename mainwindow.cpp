#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quiz.h"
#include <QMessageBox>
#include <QLabel>
#include <end.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Quzi game");




    //connect(&open, SIGNAL(~start()), this, SLOT(~MainWidnow));
    //connect(&open, SIGNAL(on_pushButton_clicked()), this, SLOT(~MainWindow()));

}

MainWindow::~MainWindow()
{
    qDebug()<<"Usuwam w Main";
    delete ui;
    //delete open;

}


void MainWindow::on_pushButton_clicked()
{
    /*Quiz *my_screen= new Quiz;

    my_screen->setModal(true);
    my_screen->exec();*/

    //ui->~MainWindow();
    //this->close();
    //qDebug()<<"dsds";
    //open = new start;
    ui->stackedWidget->insertWidget(1,&open);
    ui->stackedWidget->setCurrentIndex(1);
    //qDebug()<<"dsds";
    //this->~MainWindow();


}

void MainWindow::on_actionAutor_triggered()
{
    QMessageBox::information(this,"Autor", "Artur Zelik");
}

void MainWindow::on_actionOpis_triggered()
{
    QMessageBox::information(this,"O aplikacji","......");
}

void MainWindow::on_actionQT_triggered()
{
    QApplication::aboutQt();

}

/*void MainWindow::moveHome(){
    qDebug()<<"dsds";
    ui->stackedWidget->setCurrentIndex(0);
    //ui->~MainWindow();
}*/

void MainWindow::on_actionWyj_cie_triggered()
{
    this->close();
}


