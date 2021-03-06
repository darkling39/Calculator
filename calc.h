#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calc; }
QT_END_NAMESPACE

class Calc : public QMainWindow
{
    Q_OBJECT

public:
    Calc(QWidget *parent = nullptr);
    ~Calc();

private:
    Ui::Calc *ui;

    void print();
    void clearAll();
    void clearLast();
    void plus();
    void minus();
    void divide();
    void multiply();
    void result();
    void rest();
};
#endif // CALC_H
