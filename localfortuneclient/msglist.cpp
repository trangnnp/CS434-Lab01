#include "msglist.h"

MsgList::MsgList(QObject *parent) : QObject(parent)
{
//    mItems.append({ true, QStringLiteral("Wash the car") });
//    mItems.append({ false, QStringLiteral("Fix the sink") });
}

QVector<Msg> MsgList::items() const
{
    return mItems;
}

bool MsgList::setItemAt(int index, const Msg &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const Msg &oldItem = mItems.at(index);
    if (item.timestamp == oldItem.timestamp && item.sender == oldItem.sender)
        return false;

    mItems[index] = item;
    return true;
}

void MsgList::appendItem(Msg item)
{
    emit preItemAppended();
    mItems.append(item);
    emit postItemAppended();
}

void MsgList::removeCompletedItems()
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

void MsgList::resetItems()
{
    for (int i = 0; i < mItems.size(); ) {
        emit preItemRemoved(i);
        mItems.removeAt(i);
        emit postItemRemoved();
     }
}
