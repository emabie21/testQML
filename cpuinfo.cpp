//cpuinfo.cpp by Eva Mabie 7/23/15
//Implemenation of the custom class that get the contents of "/proc/cpuinfo" file

#include "cpuinfo.h"
#include <QFile>
#include <QTextStream>

//a constant to the path of the file
const QString CPU_PROC_FILE_NAME("/proc/cpuinfo");

cpuinfo::cpuinfo(QObject *parent) : QObject(parent)
{
    //we start off by ge a call to the method to get the contents
    getCpuInfoText();
}

QString cpuinfo::cpuProcText()
{
    return m_cpuProcText;
}


void cpuinfo::getCpuInfoText()
{
    //first check if the file is available
    if (QFile::exists(CPU_PROC_FILE_NAME))
    {
        //attempt to open
        QFile cpuProcFile(CPU_PROC_FILE_NAME);
        if (cpuProcFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //use text strean
            QTextStream outStream(&cpuProcFile);

            //read all the input - relatively small text
            m_cpuProcText = outStream.readAll();

            //now close the file
            cpuProcFile.close();

        }
        else
        {
            //error opening
            m_cpuProcText= tr("error opening ") + CPU_PROC_FILE_NAME;
        }
    }
    else
    {
        //no file
        m_cpuProcText=  CPU_PROC_FILE_NAME + tr(" does not exist!");
    }

    //now update that there is a change
    emit cpuProcTextChanged();
}
