#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "my_qlabel.h"
#include <QLine>


namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void createHomeScreen();
    void createGameScreen();

    void hideHomeScreen(bool value);
    void hideGameScreen(bool value);

    void startGameFunction();
    bool validturn(int id);
    int  winnerCheck();

public slots:
    void lblPressed(int id);

private slots:
    void on_bttnStart_clicked();

    void on_bttnBack_clicked();

    void on_bttnNew_clicked();

private:
    int w,h;

    //for home
    QLabel *title1;
    QLabel *title2;
    QLabel *title3;
    QLabel *titleimg1;
    QLabel *titleimg2;
    //QPushButton *bttnStart;

    //for game screen
    //QPushButton *bttnNew;
    //QPushButton *bttnBack;

    QLabel *lbltitle4;
    QLabel *lbltitle5;
    QLabel *lbltitle6;
    QLabel *lbltitle7;
    QLabel *lblturn;

    QLabel *lblnScore;
    QLabel *lblcScore;

    int scoreN;
    int scoreC;
    int turnCount;
    int firstTurn;
    my_qlabel *lbl[9];
    QLine *lne[8];
    int matrix[3][3];



};

#endif // MAINWINDOW_H
