#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include <QObject>
#include <QVector>
#include <algorithm>

struct Player
{
//    bool done;
//    QString description;
    QString name;
    int score;
    QString avatar;
    int status;
//    0: waiting, not in turn
//    1: start, in turn
//    2: start, die
};

class PlayerList : public QObject
{
    Q_OBJECT
public:
    explicit PlayerList(QObject *parent = nullptr);

    QVector<Player> items() const;

    bool setItemAt(int index, const Player &item);
    void sortPlayer();

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(Player item);
    void removeCompletedItems();
    void resetItems();

private:
    QVector<Player> mItems;
};

#endif // PLAYERLIST_H
