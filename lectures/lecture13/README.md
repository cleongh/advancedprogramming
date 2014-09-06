# Lecture 13: Libraries

- Qt
    - QT_OBJECT macro
    - [signals and slots](http://qt-project.org/doc/qt-5.1/qtcore/signalsandslots.html)
        - slots receive data, signals are used to notify
        - connecting slots and signals
        - type safe
    - Meta Object Complier ([moc](http://qt-project.org/doc/qt-5.1/qtdoc/moc.html#moc))
        - Takes Qt header files and translates them to standard C++
    - [uic](http://qt-project.org/doc/qt-4.8/uic.html) - generates header files from .ui files
    - Generating interfaces
        - Code
        - Compiled UI
        - Parsed UI
    - [Using Cmake](http://qt-project.org/quarterly/view/using_cmake_to_build_qt_projects)
        - [another link](http://www.cmake.org/Wiki/CMake/Tutorials/Qt)
    - Other tools
        - [Qt Designer](http://qt-project.org/doc/qt-4.8/designer-using-a-ui-file.html)
        - [Qt Quick/QML](http://qt-project.org/wiki/Qt_Quick_Tutorial) for rapid GUI creation
            - [Connecting with C++](http://qt-project.org/doc/qt-4.8/qml-extending-tutorial-index.html)
            - [Deploying](http://qt-project.org/doc/qt-5.0/qtquick/qtquick-deployment.html)
        - [QMake](http://qt-project.org/doc/qt-5.0/qtdoc/qmake-manual.html) for compiling Qt projects
        - [QTLinguist](http://qt-project.org/doc/qt-4.8/linguist-manual.html) for localization

# Extended bibliography

- [Qt Tutorials](http://qt-project.org/doc/qt-4.8/tutorials.html)

# Exercises

- Wrap your client as a Qt desktop application.

