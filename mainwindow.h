#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "form.h"
#include "result.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void showresult();
    void reset();

private:
    Ui::MainWindow *ui;
    Form *form;
    result *theresult;
};

#endif // MAINWINDOW_H
