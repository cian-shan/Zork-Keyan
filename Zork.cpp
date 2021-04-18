/*  Moving North will hurt
 *  Items may heal or hurt you
 *  Room H will win the game
 */

#include "Zork.h"
#include "ui_zork.h"

Zork::Zork(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zork)
{
    ui->setupUi(this);
    // Hide my take buttons by default
    ui->TakeX->setVisible(false);
    ui->TakeY->setVisible(false);

    game.createRooms();

    takeButtons();
    string charName = (QInputDialog::getText(parent,"Character Customisation","Enter your name:")).toStdString();
    player.setName(charName);
    ui->outputText->append(game.printWelcome(player.getName()));
    ui->healthBar->setValue(player.health);
    ui->outputText_inventory->setText(QString::fromStdString(player.longDescription()));
    ui->outputText_map->setText(game.map());
}

Zork::~Zork()
{
    delete ui;
}


void Zork::gameOver(string title, string body, string desc){
    QMessageBox msgBox;
    msgBox.setWindowTitle(QString::fromStdString(title));
    msgBox.setText(QString::fromStdString(body) + QString::fromStdString(desc));
    QPushButton *abortButton = msgBox.addButton(QMessageBox::Close);

    msgBox.exec();
    if (msgBox.clickedButton() == abortButton) {
        QApplication::quit();
    }
}

void Zork::gameWon(string desc){
    gameOver("Game Over", "You've Won!\n", desc);

}

void Zork::gameLost(string desc){
    gameOver("Game Over !", "You've Lost!\n", desc);
}

void Zork::checkWin(){
    if(game.currentRoom->type=="win")
        gameWon("The door swings open to reveal the light of the outside world, you take your first steps towards it and see a green meadow, Congratulations, You've escaped !");
}

void Zork::on_teleport_clicked()
{
    ui->outputText->append("You feel strange, as the room around you shifts and changes, you've been teleported !");
    game.teleport();
    takeButtons();
    ui->outputText->append(QString::fromStdString(game.currentRoom->longDescription()));
    checkWin();
}

void Zork::go(string direction) {
    ui->outputText->append(game.go(direction));
    checkWin();
    takeButtons();
}

void Zork::healthChange(int delta){
    ui->outputText->append(QString::fromStdString(to_string(delta)));
    if(delta < 0)
        ui->outputText->append("The liquid burns, You feel nauseous and weak...");
    else if (delta > 0)
        ui->outputText->append("The liquid gives you a strange feeling, you feel energised and more powerful !");

    player.health += delta;
    if(player.health<1){
        ui->healthBar->setValue(0);
        gameLost("You splutter and choke on the liquid as you feel a burning sensation throughout your body, you draw your final breath; You are Dead !");
    }
    ui->healthBar->setValue(player.health);
}

void Zork::on_goNorth_clicked() {
    go("north");
}

void Zork::on_goEast_clicked(){
    go("east");
}

void Zork::on_goSouth_clicked(){
    go("south");
}

void Zork::on_goWest_clicked(){
    go("west");
}


void Zork::on_TakeX_clicked()
{
     takeItem(ui->TakeX);
}

void Zork::on_TakeY_clicked()
{
    takeItem(ui->TakeY);
}

void Zork::on_TakeZ_clicked()
{
    takeItem(ui->TakeZ);
}

void Zork::takeItem(QPushButton* takeBtn){
    string itemText = (takeBtn->text()).toStdString();
    string r = "Take ";
    string::size_type i = itemText.find(r);
    if (i != std::string::npos)
       itemText.erase(i, r.length());

    Item * toAdd = game.currentRoom->getItemFromString(itemText);
    player.addItem(toAdd);
    game.currentRoom->removeItemFromRoom(itemText);
    takeBtn->setVisible(false);

    healthChange((toAdd)->getValue());
    ui->outputText_inventory->setText(QString::fromStdString(player.longDescription()));
}

void Zork::takeButtons(){

    ui->TakeX->setVisible(false);
    ui->TakeY->setVisible(false);
    ui->TakeZ->setVisible(false);

    // check if room has (max 3) items
    // cycle through list of items, activating buttons and setting text to item description
    if(game.currentRoom->numberOfItems()!=0){
        if(game.currentRoom->numberOfItems()>0){
            ui->TakeX->setVisible(true);
            ui->TakeX->setText(QString::fromStdString("Take " + game.currentRoom->itemsInRoom[0]->getShortDescription()));
        }
        if(game.currentRoom->numberOfItems()>1){
            ui->TakeY->setVisible(true);
            ui->TakeY->setText(QString::fromStdString("Take " + game.currentRoom->itemsInRoom[1]->getShortDescription()));
        }
        if(game.currentRoom->numberOfItems()>2){
            ui->TakeZ->setVisible(true);
            ui->TakeZ->setText(QString::fromStdString("Take " + game.currentRoom->itemsInRoom[2]->getShortDescription()));
        }
    }
}
