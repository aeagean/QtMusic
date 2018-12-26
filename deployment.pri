#**********************************************************
#Author: 微信公众号(你才小学生)
#WeChat public platform: nicaixiaoxuesheng
#Email:  2088201923@qq.com
#**********************************************************/

unix:!android {
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
            target.path = /opt/$${TARGET}/bin
        }
        export(target.path)
    }
    INSTALLS += target
}

export(INSTALLS)
