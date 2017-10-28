#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QSqlDatabase>

class DataBaseManager
{
public:
    enum class InitStatus
    {
        Ok,
        Error
    };
    DataBaseManager();
    InitStatus initiate();

    bool addQuestion(const QString &question_title_txt, const QString &question_txt, const QString &answer_txt);

    QSqlDatabase& getDatabase() {return mDatabase;}
private:
    QSqlDatabase mDatabase;
};

#endif // DATABASEMANAGER_H
