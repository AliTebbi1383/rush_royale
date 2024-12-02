#include "startpagegraphicsview.h"

#include <QGraphicsLinearLayout>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsWidget>
#include <QPushButton>
#include <QResizeEvent>

StartPageGraphicsView::StartPageGraphicsView(QWidget *parent)
    : QGraphicsView(parent), m_background_item(nullptr) {
  QGraphicsScene *default_scene = new QGraphicsScene(this);
  setScene(default_scene);

  m_layout_widget = new QGraphicsWidget();
  m_layout = new QGraphicsLinearLayout(Qt::Vertical);
  m_layout->setContentsMargins(50.0, 0.0, 50.0, 30.0);

  m_start_btn = new QPushButton(tr("Start"));
  connect(m_start_btn, &QPushButton::clicked, this,
          &StartPageGraphicsView::onStartBtnClicked);
  QFont start_btn_font = m_start_btn->font();
  start_btn_font.setPointSizeF(24.0f);
  start_btn_font.setBold(true);
  m_start_btn->setFont(start_btn_font);
  m_start_btn_proxy = new QGraphicsProxyWidget();
  m_start_btn_proxy->setWidget(m_start_btn);

  m_layout->addStretch();
  m_layout->addItem(m_start_btn_proxy);
  m_layout->setAlignment(m_start_btn_proxy, Qt::AlignVCenter);

  default_scene->addItem(m_layout_widget);
  m_layout_widget->setLayout(m_layout);
  m_layout_widget->setZValue(1);
}

StartPageGraphicsView::~StartPageGraphicsView() {}

void StartPageGraphicsView::setBackground(const QPixmap &pixmap) {
  Q_ASSERT(m_background_item == nullptr);
  m_background_item = scene()->addPixmap(pixmap);
  m_background_item->setZValue(0);
}

void StartPageGraphicsView::resizeEvent(QResizeEvent *event) {
  if (m_background_item) {
    fitInView(m_background_item, Qt::KeepAspectRatio);

    m_layout_widget->setGeometry(m_background_item->boundingRect());
  }

  QGraphicsView::resizeEvent(event);
}

void StartPageGraphicsView::onStartBtnClicked() { emit startClicked(); }
