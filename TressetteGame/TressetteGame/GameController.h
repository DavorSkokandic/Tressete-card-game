#pragma once

#include <QObject>
#include <QQuickView>

class GameController : public QObject {
    Q_OBJECT
public:
    GameController(QObject* parent = nullptr);

public slots:
    void openPlayingTable();
    void openRulesWindow();
    void exitGame();

private:
    QQuickView* rulesView = nullptr;
    QQuickView* gameView = nullptr;
};