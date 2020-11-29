#ifndef MsgLIST_H
#define MsgLIST_H

#include <QObject>
#include <QVector>

struct Msg
{
    QString timestamp;
    QString sender;
    QString content;
};

class MsgList : public QObject
{
    Q_OBJECT
public:
    explicit MsgList(QObject *parent = nullptr);

    QVector<Msg> items() const;

    bool setItemAt(int index, const Msg &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(Msg item);
    void removeCompletedItems();
    void resetItems();

private:
    QVector<Msg> mItems;
};

#endif // MsgLIST_H
