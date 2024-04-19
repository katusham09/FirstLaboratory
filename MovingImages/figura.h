#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>
#include <QWidget>

class Figura //базовый класс фигуры
{
protected:
    int x,y,halflen,dx,dy; //x,y - центр фигуры; halflen - размер фигуры; dx,dy - координаты точки котрая вращается
    virtual void draw(QPainter *Painter)=0;
    //виртуальная, для того, чтобы мы могли её переопределить в других класс
public:
    Figura(int X,int Y,int Halflen): //конструктор
        x(X),y(Y),halflen(Halflen){}//инициализируем значения

    void move(float Alpha,QPainter *Painter);//поворот фигуры
};

class MyLine:public Figura //наследуемся от класса Figura
{
protected:
    void draw(QPainter *Painter);//метод для рисования линии
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){} //конструктор, который вызывает конструктор предка
};

class MyRect:public Figura
{
protected:
    void draw(QPainter *Painter);//метод для рисования квадрата
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};
#endif
