#ifndef TOPICSDATA_H
#define TOPICSDATA_H
#include <QString>
#include <QList>

#include "Types.h"
#include "DataBaseManager.h"

class TopicsData
{

public:
    TopicsData();
     flash_cards::Topic& operator[](int index){
//        if(m_topics_list.get()->size() < index && index >= 0)
            return (*m_topics_list.get())[index];
    }
    //return topic index when addTopic call
    int addTopic(QString t_name);
    int size() const {return m_topics_list.get()->size();}
    int getItemIndexById(flash_cards::TopicID id)
    {
        if(m_topics_list.get()->size() > id && 0 < id && id == m_topics_list.get()->at(id).id)
        {
            return id;
        }

        for(int i = 0; i < m_topics_list.get()->size(); ++i)
        {
            if (m_topics_list.get()->at(i).id == id)
                return i;
        }
        return INVALID_TOPIC;
    }

private:
    std::shared_ptr<QList<flash_cards::Topic>> m_topics_list;

};

#endif // TOPICSDATA_H
