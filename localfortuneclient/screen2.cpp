#include "screen2.h"
#include "ui_screen2.h"
#include <QStackedWidget>

screen2::screen2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::screen2)
{
    ui->setupUi(this);
}

screen2::~screen2()
{
    delete ui;
}

void screen2::on_pushButton_clicked()
{
    ui->stackedWidget
}
