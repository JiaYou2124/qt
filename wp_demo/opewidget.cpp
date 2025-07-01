#include "opewidget.h"
#include "styles.h"  // 添加样式头文件
#include <QHBoxLayout>
#include <QIcon>
#include "document.h"

OpeWidget::OpeWidget(QWidget *parent)
    : QWidget{parent}
{
    m_pListW = new QListWidget(this);
    m_pLE = new QLineEdit(this);


    setWindowFlags(Qt::FramelessWindowHint);     //无边框
    setAttribute(Qt::WA_TranslucentBackground, false);

    //设置只读
    m_pLE->setReadOnly(true);
    //设置字体大小
    QFont font = m_pLE->font();
    font.setPointSize(20);
    m_pLE->setFont(font);
    //登录用户
    QString loginName = TcpClient::getInstance().getLoginName();
    //显示当前登录用户
    m_pLE->setText(QString("欢迎：%1").arg(loginName));
    //取消边框线
    m_pLE->setStyleSheet("QLineEdit"
                         "{"
                         "border: none;"
                         "background-color: #e0e0e0;"
                         "}"
                         );

    // m_pLE->setFixedSize(80,40);

    // 应用导航列表样式
    m_pListW->setStyleSheet(Styles::getNavigationListStyle());
    // m_pListW->setFixedSize(80, 200);
    m_pListW->setFixedWidth(80);
    m_pListW->setFocusPolicy(Qt::NoFocus);

    QIcon chat_icon(":img/img/chat.png");
    QIcon file_icon(":img/img/文件夹.png");
    QListWidgetItem *m_Friend = new QListWidgetItem(chat_icon," ");
    m_pListW->setIconSize(QSize(32, 32)); // 设置图标大小
    m_pListW->addItem(m_Friend);

    QListWidgetItem *m_File = new QListWidgetItem(file_icon," ");
    m_pListW->setIconSize(QSize(32, 32)); // 设置图标大小
    m_pListW->addItem(m_File);

    m_pFriend = new Friend;
    m_pDocument = new Document;

    m_pSW = new QStackedWidget;
    m_pSW->setStyleSheet(Styles::getStackedWidgetStyle());

    m_pSW->addWidget(m_pFriend);
    m_pSW->addWidget(m_pDocument);

    QHBoxLayout *pMain = new QHBoxLayout;
    pMain->addWidget(m_pListW);
    pMain->addWidget(m_pSW);

    QVBoxLayout *top = new QVBoxLayout;
    top->addWidget(m_pLE);
    top->addLayout(pMain);


    setLayout(top);

    connect(m_pListW,SIGNAL(currentRowChanged(int))
            ,m_pSW,SLOT(setCurrentIndex(int)));

    
    // 设置整体背景样式
    this->setStyleSheet(Styles::getOpeWidgetBackgroundStyle());
}

Friend *OpeWidget::getFriend()
{
    return m_pFriend;
}

Document *OpeWidget::getDocument()
{
    return m_pDocument;
}

OpeWidget &OpeWidget::getInstance()
{
    static OpeWidget instance;
    return instance;
}
// 鼠标按下事件 - 开始拖拽
void OpeWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDragging = true;
        m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}
// 鼠标移动事件 - 拖拽窗口
void OpeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && m_bDragging && !m_bMaximized) {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}
// 鼠标释放事件 - 结束拖拽
void OpeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_bDragging = false;
        event->accept();
    }
}
