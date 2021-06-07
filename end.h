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
    void write_date();
    void read_date();
    void set_player_name(QString temp);


private:
    Ui::End *ui;
    int score;
    //int result_score;
    QString player_name;
};

#endif // END_H
