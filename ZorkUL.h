#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "mainwindow.h"
#include <iostream>
#include <string>
#include <QApplication>

using namespace std;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
	void createRooms();
	void printWelcome();
    QString processCommand(Command command);
	void printHelp();
    string goRoom(Command command);
    void createItems();
    void displayItems();
    string take(Command command);
public:
	ZorkUL();
    QString play(Command incommand);
    QString go(string direction);
};

#endif /*ZORKUL_H_*/
