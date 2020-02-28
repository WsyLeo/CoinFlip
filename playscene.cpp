#include "playscene.h"


PlayScene::PlayScene(int levelNum)
{
    this->levelIndex = levelNum;
    initWidget();
    initData();
    connectSig();
}

void PlayScene::initData()
{
    bar = menuBar();
    setMenuBar(bar);
    startMenu = bar->addMenu(tr("开始"));
    quitAction = startMenu->addAction(tr("退出"));

    backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move((this->width() - backBtn->width()), (this->height() - backBtn->height()));

    QLabel *label = new QLabel();
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString strLevel = QString("Level:%1").arg(this->levelIndex);
    label->setFont(font);
    label->setText(strLevel);
    label->setGeometry(30, this->height() - 50, 120, 50);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
           QPixmap pix= QPixmap(":/res/BoardNode.png");
           QLabel *coinLabel = new QLabel(this);
           coinLabel->setGeometry(0, 0, pix.width(), pix.height());
           coinLabel->setPixmap(pix);
           coinLabel->move(57 + i*50, 200 + j*50);

           mMyCoin = new MyCoin(":/res/Coin0001.png");
           mMyCoin->setParent(this);
           mMyCoin->move(59 + i*50, 204 + j*50);
        }
    }
}

void PlayScene::initWidget()
{
    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle(tr("翻金币场景"));
}

void PlayScene::connectSig()
{
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    connect(backBtn, &MyPushButton::clicked, [=](){
        QTimer::singleShot(500, this, [=](){
            emit chooseSceneBack();
        });
    });
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
