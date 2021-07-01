#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <start.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionAutor_triggered();

    void on_actionOpis_triggered();

    void on_actionQT_triggered();

    //void moveHome();
    void on_actionWyj_cie_triggered();

private:
    Ui::MainWindow *ui;
    start open;
};
#endif // MAINWINDOW_H
