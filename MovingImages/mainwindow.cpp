#include "mainwindow.h"

Window::Window()
{
    setWindowTitle("Обработка событий");//устанавливаем заголовок окна
    area = new Area( this );//Создается новый объект класса Area
    btn = new QPushButton("Завершить",this );//Создаем новую кнопку с надписью "Завершить"

    QVBoxLayout *layout = new QVBoxLayout(this);//Создаем новый вертикальный менеджер компоновки
    layout->addWidget(area);
    layout->addWidget(btn);

    //Сигнально-слотовые соединения
    //connect(&Отправитель, &Class_1::mysignal, &Адресат, &Class_2::myslot);
    connect(btn,&QPushButton::clicked,this,&Window::close);//при нажатии на кнопку btn, будет вызываться слот close(), что приведет к закрытию окна.
};
