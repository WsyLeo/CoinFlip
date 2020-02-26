#include "playscene.h"


PlayScene::PlayScene(int levelNum)
{
    this->levelIndex = levelNum;

    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle(tr("翻金币场景"));

    bar = menuBar();
    setMenuBar(bar);
    startMenu = bar->addMenu(tr("开始"));
    quitAction = startMenu->addAction(tr("退出"));

    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move((this->width() - backBtn->width()), (this->height() - backBtn->height()));

    connect(backBtn, &MyPushButton::clicked, [=](){
        QTimer::singleShot(500, this, [=](){
            emit chooseSceneBack();
        });
    });

    QLabel *label = new QLabel();
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString strLevel = QString("Level:%1").arg(this->levelIndex);
    label->setFont(font);
    label->setText(strLevel);
    label->setGeometry(30, this->height() - 50, 120, 50);


}

void PlayScene::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev)
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5, 30, pix.width(), pix.height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}
