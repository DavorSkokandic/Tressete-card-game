#include "GameController.h"
#include <QUrl>
#include <QGuiApplication>

GameController::GameController(QObject* parent) : QObject(parent) {}

void GameController::openPlayingTable() {
    if (!gameView) {
        gameView = new QQuickView();
        gameView->setSource(QUrl("qrc:/PlayingTable.qml"));
        gameView->setTitle("Tressette - Playing Table");
        gameView->setWidth(1920); // Example size
        gameView->setHeight(1080);
        gameView->show();
    }
    else {
        gameView->show();
    }
    qDebug() << "Opening playing table...";
    // Initialize game state if needed
}

void GameController::openRulesWindow() {
    if (!rulesView) {
        rulesView = new QQuickView();
        rulesView->setSource(QUrl("qrc:/Rules.qml"));
        rulesView->setTitle("Tressette - Rules");
        rulesView->setWidth(1920); // Example size
        rulesView->setHeight(1080);
        //rulesView->setModal(true); // If you want it to be a modal dialog
        rulesView->show();
    }
    else {
        rulesView->show();
    }
    qDebug() << "Opening rules window...";
}

void GameController::exitGame() {
    qDebug() << "Exiting game...";
    QGuiApplication::quit();
}
