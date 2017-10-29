#include "AppActivity.h"

AppActivity* AppActivity::m_instance = nullptr;

AppActivity::AppActivity()
{
    if(m_DB_Manager.initiate() == DataBaseManager::InitStatus::Ok)
    {
//        QString str = "Title";
//        QString str2 = "text questio dsfdsf dsfsd sdfsdf sdfds f sdfd \nsdfdsfdsf";
//        QString answer = "BLA BLA BLA";
//        m_DB_Manager.addQuestion(str, str2, answer);
    }
    else    {
        //TODO
    }
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
