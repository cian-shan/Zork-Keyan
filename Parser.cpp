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
    ui->textBrowser_Health->setText(QString::number(getCharHP()));
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
