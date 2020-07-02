#include <QLabel>
#include "my_qlabel.h"


//custom label class for obtaining clicked event on a label
my_qlabel::my_qlabel(QWidget *parent, int id) : QLabel(parent)
{
this->id = id;
}

void my_qlabel::mousePressEvent(QMouseEvent *ev)
{

    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pressed(this->id);
}




