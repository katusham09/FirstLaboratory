#include "mainwindow.h"

Win::Win(QWidget *parent):QWidget(parent)
{
    setWindowTitle("Счетчик");
    // Создаем метки для отображения текста и указываем родительский виджет (this)
    label1 = new QLabel("Cчет по 1",this);
    label2 = new QLabel("Cчет по 5",this);
    // Создаем объекты класса Counter для редактирования текста и указываем начальный текст и родительский виджет (this)
    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);
    // Создаем кнопки с текстом и указываем родительский виджет (this)
    calcbutton = new QPushButton("+1",this);
    exitbutton = new QPushButton("Выход",this);

    QHBoxLayout *layout1 = new QHBoxLayout();//горизонтальный компоновщик – управляет расположением виджетов в окне по горизонтали;
    layout1->addWidget(label1);
    layout1->addWidget(label2);
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);
    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(calcbutton);
    layout3->addWidget(exitbutton);
    // Создаем вертикальный компоновщик для объединения всех горизонтальных компоновщиков
    QVBoxLayout *layout4 = new QVBoxLayout(this);//вертикальный компоновщик – управляет расположением виджетов в окне по вертикали;
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    edit1->setEnabled(false);
    edit2->setEnabled(false);

    //связь сигнала нажатия кнопки и слота закрытия окна
    //connect(&Отправитель, &Class_1::mysignal, &Адресат, &Class_2::myslot);
    connect(calcbutton,&QPushButton::clicked,edit1,&Counter::add_one);//когда пользователь кликает на кнопку calcbutton, будет вызван слот add_one объекта edit1.
    connect(edit1,&Counter::tick_signal,edit2,&Counter::add_one);//когда сигнал tick_signal будет отправлен объектом edit1, будет вызван слот add_one объекта edit2.
    connect(exitbutton,&QPushButton::clicked,this,&Win::close);//Когда пользователь кликает на кнопку exitbutton, будет вызван слот close, что, вероятно, приведет к закрытию окна Win.
}
