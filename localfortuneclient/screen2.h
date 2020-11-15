#ifndef SCREEN2_H
#define SCREEN2_H

#include <QMainWindow>


namespace Ui {
class screen2;
}

class screen2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit screen2(QWidget *parent = nullptr);
    ~screen2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::screen2 *ui;
};

#endif // SCREEN2_H
