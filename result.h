#ifndef RESULT_H
#define RESULT_H

#include <QWidget>

namespace Ui {
class result;
}

class result : public QWidget
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);

    ~result();

signals :
    void exit();
    void restart();
private slots:
    void on_exit_clicked();
    void printscore(int);
    void on_restart_clicked();

private:
    Ui::result *ui;
};

#endif // RESULT_H
