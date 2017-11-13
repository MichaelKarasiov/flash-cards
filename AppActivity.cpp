#include "AppActivity.h"

AppActivity* AppActivity::m_instance = nullptr;

AppActivity::AppActivity()
{
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
