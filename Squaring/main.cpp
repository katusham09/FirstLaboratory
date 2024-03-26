#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);// создание объекта приложения Qt
    Win win(0);//создаем окно приложения
    win.show();//отображение окна на экране
    return app.exec();// запуск цикла обработки событий и возврат управления
}
