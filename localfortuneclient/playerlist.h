#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include <QObject>
#include <QVector>

struct Player
{
//    bool done;
//    QString description;
    QString name;
    int score;
    QString avatar;
};

class PlayerList : public QObject
{
    Q_OBJECT
public:
    explicit PlayerList(QObject *parent = nullptr);

    QVector<Player> items() const;

    bool setItemAt(int index, const Player &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(Player item);
    void removeCompletedItems();

private:
    QVector<Player> mItems;
};

#endif // PLAYERLIST_H
