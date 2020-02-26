#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPaintEvent>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void initData();
    void initWidget();
    void connectSig();
signals:
    void chooseSceneBack();

public slots:
protected:
    void paintEvent(QPaintEvent *ev);
private:
    QAction *quitAction;
    QMenu *startMenu;
    QMenuBar *bar;
    MyPushButton *backBtn;
    PlayScene *mPlayScene;
};

#endif // CHOOSELEVELSCENE_H
