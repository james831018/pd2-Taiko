#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    form=NULL;
    theresult=NULL;
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->close();
}

void MainWindow::on_pushButton_2_clicked()
{

//    printf("the not form is %d\n",form);//try
    form = new Form;              //===============================================>創form
    theresult = new result;               //==========================>創result
//    printf("the have form is %d\n",form);//try
    connect(form,SIGNAL(askshowresult()),theresult,SLOT(show()));
    connect(form,SIGNAL(askprintscore(int)),theresult,SLOT(printscore(int)));
    connect(theresult,SIGNAL(exit()),form,SLOT(deleteLater()));
    connect(theresult,SIGNAL(restart()),this,SLOT(reset()));

    form->show();
    this->close();
}
void MainWindow::showresult()
{
    form->show();
}
void MainWindow::reset()
{
    if(form!=NULL){
//        printf("the form !=NULL\n");//try
        delete form;
        form=NULL;
    }
    if(theresult!=NULL){
//        printf("theresult !=NULL\n");//try
        delete theresult;
        theresult = NULL;
    }
    on_pushButton_2_clicked();
}
