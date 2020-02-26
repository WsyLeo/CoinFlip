#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initData();
    initWidget();
    connectSig();
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initData()
{
    QString normalImg = ":/res/MenuSceneStartButton.png";
    startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move( this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7 );

    mChooseLevelScene = new ChooseLevelScene();
}

void MainScene::initWidget()
{
    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币");
}

void MainScene::connectSig()
{
    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });

    connect(startBtn, &MyPushButton::clicked, [=](){
        startBtn->zoomDown();
        startBtn->zoomUp();

        QTimer::singleShot(500, this, [=](){
            this->hide();
            mChooseLevelScene->show();
        });
    });

    connect(mChooseLevelScene, &ChooseLevelScene::chooseSceneBack, this, [=](){
        mChooseLevelScene->hide();
        this->show();
    });

}

void MainScene::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);   //缩放
    painter.drawPixmap(10, 30, pix);

    Q_UNUSED(ev)
}

