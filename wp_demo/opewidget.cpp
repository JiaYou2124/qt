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
                         "background-color: #ffffff;"
                         "}"
                         );

    // m_pLE->setFixedSize(80,40);

    // 应用导航列表样式
    m_pListW->setStyleSheet(Styles::getNavigationListStyle());
    // m_pListW->setFixedSize(80, 200);
    m_pListW->setFixedWidth(80);
    m_pListW->setFocusPolicy(Qt::NoFocus);

    QIcon icon(":img/img/chat.png");
    QListWidgetItem *m_Friend = new QListWidgetItem(icon," ");
    m_pListW->setIconSize(QSize(32, 32)); // 设置图标大小
    m_pListW->addItem(m_Friend);

    m_pListW->addItem("文件");

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
