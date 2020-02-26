#include "mypushbutton.h"

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret;
    ret = pix.load(normalImgPath);
    if(!ret)
    {
        qDebug() << "图片加载失败！";
        return ;
    }

    this->setFixedSize(pix.width(), pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyPushButton::zoomDown()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //开始
    animation->start();
}

void MyPushButton::zoomUp()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *ev)
{
    if (this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret;
        ret = pix.load(this->pressImgPath);
        if(!ret)
        {
            qDebug() << "图片加载失败！";
            return ;
        }

        this->setFixedSize(pix.width(), pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    return QPushButton::mousePressEvent(ev);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if (this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret;
        ret = pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug() << "图片加载失败！";
            return ;
        }

        this->setFixedSize(pix.width(), pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    return  QPushButton::mouseReleaseEvent(ev);
}
