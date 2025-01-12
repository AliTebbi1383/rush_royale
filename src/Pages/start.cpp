#include "start.h"

#include <gameresourcemanager.h>

#include <QGraphicsPixmapItem>

#include "mainwindow.h"
#include "ui_start.h"

Start::Start(QWidget *parent) : QWidget(parent), ui(new Ui::Start) {
  ui->setupUi(this);
  ui->graphicsView->setBackground(QPixmap(":/assets/bg.jpg"));

  connect(ui->graphicsView, &StartPageGraphicsView::startClicked, this,
          &Start::LaunchGame);
}

Start::~Start() { delete ui; }

void Start::LaunchGame() {
  GameResourceManager::init();
  MainWindow *win = new MainWindow();
  win->show();
  this->close();
  this->destroy();
}
