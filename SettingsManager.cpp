#include "SettingsManager.h"
#include <QSettings>

SettingsManager::SettingsManager():
    m_DataBasePath("./userCards.sqlite") //TODO change path
{
}
