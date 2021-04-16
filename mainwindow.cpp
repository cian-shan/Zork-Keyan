#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include <QPixmap>
#include <QApplication>
#include <QInputDialog>
#include <QLabel>

ZorkUL game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_North_clicked(){
    ui->outputbox->setText(game.play(Command("go","north")));
}
void MainWindow::on_South_clicked(){
    ui->outputbox->setText(game.play(Command("go","south")));
}
void MainWindow::on_East_clicked(){
    ui->outputbox->setText(game.play(Command("go","east")));
}
void MainWindow::on_West_clicked(){
    ui->outputbox->setText(game.play(Command("go","west")));
}

void MainWindow::on_pushButton_Action1_clicked()
{
    // activate action 1 if in room (x)
}

void MainWindow::on_pushButton_Action2_clicked()
{
    // activate action 2 if in room (x)
}

void MainWindow::on_pushButton_Action3_clicked()
{
    // activate action 3 in room (x)
}