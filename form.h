#ifndef FORM_H
#define FORM_H
#include"result.h"

#include<QTime>
#include<QTimer>

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
signals:
    void askshowresult();
    void askprintscore(int);
public slots:
    void movelabel();

private:
    void keyPressEvent(QKeyEvent *event);
    int timecount;
    int fortime;
    int score;
    int combocount;
    Ui::Form *ui;
    result *theresult;
};

#endif // FORM_H
