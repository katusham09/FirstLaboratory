#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>


class Win:public QWidget // класс окна
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход
public:
    Win(QWidget *parent = 0); // конструктор
public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
};

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){} //конструктор
    virtual State validate(QString &str,int &pos)const //возвращает она State - состояние; QString &str - это наша строка, которую мы проверяем
    {
        return Acceptable; // метод всегда принимает вводимую строку
    }
//Поскольку в качестве сигнала завершения ввода мы собираемся использовать returnPressed()– сигнал нажатия клавиши Enter, кроме класса окна нам понадобится
//описать специальный класс валидатора StrValidator, наследуемый от класса QValidator.
//Объект этого класса, включающего метод проверки вводимой строки validate(), передается строчному редактору, осуществляющему ввод.
//При завершении ввода этот метод вызывается автоматически. Если этот метод возвращает Acceptable, то редактор
//ввода генерирует сигналы editingFinished()– завершение редактирования и
//returnPressed()– сигнал нажатия клавиши Enter. В противном случае эти сигналы не генерируются.
//Описываемый нами метод всегда принимает вводимую строку. Проверка же вводимой строки будет осуществляться позднее
};

#endif
