#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initialize main window size
    w = 300;
    h = 500;


    scoreC = 0;
    scoreN = 0;

    //total number of turn inits
    turnCount = 0;

    //init matrix for comparison
    for (int i =0; i < 3; i++)
        for (int j =0; j < 3; j++)
            matrix[i][j] = 0;

    //setting color and size
    this->setGeometry(0,0,w,h);
    this->setMaximumSize(300,500);
    this->setFixedSize(300,500);
    this->setStyleSheet("background-color: rgb(46, 52, 54);");

    //create homescreen items
    createHomeScreen();

    //create game screen items
    createGameScreen();

    //show home screen and hide game screen at start
    hideHomeScreen(false);
    hideGameScreen(true);

    scoreC = 0;
    scoreN = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createHomeScreen()
{

    //initialize all labels and setting size programmically
    title1 = new QLabel (this) ;
    title1->setText("noughts");
    title1->setGeometry(40,200,100,50);
    title1->setStyleSheet("color: rgb(245, 121, 0); font: 75 italic 22pt ""Carlito"";");
    title1->setParent(this);

    title2 = new QLabel (this) ;
    title2->setText("+");
    title2->setGeometry(150,200,50,50);
    title2->setStyleSheet("color: rgb(255, 255, 255); font: 75 italic 18pt ""Carlito"";");
    title2->setParent(this);

    title3 = new QLabel (this) ;
    title3->setText("crosses");
    title3->setGeometry(185,200,90,50);
    title3->setStyleSheet("color: rgb(184,57,142); font: 75 italic 22pt ""Carlito"";");
    title3->setParent(this);


    ui->bttnStart->setText("Start Game");
    ui->bttnStart->setGeometry(50,400,200,50);
    ui->bttnStart->setStyleSheet("color: rgb(46,52,54); background-color: rgb(238, 238, 236); font: 75 italic 14pt ""Carlito"";");
    ui->bttnStart->setParent(this);
    ui->bttnStart->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                   "stop: 0 white, stop: 1 grey);"
                                                   "border-style: solid;"
                                                   "border-width: 2px;"
                                                   "border-color: black;"
                                                   "border-radius: 15px;}"));

    titleimg1 = new QLabel (this) ;
    QPixmap pix("nought-01.png");
    titleimg1->setPixmap(pix);
    titleimg1->setGeometry(60,250,50,50);
    titleimg1->setScaledContents(true);

    titleimg2 = new QLabel (this) ;
    QPixmap pix2("cross-01.png");
    titleimg2->setPixmap(pix2);
    titleimg2->setGeometry(200,250,50,50);
    titleimg2->setScaledContents(true);


}

void MainWindow::hideHomeScreen(bool value)
{

    title1->setHidden(value);
    title2->setHidden(value);
    title3->setHidden(value);
    titleimg1->setHidden(value);
    titleimg2->setHidden(value);
    ui->bttnStart->setHidden(value);
}


void MainWindow::hideGameScreen(bool value)
{

    for (int i = 0; i < 9; ++i) {
        lbl[i]->setHidden(value);
    }

    ui->bttnNew->setHidden(value);

    ui->bttnBack->setHidden(value);

    lbltitle4->setHidden(value);


    lbltitle6->setHidden(value);

    lblcScore->setHidden(value);


    lbltitle5->setHidden(value);

    lbltitle7->setHidden(value);

    lblnScore->setHidden(value);

    lblturn->setHidden(value);

}

void MainWindow::createGameScreen()
{

    //init array of labels
    for (int i = 0; i < 9; ++i) {

        lbl[i] = new my_qlabel(this,i);

        //location setting
        lbl[i]->setGeometry((i%3)*50 + 75, (i/3)*50 + 150, 45, 45 );

        //setting style
        lbl[i]->setFrameStyle(QFrame::Box);

        //setting contents of images within its boundaries
        lbl[i]->setScaledContents(true);

        //connect press event of label with a functions
        connect(lbl[i],SIGNAL(Mouse_Pressed(int)),this,SLOT(lblPressed(int)));
        matrix[i/3][i%3] = 0;

    }

    //ui->bttnNew = new QPushButton (this);
    ui->bttnNew->setGeometry(30,400,110,30);
    ui->bttnNew->setText("New Game");
    ui->bttnNew->setStyleSheet("color: rgb(238, 238, 236);");
    ui->bttnNew->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                 "stop: 0 white, stop: 1 grey);"
                                                 "border-style: solid;"
                                                 "border-width: 2px;"
                                                 "border-color: black;"
                                                 "border-radius: 15px;}"));

    //ui->bttnBack = new QPushButton (this);
    ui->bttnBack->setGeometry(160,400,110,30);
    ui->bttnBack->setText("Back");
    ui->bttnBack->setStyleSheet("color: rgb(238, 238, 236);");
    ui->bttnBack->setStyleSheet(QString::fromUtf8("QPushButton{background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                                  "stop: 0 white, stop: 1 grey);"
                                                  "border-style: solid;"
                                                  "border-width: 2px;"
                                                  "border-color: black;"
                                                  "border-radius: 15px;}"));

    QPixmap p("cross-01.png");
    lbltitle4 = new QLabel (this) ;
    lbltitle4->setPixmap(p);
    lbltitle4->setGeometry(20,50,20,20);
    lbltitle4->setScaledContents(true);


    lbltitle6 = new QLabel (this) ;
    lbltitle6->setGeometry(50,55,120,20);
    lbltitle6->setText("Crosses Score : ");
    lbltitle6->setStyleSheet("color: rgb(238, 238, 236); font: 75 italic 10pt ""Carlito"";");

    lblcScore = new QLabel (this) ;
    lblcScore->setGeometry(130,50,30,30);
    lblcScore->setText("0");
    lblcScore->setStyleSheet("color: rgb(238, 238, 236); font: 75 italic 10pt ""Carlito"";");


    QPixmap q("nought-01.png");
    lbltitle5 = new QLabel (this) ;
    lbltitle5->setPixmap(q);
    lbltitle5->setGeometry(150,50,20,20);
    lbltitle5->setScaledContents(true);

    lbltitle7 = new QLabel (this) ;
    lbltitle7->setGeometry(180,55,120,20);
    lbltitle7->setText("Nought Score : ");
    lbltitle7->setStyleSheet("color: rgb(238, 238, 236); font: 75 italic 10pt ""Carlito"";");

    lblnScore = new QLabel (this) ;
    lblnScore->setGeometry(270,50,30,30);
    lblnScore->setText("0");
    lblnScore->setStyleSheet("color: rgb(238, 238, 236); font: 75 italic 10pt ""Carlito"";");

    lblturn = new QLabel (this) ;
    lblturn->setGeometry(80,80,150,50);
    lblturn->setText("Nought's Turn");
    lblturn->setStyleSheet("color: rgb(238, 238, 236); font: 75 italic 16pt ""Carlito"";");


}
void MainWindow::startGameFunction()
{

    hideHomeScreen(true);
    hideGameScreen(false);
}

void MainWindow::lblPressed(int id)
{
    //check if same block/label is not clicked and maximum count in a game is 9
    if(validturn(id) && turnCount <= 8)
    {
        //noughts turn are even
        if(turnCount % 2 == firstTurn)
        {
            //matrix or array is filled with a digit 10 at the place of click
            matrix[id%3][id/3] = 10;

            //read image from file
            QPixmap p("nought-01.png");

            //set image to clicked place on label
            lbl[id]->setPixmap(p);

            //update turn label
            lblturn->setText("Cross's Turn");

            //increment in count
            turnCount++;

            //check for winner
            int w = winnerCheck();

            //if nought win
            if(w == 10)
            {
                //increament in score count
                scoreN++;

                //display label
                lblnScore->setText(QString::number(scoreN));
                turnCount = 9;

                for (int i =0; i < 9; i++)
                    lbl[i]->setDisabled(true);

            }
        }

        //cross turn are odd
        else
        {
            matrix[id%3][id/3] = 1;
            QPixmap p("cross-01.png");
            lbl[id]->setPixmap(p);
            lblturn->setText("Nought's Turn");
            turnCount++;
            int w = winnerCheck();
            if(w == 1)
            {
                scoreC++;
                lblcScore->setText(QString::number(scoreC));
                turnCount = 9;

                for (int i =0; i < 9; i++)
                    lbl[i]->setDisabled(true);

            }
        }

//        for (int i =0; i < 3; i++)
//        {
//            for (int j =0; j < 3; j++)
//            {
//                if(matrix[i][j] != 0)
//                {
//                    if(i==2 && j == 2)
//                    {
//                        if(turnCount == 10)
//                        {
//                            lblturn->setText("Match Drawn");
//                            for (int i =0; i < 9; i++)
//                                lbl[i]->setDisabled(true);
//                        }
//                    }
//                    else
//                    {
//                    break;
//                    }
//                }
//            }
//        }

        if((winnerCheck() == 0) && (turnCount == 9))
        {
            lblturn->setText("Game Drawn");
            for (int i =0; i < 9; i++)
                lbl[i]->setDisabled(true);


        }
    }
    else
    {

        if(validturn(id)== false)
        {
            lblturn->setText("Invalid Turn");
        }


    }
}

void MainWindow::on_bttnStart_clicked()
{
    //show game screen
    startGameFunction();
    firstTurn = rand() % 2;

    if(turnCount % 2 == firstTurn)
        lblturn->setText("Nought's Turn");
    else
        lblturn->setText("Cross's Turn");
}

void MainWindow::on_bttnBack_clicked()
{
    //go back to main screen
    turnCount = 0;
    scoreC = 0;
    scoreN = 0;
    lblnScore->setText(QString::number(scoreN));
    lblcScore->setText(QString::number(scoreC));

    for (int i =0; i < 3; i++)
        for (int j =0; j < 3; j++)
            matrix[i][j] = 0;

    for (int i =0; i < 9; i++)
        lbl[i]->clear();


    for (int i =0; i < 9; i++)
        lbl[i]->setDisabled(false);



    hideHomeScreen(false);
    hideGameScreen(true);
}

void MainWindow::on_bttnNew_clicked()
{
    //reset everything for new game
    turnCount = 0;

    for (int i =0; i < 3; i++)
        for (int j =0; j < 3; j++)
            matrix[i][j] = 0;

    for (int i =0; i < 9; i++)
        lbl[i]->clear();


    for (int i =0; i < 9; i++)
        lbl[i]->setDisabled(false);

    firstTurn = rand() % 2;

    if(turnCount % 2 == firstTurn)
        lblturn->setText("Nought's Turn");
    else
        lblturn->setText("Cross's Turn");
}


bool MainWindow::validturn(int id)
{

    //matrix is initially filled with 0s, so if matrix is filled with other than a zero,
    //that means it is already filled
    if(matrix[id%3][id/3] != 0)
        return false;
    else
        return true;
}



int MainWindow::winnerCheck()
{

    //conditions for nought as winner
    if(matrix[0][0] == 10 && matrix[0][1] == 10 && matrix[0][2] == 10)
    {
        lblturn->setText("Nought  Won");
        return 10;
    }
    if(matrix[1][0] == 10 && matrix[1][1] == 10 && matrix[1][2] == 10)
    {
        lblturn->setText("Nought  Won");
        return 10;
    }
    if(matrix[2][0] == 10 && matrix[2][1] == 10 && matrix[2][2] == 10)
    {
        lblturn->setText("Nought  Won");
        return 10;
    }
    if(matrix[0][0] == 10 && matrix[1][0] == 10 && matrix[2][0] == 10)
    {
        lblturn->setText("Nought  Won");
        return 10;
    }
    if(matrix[0][1] == 10 && matrix[1][1] == 10 && matrix[2][1] == 10)
    {
        lblturn->setText("Nought  Won");
        return 10;
    }
    if(matrix[0][2] == 10 && matrix[1][2] == 10 && matrix[2][2] == 10)
    {
        lblturn->setText("Nought  Won");
        return 10;
    }
    if(matrix[0][0] == 10 && matrix[1][1] == 10 && matrix[2][2] == 10)
    {
        lblturn->setText("Nought  Won");
        return 10;
    }
    if(matrix[2][0] == 10 && matrix[1][1] == 10 && matrix[0][2] == 10)
    {
        lblturn->setText("Nought  Won");
        return 10;
    }

    //conditions for cross as winner
    if(matrix[0][0] == 1 && matrix[0][1] == 1 && matrix[0][2] == 1)
    {
        lblturn->setText("Cross  Won");
        return 1;
    }
    if(matrix[1][0] == 1 && matrix[1][1] == 1 && matrix[1][2] == 1)
    {
        lblturn->setText("Cross  Won");
        return 1;
    }
    if(matrix[2][0] == 1 && matrix[2][1] == 1 && matrix[2][2] == 1)
    {
        lblturn->setText("Cross  Won");
        return 1;
    }
    if(matrix[0][0] == 1 && matrix[1][0] == 1 && matrix[2][0] == 1)
    {
        lblturn->setText("Cross  Won");
        return 1;
    }
    if(matrix[0][1] == 1 && matrix[1][1] == 1 && matrix[2][1] == 1)
    {
        lblturn->setText("Cross  Won");
        return 1;
    }
    if(matrix[0][2] == 1 && matrix[1][2] == 1 && matrix[2][2] == 1)
    {
        lblturn->setText("Cross  Won");
        return 1;
    }
    if(matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1)
    {
        lblturn->setText("Cross  Won");
        return 1;
    }
    if(matrix[2][0] == 1 && matrix[1][1] == 1 && matrix[0][2] == 1)
    {
        lblturn->setText("Cross  Won");
        return 1;
    }

    return 0;
}
