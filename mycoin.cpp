#include "mycoin.h"


MyCoin::MyCoin(QString path):
    mPath(path)
{
    initWidget();
    initData();
    connectSig();
}

void MyCoin::initData()
{
    QPixmap pix;
    bool ret = pix.load(mPath);
    if(!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(mPath);
        qDebug() << str;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QpushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyCoin::initWidget()
{

}

void MyCoin::connectSig()
{

}
