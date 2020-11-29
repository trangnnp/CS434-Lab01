#ifndef MsgMODEL_H
#define MsgMODEL_H

#include <QAbstractListModel>

class MsgList;

class MsgModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(MsgList *list READ list WRITE setList)

public:
    explicit MsgModel(QObject *parent = nullptr);

    enum {
        TimestampRole = Qt::UserRole,
        SenderRole,
        ContentRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    MsgList *list() const;
    void setList(MsgList *list);

private:
    MsgList *mList;
};

#endif // MsgMODEL_H
