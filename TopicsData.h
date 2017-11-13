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
    const flash_cards::Topic& operator[](int index) const{
//        if(m_topics_list.get()->size() < index && index >= 0)
            return (*m_topics_list.get())[index];
    }

    flash_cards::Result addTopic(QString t_name);
    int size() const {return m_topics_list.get()->size();}

private:
    std::shared_ptr<QList<flash_cards::Topic>> m_topics_list;

};

#endif // TOPICSDATA_H
