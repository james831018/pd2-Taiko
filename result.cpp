#include "result.h"
#include "ui_result.h"
#include"mainwindow.h"
#include"form.h"

result::result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}

result::~result()
{
    delete ui;
}
void result::printscore(int score)
{
    ui->resultscore->display(score);
}

void result::on_exit_clicked()
{
    this->hide();
    exit();

}

void result::on_restart_clicked()
{
    restart();
}
