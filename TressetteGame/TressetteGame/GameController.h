#pragma once

#include <QObject>
#include <QQuickView>

class GameController : public QObject {
    Q_OBJECT
public:
    GameController(QObject* parent = nullptr);

public slots:
    void playClicked();
    void rulesClicked();
    void exitClicked();

private:
    QQuickView* rulesView = nullptr;
    QQuickView* gameView = nullptr;
};