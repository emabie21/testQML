//cpuinfo.h by Eva Mabie 7/22/15
//header file for custom class that gets the contents of the /proc/cpuinfo file

#ifndef CPUINFO_H
#define CPUINFO_H

#include <QObject>
#include <QString>

class cpuinfo : public QObject
{
    Q_OBJECT
    //Define the properties of the cpu proc text string only two that matter
    //  read and notify. Class doesn't allow fow writting to from qml
    Q_PROPERTY(QString cpuProcText READ cpuProcText NOTIFY cpuProcTextChanged)
public:
    explicit cpuinfo(QObject *parent = 0);
    void getCpuInfoText();
    QString cpuProcText();

signals:
    void cpuProcTextChanged();
private:

    QString m_cpuProcText;

};

#endif // CPUINFO_H
