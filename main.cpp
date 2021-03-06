#include "ventanainicio.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
/*
 * main del programa, se encarga de iniciar la ventana de inicio
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Proyecto1_Memorama_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    VentanaInicio w;
    w.show();
    return a.exec();
}
