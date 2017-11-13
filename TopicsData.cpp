#include "TopicsData.h"
#include "DataBaseManager.h"
#include <QDebug>

TopicsData::TopicsData()
{
    m_topics_list = DataBaseManager::getInstance().getTopics();
    qDebug() << __FUNCTION__ << " " << m_topics_list.get()->size();
}

flash_cards::Result TopicsData::addTopic(QString t_name)
{
    for(int i = 0; i < m_topics_list.get()->size(); ++i)
    {
        if(m_topics_list.get()->at(i).name == t_name)
        {
            return false;
        }
    }

    //Insert topic to database

    DataBaseManager::getInstance().addTopic(t_name);

    return true;
}
