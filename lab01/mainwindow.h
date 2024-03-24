#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
//класс фигур
class Figura
{
protected:
int x,y,halflen,dx,dy,r;
virtual void draw(QPainter *Painter)=0;
public:
Figura(int X,int Y,int Halflen):
x(X),y(Y),halflen(Halflen){}
void move(float Alpha,QPainter *Painter);
};
//класс линиии наследник от фигуры
class MyLine:public Figura
{
protected:
void draw(QPainter *Painter);
public:
MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
};
class MyRect:public Figura
{
protected:
void draw(QPainter *Painter);
public:
MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};
#endif
