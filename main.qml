import QtQuick.Controls 1.4
import QtQuick.Window 2.0

//registered type for custom type to get contents of /proc/cpuinfo
import com.cpuInfo.test 1.0


Window {
    visible: true
    width: 720
    height: 720




    TextArea {
        id:cpuText
        text:cpuInfoObj.cpuProcText
        anchors.fill: parent
    }


    //custom qml control that is tied to C++ class(cpuinfo) to get contents of /proc/cpuinfo
    cpuInfo
    {
        id: cpuInfoObj
        //on signal from c++ class we update the text area with new info
        onCpuProcTextChanged: cpuText.text = this.cpuProcText


    }
}
