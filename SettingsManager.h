#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H
#include <QSettings>

class SettingsManager
{
public:
    SettingsManager();
    const QString getDataBasePath() const {return m_DataBasePath;}
private:
    QString m_DataBasePath;
};

#endif // SETTINGSMANAGER_H
