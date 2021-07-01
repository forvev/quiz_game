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
    void read_file_lines();


private slots:
    //void on_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::End *ui;
    int score;
    //int result_score;
    QString player_name;
    int file_lines_count=0;

    //QString *read_file;

signals:
    void HomeClicked();
};

#endif // END_H
