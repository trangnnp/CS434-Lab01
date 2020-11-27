#include "playerlist.h"
#include "playermodel.h"

PlayerModel::PlayerModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int PlayerModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant PlayerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const Player item = mList->items().at(index.row());
    switch (role) {
    case NameRole:
        return QVariant(item.name);
    case ScoreRole:
        return QVariant(item.score);
    case AvatarRole:
        return QVariant(item.avatar);
    case StatusRole:
        return QVariant(item.status);
    }

    return QVariant();
}

bool PlayerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    Player item = mList->items().at(index.row());
    switch (role) {
    case NameRole:
        item.name = value.toString();
        break;
    case ScoreRole:
        item.score = value.toInt();
        break;
    case AvatarRole:
        item.avatar = value.toString();
        break;
    case StatusRole:
        item.status = value.toInt();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags PlayerModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PlayerModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[NameRole] = "name";
    names[ScoreRole] = "score";
    names[AvatarRole] = "avatar";
    names[StatusRole] = "status";
    return names;
}

PlayerList *PlayerModel::list() const
{
    return mList;
}

void PlayerModel::setList(PlayerList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &PlayerList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &PlayerList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &PlayerList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &PlayerList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
