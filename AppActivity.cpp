#include "AppActivity.h"
#include <QDebug>
AppActivity* AppActivity::m_instance = nullptr;

AppActivity::AppActivity() :
    topics_model(&topics_data)
{
    qDebug() << "TOPICS DATA SIZE: " << topics_data.size();
}

AppActivity::~AppActivity()
{
}

AppActivity* AppActivity::instance()
{
    if(!m_instance)
        m_instance = new AppActivity();
    return m_instance;
}
