#include "razermousebattery.h"

#include <QJsonDocument>
#include <QProcess>

RazerMouseBattery::RazerMouseBattery(QObject *parent)
    : QObject{parent}
{
    connect(&m_process, &QProcess::finished, [this]() {
        QByteArray output = m_process.readAllStandardOutput();
        auto document = QJsonDocument::fromJson(output);
        setBatteryLevel(document["BatteryLevel"].toDouble());
        setIsCharging(document["IsCharging"].toBool());
    });
}

bool RazerMouseBattery::isCharging() const
{
    return m_isCharging;
}

void RazerMouseBattery::setIsCharging(bool newIsCharging)
{
    if (m_isCharging == newIsCharging)
        return;
    m_isCharging = newIsCharging;
    emit isChargingChanged();
}

double RazerMouseBattery::batteryLevel() const
{
    return m_batteryLevel;
}

void RazerMouseBattery::setBatteryLevel(double newBatteryLevel)
{
    if (m_batteryLevel == newBatteryLevel)
        return;
    m_batteryLevel = newBatteryLevel;
    emit batteryLevelChanged();
}

QString RazerMouseBattery::commandPath() const
{
    return m_commandPath;
}

void RazerMouseBattery::setCommandPath(const QString &newCommandPath)
{
    if (m_commandPath == newCommandPath)
        return;
    m_commandPath = newCommandPath;
    emit commandPathChanged();
}

void RazerMouseBattery::update()
{
    m_process.start(commandPath());
}
