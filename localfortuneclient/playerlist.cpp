#include "playerlist.h"

PlayerList::PlayerList(QObject *parent) : QObject(parent)
{
//    mItems.append({ true, QStringLiteral("Wash the car") });
//    mItems.append({ false, QStringLiteral("Fix the sink") });
}

QVector<Player> PlayerList::items() const
{
    return mItems;
}

bool PlayerList::setItemAt(int index, const Player &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const Player &oldItem = mItems.at(index);
    if (item.name == oldItem.name && item.score == oldItem.score)
        return false;

    mItems[index] = item;
    return true;
}

void PlayerList::appendItem(Player item)
{
    emit preItemAppended();
    mItems.append(item);
    emit postItemAppended();
}

void PlayerList::removeCompletedItems()
{
//    for (int i = 0; i < mItems.size(); ) {
//        if (mItems.at(i).done) {
//            emit preItemRemoved(i);

//            mItems.removeAt(i);

//            emit postItemRemoved();
//        } else {
//            ++i;
//        }
//    }
}
