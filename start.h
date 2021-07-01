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
    //void get_time();
    friend class Quiz;

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

private:
    Ui::start *ui;

    int number_of_question;

public:
    Quiz *quiz_start;

/*signals:
    void delete_obj();*/

};

#endif // START_H
