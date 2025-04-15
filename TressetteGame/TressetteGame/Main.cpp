#include <iostream>
#include "Cards.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext> 
#include "GameController.h"

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Create an instance of your GameController
    GameController gameController;

    // Expose the gameController object to QML
    engine.rootContext()->setContextProperty("gameController", &gameController);

    engine.addImportPath("qrc:/"); // Good to have
    engine.addImportPath("C:/Qt/6.9.0/msvc2022_64/qml"); // Replace with your actual Qt install path
    QStringList importPaths = engine.importPathList();
   // qDebug() << "QML Import Paths:";
   // for (const auto& path : importPaths)
   //     qDebug() << "  " << path;
    engine.load(QUrl(QStringLiteral("qrc:/TressetteGame/Main_design.qml")));

    if (engine.rootObjects().isEmpty()) {
        qWarning() << "QML root object not loaded!";
        return -1;
    }
	QObject* rootObject = engine.rootObjects().first();
	if (!rootObject) {
		qWarning() << "Root object is null!";
		return -1;
	}

	QObject::connect(rootObject, SIGNAL(openPlayingTable()), &gameController, SLOT(openPlayingTable()));//Sending signal to open the playing table
	QObject::connect(rootObject, SIGNAL(openRulesWindow()), &gameController, SLOT(openRulesWindow()));//Sending signal to open the rules window
	QObject::connect(rootObject, SIGNAL(exitGame()), &gameController, SLOT(exitGame()));//Sending signal to exit the game

   
    return app.exec();
}