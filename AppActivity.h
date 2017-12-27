#ifndef APPACTIVITY_H
#define APPACTIVITY_H
#include <DataBaseManager.h>
#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>
#include <QDebug>

#include "Types.h"
#include "TopicsData.h"
#include "TopicsModel.h"
class AppActivity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* topicsModel READ getTopicsModel CONSTANT)
private:

    static AppActivity* m_instance;

    TopicsData topics_data;
    TopicsModel topics_model;
public:
    static AppActivity* instance();
    ~AppActivity();
    explicit AppActivity();
    Q_INVOKABLE bool add_q_data(const QString& q_title, const QString& q_question, const QString& q_answer)
    {
        if(q_title.isEmpty() || q_question.isEmpty() || q_answer.isEmpty())
            return false;
        if(m_current_active_topic_index > 0 && m_current_active_topic_index < topics_data.size()
            && DataBaseManager::getInstance().addQuestion(topics_data[m_current_active_topic_index].id, q_title, q_question, q_answer) == DataBaseManager::Status::Ok){
            topics_data[m_current_active_topic_index].it_count += 1;
            topics_model.resetModel();
            return true;
        }
        else return false;
    }

    Q_INVOKABLE bool add_topic(const QString& t_name)
    {
       m_current_active_topic_index = topics_data.addTopic(t_name);
       topics_model.resetModel();
       return m_current_active_topic_index == INVALID_TOPIC ? false : true;
    }

    Q_INVOKABLE void set_current_topic(int index)
    {
        m_current_active_topic_index = index;
        qDebug() << "Current active index : " << m_current_active_topic_index;
    }


    QAbstractListModel* getTopicsModel()
    {
        return &topics_model;
    }
    Q_INVOKABLE QString getCurrentTopicName(){

        if(m_current_active_topic_index != INVALID_TOPIC && m_current_active_topic_index < topics_data.size())
        {
            return topics_data[m_current_active_topic_index].name;
        }
        return "Errrr";
    }

    static QObject* get_instance(QQmlEngine *engine, QJSEngine *scriptEngine)
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        return AppActivity::instance();
    }

    int m_current_active_topic_index = -1;



//    AppActivity(const AppActivity&) = default;
//    AppActivity(AppActivity&&) = default;
//    AppActivity& operator =(const AppActivity&) = default;
};

#endif // APPACTIVITY_H
