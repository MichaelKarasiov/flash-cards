#ifndef TOPICSMODEL_H
#define TOPICSMODEL_H
#include <QAbstractListModel>

#include "TopicsData.h"
class TopicsModel : public QAbstractListModel
{
        Q_OBJECT
        Q_ENUMS(Roles)

    TopicsData& m_topics_source;
public:

    enum Roles
    {
        Name = Qt::UserRole + 1,
        ItemsCount,
        Id
    };
    Q_ENUMS(Roles)
    TopicsModel(TopicsData*, QObject* parent = 0);

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;

    QHash<int,QByteArray> roleNames() const {return m_roleNames;}
    void resetModel();
protected:
    QHash<int,QByteArray> m_roleNames;
private:


};
#endif // TOPICSMODEL_H
