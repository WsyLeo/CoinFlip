#include "chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    initWidget();
    initData();
    connectSig();
}

void ChooseLevelScene::initData()
{
    bar = menuBar();
    setMenuBar(bar);
    startMenu = bar->addMenu(tr("开始"));
    quitAction = startMenu->addAction(tr("退出"));

    backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move((this->width() - backBtn->width()), (this->height() - backBtn->height()));
}

void ChooseLevelScene::initWidget()
{
    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle(tr("选择关卡场景"));
}

void ChooseLevelScene::connectSig()
{
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    connect(backBtn, &MyPushButton::clicked, [=](){
        QTimer::singleShot(500, this, [=](){
            emit chooseSceneBack();
        });
    });

    //创建按钮矩阵
    for (int i = 0; i < 20; i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4 * 70, 130 + i/4 * 80);

        connect(menuBtn, &MyPushButton::clicked, [=](){
            QString str = QString("您选择的是第 %1 关").arg(i+1);
            qDebug() << str;

            this->hide();
            //进来new
            mPlayScene = new PlayScene(i+1);
            mPlayScene->show();

            connect(mPlayScene, &PlayScene::chooseSceneBack, this, [=](){
                this->show();
                //删除
                delete mPlayScene;
                mPlayScene = nullptr;
            });
        });

        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + i%4 * 70, 130 + i/4 * 80);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        //设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev)
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}
