#include "TopicsData.h"
#include "DataBaseManager.h"
#include <QDebug>

TopicsData::TopicsData()
{
    m_topics_list = DataBaseManager::getInstance().getTopics();
    qDebug() << __FUNCTION__ << " " << m_topics_list.get()->size();
}

flash_cards::TopicID TopicsData::addTopic(QString t_name)
{
    for(int i = 0; i < m_topics_list.get()->size(); ++i)
    {
        if(m_topics_list.get()->at(i).name == t_name)
        {
            return i;
        }
    }

    //Insert topic to database

    if(DataBaseManager::getInstance().addTopic(t_name) == DataBaseManager::Status::Ok){
        flash_cards::Topic tmp;
        tmp.id = (m_topics_list.get()->last().id+1);
        tmp.name = t_name;
        m_topics_list.get()->push_back(tmp);
        return m_topics_list.get()->size()-1;
    }

    return INVALID_TOPIC;
}
