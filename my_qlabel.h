#ifndef MY_QLABEL_H
#define MY_QLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>

//this Qlabel subclass is used for the purpose of using click event which is not available in default Qlabel
//so I have creatd my own class in which mousepressevent is used
class my_qlabel : public QLabel
{
    Q_OBJECT
public:
    explicit my_qlabel(QWidget *parent = nullptr, int id = 0);
    void mousePressEvent(QMouseEvent *ev);

    int x,y;
    int id;

signals:
    void Mouse_Pressed(int id);

public slots:
};

#endif // MY_QLABEL_H
