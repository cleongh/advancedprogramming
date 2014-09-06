// from http://stackoverflow.com/questions/10703122/qt-using-quiloader-to-load-a-widget-with-no-parent
#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtUiTools/QUiLoader>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QUiLoader loader;
    QFile file("qtwindow.ui");
    file.open(QFile::ReadOnly);

    QWidget *myWidget = loader.load(&file);
    if(myWidget){
        myWidget->show();

        QPushButton *outer = qFindChild<QPushButton*>(myWidget, "outer");
        QObject::connect(outer, SIGNAL(clicked()), myWidget,  SLOT(close()));
    }

    return a.exec();
}
