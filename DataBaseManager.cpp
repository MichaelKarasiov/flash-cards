#include "DataBaseManager.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include <QVariant>
#include <QDateTime>

#include <SettingsManager.h>
#include <QDebug>
#include <QSqlRecord>

#include "Types.h"

DataBaseManager *DataBaseManager::m_instance = nullptr;
DataBaseManager& DataBaseManager::getInstance()
{
    if(!m_instance)
        m_instance = new DataBaseManager();
    return *m_instance;
}

DataBaseManager::DataBaseManager()
{
    initiate();
}

DataBaseManager::Status DataBaseManager::initiate()
{
    qDebug() << __FUNCTION__ << " : starts...";
    SettingsManager settingsManager;
    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mDatabase.setDatabaseName(settingsManager.getDataBasePath());
    mDatabase.open();
    QSqlQuery query;
    int result = query.exec(
              "CREATE TABLE flash_cards "
              "(id integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "topic_id integer, "
              "question_title text, "
              "question text, "
              "answer text, "
              "time_create text, "
              "time_change text)");
    if(!result)
    {
        qDebug() << query.lastError();
        //return DataBaseManager::Status::Error;
    }
    //else
    //    qDebug() << __FUNCTION__ << " : success!";
    //return Status::Ok;

    int result_2 = query.exec(
              "CREATE TABLE topics "
              "(id integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "name text, "
              "active integer, "
              "time_create text, "
              "time_change text)");
    if(!result_2)
    {
        qDebug() << "result _ 2 " << query.lastError();
    }
}

DataBaseManager::Status DataBaseManager::addQuestion(const QString &question_title_txt, const QString& question_txt, const QString& question_answer_txt, int topic_id)
{

    QSqlQuery query(mDatabase);
     query.prepare(
              "INSERT INTO [flash_cards] (topic_id, question_title, question, answer, time_create, time_change)"
              " VALUES (:q_top_id, :q_title, :q_text, :q_answer, :q_time_create, :q_time_change)");

    qDebug() << topic_id;
    qDebug() << question_title_txt;
    qDebug() << question_txt;
    qDebug() << question_answer_txt;

    query.bindValue(":q_top_id", (topic_id));
    query.bindValue(":q_title", (question_title_txt));
    query.bindValue(":q_text", (question_txt));
    query.bindValue(":q_answer", (question_answer_txt));
    query.bindValue(":q_time_create", QDateTime::currentDateTime().toString());
    query.bindValue(":q_time_change", QDateTime::currentDateTime().toString()); //TODO time changed have to be realy time changed

    int result = query.exec();
    if(!result)
    {
        qDebug() << query.lastError();
        return DataBaseManager::Status::Error;
    }
    else
        qDebug() << __FUNCTION__ << " : success!";

    return DataBaseManager::Status::Ok;
}

DataBaseManager::Status DataBaseManager::addTopic(const QString &topic_name)
{
    QSqlQuery query(mDatabase);
    query.prepare(
                "INSERT INTO [topics] (name, active, time_create, time_change)"
                " VALUES (:q_top_name, 1, :q_time_create, :q_time_change)"
                );

    qDebug() << __FUNCTION__;
    qDebug() << topic_name;

    query.bindValue(":q_top_name", topic_name);
    query.bindValue(":q_time_create", QDateTime::currentDateTime().toString());
    query.bindValue(":q_time_change", QDateTime::currentDateTime().toString()); //TODO time changed have to be realy time changed

    int result = query.exec();
    if(!result)
    {
        qDebug() << query.lastError();
        return DataBaseManager::Status::Error;
    }
    else
        qDebug() << __FUNCTION__ << " : success!";

    return DataBaseManager::Status::Ok;
}

std::shared_ptr<QList<flash_cards::Topic>> DataBaseManager::getTopics()
{
    QList<flash_cards::Topic> *topicList = new QList<flash_cards::Topic>();

    QSqlQuery query(mDatabase);
    query.prepare("SELECT id, name, (SELECT COUNT(id) FROM flash_cards WHERE topic_id = topics.id) AS count FROM topics ");

    if (!query.exec())
    {
        qDebug() << __FUNCTION__ << query.lastError();
        return std::shared_ptr<QList<flash_cards::Topic>>();
    }

    QSqlRecord rec = query.record();

    const int ix_id       = rec.indexOf("id");
    const int ix_name     = rec.indexOf("name");
    const int ix_count     = rec.indexOf("count");

    while(query.next())
    {
        flash_cards::Topic tmp;
        tmp.id = query.value(ix_id).toInt();
        tmp.name = query.value(ix_name).toString();
        tmp.it_count = query.value(ix_count).toInt();

        topicList->append(tmp);
    }

    return std::shared_ptr<QList<flash_cards::Topic>>(topicList);
}
