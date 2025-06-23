#include "tcpclient.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "opewidget.h"
#include "privatechat.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "wp_demo_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    // TcpClient w;
    TcpClient::getInstance().show();
    // OpeWidget o;
    // o.show();
    // privateChat p;
    // p.show();

    return a.exec();
}
