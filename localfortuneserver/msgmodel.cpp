#include "msglist.h"
#include "msgmodel.h"
MsgModel::MsgModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int MsgModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant MsgModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const Msg item = mList->items().at(index.row());
    switch (role) {
    case TimestampRole:
        return QVariant(item.timestamp);
    case SenderRole:
        return QVariant(item.sender);
    case ContentRole:
        return QVariant(item.content);
    }

    return QVariant();
}

bool MsgModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    Msg item = mList->items().at(index.row());
    switch (role) {
    case TimestampRole:
        item.timestamp = value.toString();
        break;
    case SenderRole:
        item.sender = value.toString();
        break;
    case ContentRole:
        item.content = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags MsgModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> MsgModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[TimestampRole] = "timestamp";
    names[SenderRole] = "sender";
    names[ContentRole] = "content";
    return names;
}

MsgList *MsgModel::list() const
{
    return mList;
}

void MsgModel::setList(MsgList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &MsgList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &MsgList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &MsgList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &MsgList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
