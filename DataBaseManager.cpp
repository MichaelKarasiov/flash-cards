#include "DataBaseManager.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include <QVariant>

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
    }
    else
        qDebug() << __FUNCTION__ << " : success!";
    return InitStatus::Ok;
}

bool DataBaseManager::addQuestion(const QString &question_title_txt, const QString& question_txt)
{

    QSqlQuery query(mDatabase);
     query.prepare(
              "INSERT INTO [flash_cards] (question_title, question) VALUES (:q_title, :q_text)");

    qDebug() << question_title_txt;
    qDebug() << question_txt;
    query.bindValue(":q_title", (question_title_txt));
    query.bindValue(":q_text", (question_txt));

    int result = query.exec();
    if(!result)
    {
        qDebug() << query.lastError();
    }
    else
        qDebug() << __FUNCTION__ << " : success!";
}
bool DataBaseManager::addAnswer(int qustion_id, QString& answer_txt){}
