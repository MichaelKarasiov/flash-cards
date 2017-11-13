#ifndef APPACTIVITY_H
#define APPACTIVITY_H
#include <DataBaseManager.h>
#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

class AppActivity : public QObject
{
    Q_OBJECT
public:
    static AppActivity* instance();

    explicit AppActivity();
    Q_INVOKABLE bool add_q_data(const QString& q_title, const QString& q_question, const QString& q_answer)
    {
        if(q_title.isEmpty() || q_question.isEmpty() || q_answer.isEmpty())
            return false;
        if(DataBaseManager::getInstance().addQuestion(q_title, q_question, q_answer,current_topic_id) == DataBaseManager::Status::Ok)
            return true;
        else return false;
    }

    static QObject* get_instance(QQmlEngine *engine, QJSEngine *scriptEngine)
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        return AppActivity::instance();
    }

    ~AppActivity();
private:
    static AppActivity* m_instance;
//    AppActivity(const AppActivity&) = default;
//    AppActivity(AppActivity&&) = default;
//    AppActivity& operator =(const AppActivity&) = default;

    int current_topic_id;
};

#endif // APPACTIVITY_H
