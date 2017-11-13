#include "TopicsModel.h"

TopicsModel::TopicsModel(QObject *parent):
    QAbstractListModel(parent)
{
    m_roleNames = QAbstractListModel::roleNames();

    m_roleNames.insert(Roles::Name, "Name");
    m_roleNames.insert(Roles::ItemsCount, "Count");
}


QVariant TopicsModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    // add assertion on data not available Q_ASSERT()

    QVariant value;

    switch (role)
    {
    case Name :
        value = m_topics_source[index.row()].name;
        break;
    case ItemsCount :
        value = m_topics_source[index.row()].it_count;
        break;
    }

    return value;
}

int TopicsModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return m_topics_source.size();
}

QModelIndex TopicsModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return createIndex(row, column);
}

//void TopicsModel::resetModel()
//{
//    beginResetModel();
//    endResetModel();
//}
