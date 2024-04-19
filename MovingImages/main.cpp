#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication appl(argc, argv);// создание объекта приложения Qt
    Window win;//создаем окно приложения
    win.show();//отображение окна на экране
    return appl.exec();// запуск цикла обработки событий и возврат управления
}
