#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class Counter:public QLineEdit  //создаем новый класс редактируемой строки
{
    Q_OBJECT  // макрос Qt, обеспечивающий корректное создание сигналов и слотов
public:
    Counter(const QString & contents, QWidget *parent=0):
        QLineEdit(contents,parent){}
    //конструктор. contents - начальный текст,который мы зададим и parent-родитель
signals:
    void tick_signal();//объявляем сигнал
public slots:
    void add_one()//слот add_one() увеличивает число на единицу, проверяет, кратно ли оно 5, и если да, отправляет сигнал tick_signal().
    {
        QString str=text();// в str записываем текст из текстового поля
        int r=str.toInt();//Преобразует текст str в целое число и сохраняет его в переменную r.
        if (r!=0 && r%5 ==0) emit tick_signal();//если число кратно 5, то вызываем сигнал tick_signal
        r++;//увеличиваем на единицу
        str.setNum(r);//Преобразует число r обратно в строку и сохраняем его в переменную str.
        setText(str);//Устанавливает новое значение текстового поля на основе изменённой строки str.
    }
};

class Win: public QWidget //новый класс окна
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;//метки для отображения текста
    Counter *edit1,*edit2;//Указатели на объекты класса Counter для редактирования текста
    QPushButton *calcbutton;//кнопка для выполнения операции
    QPushButton *exitbutton;//кнопка выхода
public:
    Win(QWidget *parent = 0);//конструктор
};
#endif
