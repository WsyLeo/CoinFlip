#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    void initData();
    void initWidget();
    void connectSig();
protected:
    void paintEvent(QPaintEvent *ev);

private:
    Ui::MainScene *ui;
    MyPushButton *startBtn;
    ChooseLevelScene *mChooseLevelScene;
};
#endif // MAINSCENE_H
