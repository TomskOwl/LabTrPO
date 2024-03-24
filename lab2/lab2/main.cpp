#include <QCoreApplication>
#include <QFileInfo>
#include <QTimer>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString filePath = "C:/labTRPO/LabTrPO/lab2/lab2/file1.txt"; // Replace "path/to/your/file" with the actual file path

    QFileInfo fileInfo(filePath);
    QTextStream(stdout) << "Initial file size: " << fileInfo.size() << " bytes\n";

    QTimer timer;
    timer.setInterval(1000); // Interval to check the file size in milliseconds
    timer.setSingleShot(false);

    QObject::connect(&timer, &QTimer::timeout, [&fileInfo, &filePath](){
        fileInfo.refresh();
        if (!fileInfo.isFile()) {
            QTextStream(stdout) << "File " << filePath << " does not exist.\n";}
        else {
        QTextStream(stdout) << "Current file size: " << fileInfo.size() << " bytes\n";}
    });

    timer.start();

    return app.exec();
}

