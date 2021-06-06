#ifndef QUIZ_H
#define QUIZ_H

#include <QDialog>
#include <end.h>

namespace Ui {
class Quiz;
}

class Quiz : public QDialog
{
    Q_OBJECT

public:
    explicit Quiz(QWidget *parent = nullptr);
    ~Quiz();
    void select_question();
    void fill_in();
    void check_answer();
    void active_timer();
    void setTime_for_quiz(int time);

private slots:
    void on_pushButton_clicked();
//public slots:
    void UpdateTime();

private:
    Ui::Quiz *ui;
    int qs_count;
    QString *question;
    QString *answer;
    QString *answer_2;
    QString *answer_3;
    QString *answer_4;
    int *cur_answer;
    int current_count=0;//przy ktorym obecnie pytaniu jestesmy
    int points_scored;
    int fatal_value;//blokuje przejscie do nastepnego pytania w przypadku zaznaczenia wiecej niz jednej opcji
    End *quiz_end;

    QTimer *s1_timer;//zegar
    int time_for_quiz;

};

#endif // QUIZ_H
