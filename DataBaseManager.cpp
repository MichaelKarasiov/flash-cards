#include "DataBaseManager.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include <QVariant>
#include <QDateTime>

#include <SettingsManager.h>
#include <QDebug>
DataBaseManager::DataBaseManager()
{
}

DataBaseManager::InitStatus DataBaseManager::initiate()
{
    qDebug() << __FUNCTION__ << " : starts...";
    SettingsManager settingsManager;
    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mDatabase.setDatabaseName(settingsManager.getDataBasePath());
    mDatabase.open();
    QSqlQuery query;
    int result = query.exec(
              "CREATE TABLE flash_cards "
              "(id integer NOT NULL PRIMARY KEY AUTOINCREMENT, "
              "question_title text, "
              "question text, "
              "answer text, "
              "time_create text, "
              "time_change text)");
    if(!result)
    {
        qDebug() << query.lastError();
        return DataBaseManager::InitStatus::Error;
    }
    else
        qDebug() << __FUNCTION__ << " : success!";
    return InitStatus::Ok;
}

DataBaseManager::InitStatus DataBaseManager::addQuestion(const QString &question_title_txt, const QString& question_txt, const QString& question_answer_txt)
{

    QSqlQuery query(mDatabase);
     query.prepare(
              "INSERT INTO [flash_cards] (question_title, question, answer, time_create, time_change)"
              " VALUES (:q_title, :q_text, :q_answer, :q_time_create, :q_time_change)");

    qDebug() << question_title_txt;
    qDebug() << question_txt;
    qDebug() << question_answer_txt;

    query.bindValue(":q_title", (question_title_txt));
    query.bindValue(":q_text", (question_txt));
    query.bindValue(":q_answer", (question_answer_txt));
    query.bindValue(":q_time_create", QDateTime::currentDateTime().toString());
    query.bindValue(":q_time_change", QDateTime::currentDateTime().toString()); //TODO time changed have to be realy time changed

    int result = query.exec();
    if(!result)
    {
        qDebug() << query.lastError();
        return DataBaseManager::InitStatus::Error;
    }
    else
        qDebug() << __FUNCTION__ << " : success!";

    return DataBaseManager::InitStatus::Ok;
}
