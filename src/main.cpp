#include <QApplication>
#include <QDateTime>
#include <QFile>
#include <QIcon>
#include <QMutex>

#include <Pages/start.h>

struct {
  QFile gameLogFile;
  QMutex logMutex;
} gameLogger;

QtMessageHandler default_handler = nullptr;

void gameLogManager(QtMsgType type, const QMessageLogContext &context, const QString &msg){
  // Synchronize access to the file
  QMutexLocker locker(&gameLogger.logMutex);

  if (!gameLogger.gameLogFile.isOpen()) {
    gameLogger.gameLogFile.open(QIODevice::WriteOnly | QIODevice::Append);
  }

  if (context.category && QString(context.category) == QStringLiteral("game")) {
    QTextStream out(&gameLogger.gameLogFile);
    out << QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss]") << msg << Qt::endl;
  }

  if(default_handler){
    default_handler(type, context, msg);
  }
}

int main(int argc,char *argv[]){
  gameLogger.gameLogFile.setFileName("log.txt");
  QApplication app(argc, argv);

  default_handler = qInstallMessageHandler(nullptr);
  qInstallMessageHandler(gameLogManager);

  app.setApplicationName("RushRoyale");
  app.setApplicationDisplayName("Rush Royale");
  app.setWindowIcon(QIcon(":/assets/icon.png"));

  Start start;
  start.show();

  return app.exec();
}
