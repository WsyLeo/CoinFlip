#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString path);
    void initData();
    void initWidget();
    void connectSig();

signals:

public slots:

private:
    QString mPath;
};

#endif // MYCOIN_H
