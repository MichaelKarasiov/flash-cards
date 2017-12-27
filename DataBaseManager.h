#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <memory>

#include "Types.h"

class DataBaseManager
{
public:
    enum class Status
    {
        Ok = 1,
        Error
    };

    Status initiate();

    Status addQuestion(int topic_id, const QString &question_title_txt, const QString &question_txt, const QString &answer_txt);
    Status addTopic(const QString &topic_name);

    std::shared_ptr<QList<flash_cards::Topic>> getTopics();
    QSqlDatabase& getDatabase() {return mDatabase;}

    static DataBaseManager& getInstance();
private:
     DataBaseManager();
     ~DataBaseManager() = default;
     DataBaseManager(const DataBaseManager& ) = default;
     DataBaseManager& operator=(const DataBaseManager&) = default;
     QSqlDatabase mDatabase;
     static DataBaseManager *m_instance;

};

#endif // DATABASEMANAGER_H
