#ifndef STARTPAGEGRAPHICSVIEW_H
#define STARTPAGEGRAPHICSVIEW_H
#include <QGraphicsView>

QT_FORWARD_DECLARE_CLASS(QGraphicsLinearLayout)
QT_FORWARD_DECLARE_CLASS(QGraphicsPixmapItem)
QT_FORWARD_DECLARE_CLASS(QGraphicsProxyWidget)
QT_FORWARD_DECLARE_CLASS(QGraphicsWidget)
QT_FORWARD_DECLARE_CLASS(QPushButton)

class StartPageGraphicsView : public QGraphicsView {
  Q_OBJECT
 public:
  StartPageGraphicsView(QWidget *parent = nullptr);
  ~StartPageGraphicsView();

  void setBackground(const QPixmap &pixmap);

 signals:
  void startClicked();

 protected:
  void resizeEvent(QResizeEvent *event) override;

 private:
  QGraphicsPixmapItem *m_background_item;
  QGraphicsWidget *m_layout_widget;
  QGraphicsLinearLayout *m_layout;
  QGraphicsProxyWidget *m_start_btn_proxy;
  QPushButton *m_start_btn;

 private slots:
  void onStartBtnClicked();
};

#endif  // STARTPAGEGRAPHICSVIEW_H
