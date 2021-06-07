#ifndef END_H
#define END_H

#include <QWidget>
//#include <quiz.h>

namespace Ui {
class End;
}

class End : public QWidget //, public Quiz
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();
    void set_score(int value);


private:
    Ui::End *ui;
    int score;
};

#endif // END_H
