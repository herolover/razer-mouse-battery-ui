#include "razermousebattery.h"

#include <QJsonDocument>
#include <QProcess>

RazerMouseBattery::RazerMouseBattery(QObject *parent)
    : QObject{parent}
{
    connect(&m_process, &QProcess::finished, [this]() {
        QByteArray output = m_process.readAllStandardOutput();
        auto document = QJsonDocument::fromJson(output);
        if (document["Status"].toString() == "OK") {
            setIsOk(true);
            setBatteryLevel(document["BatteryLevel"].toDouble());
            setIsCharging(document["IsCharging"].toBool());
        } else {
            setIsOk(false);
            setReason(document["Reason"].toString());
        }
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

bool RazerMouseBattery::isOk() const
{
    return m_isOk;
}

void RazerMouseBattery::setIsOk(bool newIsOk)
{
    if (m_isOk == newIsOk)
        return;
    m_isOk = newIsOk;
    emit isOkChanged();
}

QString RazerMouseBattery::reason() const
{
    return m_reason;
}

void RazerMouseBattery::setReason(const QString &newReason)
{
    if (m_reason == newReason)
        return;
    m_reason = newReason;
    emit reasonChanged();
}
