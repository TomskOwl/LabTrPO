
#include <iostream>
#include <QCoreApplication>
#include <QTimer>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QtCore>
#include <QFileSystemWatcher>
//class Updater : public QObject
//{
//     Q_OBJECT

//public:
//    Updater(QObject *parent = 0) : QObject(parent) {};
//    Updater(QFile file) {
//        _fileForUpdate = file;
//    }
//    ~Updater() {};
//private:
//    QFile *_fileForUpdate;

//public slots:
//     void updateFileSize();

//signals:
//     void finished();
//};

//void Updater::updateFileSize()
//{
//    QFileInfo fileInfo(_fileForUpdate->fileName());
//    QString fileName(fileInfo.fileName());
//     QTextStream cout(stdout);

//     if (!fileInfo.isFile()) {
//          cout << "File" << fileName << "does not exist.";
//     } else {
//          qint64 size = fileInfo.size();
//          cout << "File size:" << size << "bytes";
//     }
//     emit finished();
//}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFileSystemWatcher Watcher;


    QFile file1("C:/labTRPO/LabTrPO/lab2/lab2/file1.txt");
    QFileInfo fileInfo(file1.fileName());
    QTextStream cout(stdout);
    if(!file1.open(QIODevice::ReadOnly)) {
        std::cout <<"Read-file-path "<<"C:/labTRPO/LabTrPO/lab2/lab2/file1.txt"<<std::endl<<"Error:";}
        else {
            qint64 size = fileInfo.size();
            std::cout << "File size:" << size << "bytes";
            Watcher.addPath(fileInfo.path());
    }
    QObject::connect(&Watcher,&QFileSystemWatcher::fileChanged, &a,[fileInfo](){
        qint64 size = fileInfo.size();
        std::cout << "File size:" << size << "bytes";
//        std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
        ;});
//    QTimer::singleShot(3000, &a, SLOT(quit()));
    return a.exec();
}
