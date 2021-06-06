#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quiz.h"
#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //open = new start;
    ui->stackedWidget->insertWidget(1,&open);



}

MainWindow::~MainWindow()
{
    delete ui;
    //delete open;

}


void MainWindow::on_pushButton_clicked()
{
    /*Quiz *my_screen= new Quiz;

    my_screen->setModal(true);
    my_screen->exec();*/

    ui->stackedWidget->setCurrentIndex(1);


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
