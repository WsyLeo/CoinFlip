#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include "mypushbutton.h"
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNum);
    void initData();
    void initWidget();
    void connectSig();

protected:
    void paintEvent(QPaintEvent *ev);
signals:
    void chooseSceneBack();
public slots:

private:
    int levelIndex;
    QAction *quitAction;
    QMenu *startMenu;
    QMenuBar *bar;
    MyPushButton *backBtn;
};

#endif // PLAYSCENE_H
