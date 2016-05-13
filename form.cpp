#include "form.h"
#include "ui_form.h"

#include<QKeyEvent>



Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    timecount = 30;
    fortime = 0;
    score = 0;
    combocount = 0;
    QTimer *time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(movelabel()));
    time->start(10);
    ui->setupUi(this);
    ui->count->display(30);
}

void Form::movelabel()
{
    fortime+=1;
    if(timecount == 0){
        timecount-=1;
        ui->drum->close();//讓鼓消失
        ui->drum2->close();
        ui->drum3->close();
        ui->drum4->close();
        ui->drum5->close();
        ui->drum6->close();

        askshowresult();//=========>mian 有connect
        askprintscore(score);//=======>main 有connect

        ui->count->display(0);
    }
     else if(timecount>=0){
        if((fortime%100)==0){
        timecount-=1;
        ui->count->display(timecount);
        }
    }

    int therand = rand()%1000;
    int therand2 = rand()%1000;
    int therand3 = rand()%1000;
    int therand4 = rand()%1000;
    int therand5 = rand()%1000;
    int therand6 = rand()%1000;

    int x = ui->drum->x();    int y = ui->drum->y();
    int x2 = ui->drum2->x();   int y2 = ui->drum2->y();
    int x3 = ui->drum3->x();    int y3 = ui->drum3->y();
    int x4 = ui->drum4->x();    int y4 = ui->drum4->y();
    int x5 = ui->drum5->x();    int y5 = ui->drum5->y();
    int x6 = ui->drum6->x();    int y6 = ui->drum6->y();
 //   printf("x is %d,y is %d\n",x,y);                   //鼓在480~520之間((最旁邊

    ui->drum->move(QPoint(x-2,y));
    ui->drum2->move(QPoint(x2-2,y));
    ui->drum3->move(QPoint(x3-2,y3));
    ui->drum4->move(QPoint(x4-2,y3));
    ui->drum5->move(QPoint(x5-2,y));
    ui->drum6->move(QPoint(x6-2,y));
    if(x <=-50){
        ui->drum->move(QPoint(520+therand,y));
        combocount = 0;
        ui->combocount->display(0);
    }
    if(x2 <=-50){
        ui->drum2->move(QPoint(520+therand2,y));
        combocount = 0;
        ui->combocount->display(0);
    }
    if(x3 <=-50){
        ui->drum3->move(QPoint(520+therand3,y3));
        combocount = 0;
        ui->combocount->display(0);
    }
    if(x4 <=-50){
        ui->drum4->move(QPoint(520+therand4,y3));
        combocount = 0;
        ui->combocount->display(0);
    }
    if(x5 <=-50){
        ui->drum5->move(QPoint(520+therand5,y));
        combocount = 0;
        ui->combocount->display(0);
    }
    if(x6 <=-50){
        ui->drum6->move(QPoint(520+therand6,y));
        combocount = 0;
        ui->combocount->display(0);
    }
}
void Form ::keyPressEvent(QKeyEvent *event)
{
    fortime+=1;
   // printf("for time is %d\n",fortime);             //fortime 可以改變
    int test = rand()%1000; //隨機跳到另一個位置
    int test2 = rand()%1000;
    int test3 = rand()%1000;
    int test4 = rand()%1000;
    int test5 = rand()%1000;
    int test6 = rand()%1000;

    int x = ui->drum->x();    int y = ui->drum->y();
    int x2 = ui->drum2->x();   //int y2 = ui->drum2->y();
    int x3 = ui->drum3->x();    int y3 = ui->drum3->y();
    int x4 = ui->drum4->x();    int y4 = ui->drum4->y();
    int x5 = ui->drum5->x();    int y5 = ui->drum5->y();
    int x6 = ui->drum6->x();    int y6 = ui->drum6->y();
    if(event->key() == Qt::Key_U){

        if(x>=-20 && x<=60){
            ui->drum->move(QPoint(520+test,y));
            combocount+=1;
            score +=combocount;
     //       printf("the score is %d\n",score);
            ui->scorcount->display(score);
            ui->combocount->display(combocount);
        }

        if(x3>=-20 && x3<=60){
            ui->drum3->move(QPoint(520+test3,y3));
            combocount+=1;
            score +=combocount;
     //       printf("the score is %d\n",score);
            ui->scorcount->display(score);
            ui->combocount->display(combocount);
        }
        if(x5>=-20 && x5<=60){
            ui->drum5->move(QPoint(520+test5,y));
            combocount+=1;
            score +=combocount;
     //       printf("the score is %d\n",score);
            ui->scorcount->display(score);
            ui->combocount->display(combocount);
        }

    }
    if(event->key() == Qt::Key_L){
        if(x2>=-20 && x2<=60){
            ui->drum2->move(QPoint(520+test2,y));
            combocount+=1;
            score +=combocount;
     //       printf("the score is %d\n",score);
            ui->scorcount->display(score);
            ui->combocount->display(combocount);
        }
        if(x4>=-20 && x4<=60){
            ui->drum4->move(QPoint(520+test4,y3));
            combocount+=1;
            score +=combocount;
     //       printf("the score is %d\n",score);
            ui->scorcount->display(score);
            ui->combocount->display(combocount);
        }
        if(x6>=-20 && x6<=60){
            ui->drum6->move(QPoint(520+test6,y));
            combocount+=1;
            score +=combocount;
     //       printf("the score is %d\n",score);
            ui->scorcount->display(score);
            ui->combocount->display(combocount);
        }
    }
}

Form::~Form()
{
    delete ui;
}
