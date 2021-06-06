#ifndef START_H
#define START_H

#include <QWidget>
#include <quiz.h>

//class Quiz;

namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

private:
    Ui::start *ui;
    Quiz *quiz_start;

};

#endif // START_H
