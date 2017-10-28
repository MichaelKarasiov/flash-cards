#include "AppActivity.h"

#define DB_INIT_STATUS DataBaseManager::InitStatus::

AppActivity::AppActivity()
{
    if(m_DB_Manager.initiate() != DB_INIT_STATUS Ok)
    {
        //TODO
    }
QString str = "sssss";
QString str2 = "sdsfdsfdsfd";
    m_DB_Manager.addQuestion(str, str2);

}
