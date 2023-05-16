#ifndef RAZERMOUSEBATTERY_H
#define RAZERMOUSEBATTERY_H

#include <QObject>
#include <QQmlEngine>
#include <QProcess>

class RazerMouseBattery : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString commandPath READ commandPath WRITE setCommandPath NOTIFY commandPathChanged)
    Q_PROPERTY(bool isOk READ isOk WRITE setIsOk NOTIFY isOkChanged)
    Q_PROPERTY(QString reason READ reason WRITE setReason NOTIFY reasonChanged)
    Q_PROPERTY(double batteryLevel READ batteryLevel WRITE setBatteryLevel NOTIFY batteryLevelChanged)
    Q_PROPERTY(bool isCharging READ isCharging WRITE setIsCharging NOTIFY isChargingChanged)
    QML_ELEMENT
public:
    explicit RazerMouseBattery(QObject *parent = nullptr);

    double batteryLevel() const;
    void setBatteryLevel(double newBatteryLevel);

    bool isCharging() const;
    void setIsCharging(bool newIsCharging);

    QString commandPath() const;
    void setCommandPath(const QString &newCommandPath);

    Q_INVOKABLE void update();

    bool isOk() const;
    void setIsOk(bool newIsOk);

    QString reason() const;
    void setReason(const QString &newReason);

signals:

    void batteryLevelChanged();
    void isChargingChanged();

    void commandPathChanged();

    void isOkChanged();

    void reasonChanged();

private:
    bool m_isCharging = false;
    double m_batteryLevel = 0.0;
    QString m_commandPath;
    QProcess m_process;
    bool m_isOk = false;
    QString m_reason;
};

#endif // RAZERMOUSEBATTERY_H
