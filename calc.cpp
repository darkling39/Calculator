#include "calc.h"
#include "ui_calc.h"
#include <QtDebug>

Calc::Calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calc)
{
    ui->setupUi(this);
    ui->l_skreen->setPlaceholderText("0");
    connect(ui->b_1, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_2, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_3, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_4, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_5, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_6, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_7, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_8, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_9, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_0, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_div, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_mult, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_plus, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_minus, &QPushButton::clicked, this, &Calc::print);
    connect(ui->b_dot, &QPushButton::clicked, this, &Calc::print);

    connect(ui->b_clear, &QPushButton::clicked, this, &Calc::clearAll);
    connect(ui->b_clearLast, &QPushButton::clicked, this, &Calc::clearLast);
    connect(ui->b_res, &QPushButton::clicked, this, &Calc::result);
}

Calc::~Calc()
{
    delete ui;
}

void Calc::print()
{
    QPushButton *button = (QPushButton*)sender();
    ui->l_skreen->setText(ui->l_skreen->text() + button->text());
}

void Calc::clearAll()
{
    ui->l_skreen->clear();
    ui->l_skreen->setPlaceholderText("0");
}

void Calc::clearLast()
{
    QString eq = ui->l_skreen->text();
    eq.chop(1);
    ui->l_skreen->setText(eq);
}

void Calc::plus()
{
    QString eq = ui->l_skreen->text();
    QStringList list = eq.split(QLatin1Char('+'));
    double res = QString(list[0]).toDouble() + QString(list[1]).toDouble();
    ui->l_skreen->setText(QString::number(res));
}

void Calc::minus()
{
    QString eq = ui->l_skreen->text();
    QStringList list = eq.split(QLatin1Char('-'));
    double res = QString(list[0]).toDouble() - QString(list[1]).toDouble();
    ui->l_skreen->setText(QString::number(res));
}

void Calc::divide()
{
    QString eq = ui->l_skreen->text();
    QStringList list = eq.split(QLatin1Char('/'));
    double res = QString(list[0]).toDouble() / QString(list[1]).toDouble();
    ui->l_skreen->setText(QString::number(res));
}

void Calc::multiply()
{
    QString eq = ui->l_skreen->text();
    QStringList list = eq.split(QLatin1Char('x'));
    double res = QString(list[0]).toDouble() * QString(list[1]).toDouble();
    ui->l_skreen->setText(QString::number(res));
}

void Calc::result()
{
    QString eq = ui->l_skreen->text();
    for(int i = 0; i < eq.length(); i++)
    {
        if(eq[i] == '+')
        {
            plus();
            break;
        }
        if(eq[i] == '-')
        {
            minus();
            break;
        }
        if(eq[i] == 'x')
        {
            multiply();
            break;
        }
        if(eq[i] == '/')
        {
            divide();
            break;
        }
    }
}

