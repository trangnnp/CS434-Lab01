#include "playerlist.h"

ToDoList::ToDoList(QObject *parent) : QObject(parent)
{
//    mItems.append({ true, QStringLiteral("Wash the car") });
//    mItems.append({ false, QStringLiteral("Fix the sink") });
}

QVector<ToDoItem> ToDoList::items() const
{
    return mItems;
}

bool ToDoList::setItemAt(int index, const ToDoItem &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const ToDoItem &oldItem = mItems.at(index);
    if (item.name == oldItem.name && item.score == oldItem.score)
        return false;

    mItems[index] = item;
    return true;
}

void ToDoList::appendItem(ToDoItem item)
{
    emit preItemAppended();
    mItems.append(item);
    emit postItemAppended();
}

void ToDoList::removeCompletedItems()
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
