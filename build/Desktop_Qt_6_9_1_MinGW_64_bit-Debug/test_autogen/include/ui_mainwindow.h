/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_num_1;
    QPushButton *button_num_6;
    QPushButton *button_num_7;
    QPushButton *button_num_8;
    QPushButton *button_num_2;
    QPushButton *button_num_0;
    QPushButton *button_backspace;
    QPushButton *button_CE;
    QPushButton *button_num_3;
    QPushButton *button_num_9;
    QPushButton *button_num_4;
    QPushButton *button_num_5;
    QPushButton *button_factorial;
    QPushButton *button_add;
    QPushButton *button_subtract;
    QPushButton *button_multiply;
    QPushButton *button_divide;
    QPushButton *button_equal;
    QPushButton *button_absolute;
    QPushButton *button_close_parenthesis;
    QPushButton *button_open_parenthesis;
    QLineEdit *txtDisplay;
    QLabel *label;
    QLineEdit *hisDisplay;
    QButtonGroup *numButtonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::WindowModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(311, 423);
        MainWindow->setWindowTitle(QString::fromUtf8("Calculator"));
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 120, 311, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout->setContentsMargins(1, 1, 1, 1);
        button_num_1 = new QPushButton(gridLayoutWidget);
        numButtonGroup = new QButtonGroup(MainWindow);
        numButtonGroup->setObjectName("numButtonGroup");
        numButtonGroup->addButton(button_num_1);
        button_num_1->setObjectName("button_num_1");
        button_num_1->setMaximumSize(QSize(70, 42));
        QFont font;
        font.setPointSize(12);
        button_num_1->setFont(font);
        button_num_1->setText(QString::fromUtf8("1"));
        button_num_1->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_1, 2, 0, 1, 1);

        button_num_6 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_6);
        button_num_6->setObjectName("button_num_6");
        button_num_6->setMaximumSize(QSize(70, 42));
        button_num_6->setFont(font);
        button_num_6->setText(QString::fromUtf8("6"));
        button_num_6->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_6, 4, 2, 1, 1);

        button_num_7 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_7);
        button_num_7->setObjectName("button_num_7");
        button_num_7->setMaximumSize(QSize(70, 42));
        button_num_7->setFont(font);
        button_num_7->setText(QString::fromUtf8("7"));
        button_num_7->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_7, 5, 0, 1, 1);

        button_num_8 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_8);
        button_num_8->setObjectName("button_num_8");
        button_num_8->setMaximumSize(QSize(70, 42));
        button_num_8->setFont(font);
        button_num_8->setText(QString::fromUtf8("8"));
        button_num_8->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_8, 5, 1, 1, 1);

        button_num_2 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_2);
        button_num_2->setObjectName("button_num_2");
        button_num_2->setMaximumSize(QSize(70, 42));
        button_num_2->setFont(font);
        button_num_2->setText(QString::fromUtf8("2"));
        button_num_2->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_2, 2, 1, 1, 1);

        button_num_0 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_0);
        button_num_0->setObjectName("button_num_0");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button_num_0->sizePolicy().hasHeightForWidth());
        button_num_0->setSizePolicy(sizePolicy);
        button_num_0->setMaximumSize(QSize(70, 42));
        button_num_0->setFont(font);
        button_num_0->setText(QString::fromUtf8("0"));
        button_num_0->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_0, 6, 1, 1, 1);

        button_backspace = new QPushButton(gridLayoutWidget);
        button_backspace->setObjectName("button_backspace");
        button_backspace->setMinimumSize(QSize(0, 42));
        button_backspace->setMaximumSize(QSize(70, 42));
        QFont font1;
        font1.setPointSize(7);
        button_backspace->setFont(font1);
        button_backspace->setText(QString::fromUtf8("Backspace"));
        button_backspace->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_backspace, 0, 3, 1, 1);

        button_CE = new QPushButton(gridLayoutWidget);
        button_CE->setObjectName("button_CE");
        button_CE->setMaximumSize(QSize(70, 42));
        button_CE->setFont(font);
        button_CE->setText(QString::fromUtf8("CE"));
        button_CE->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_CE, 0, 2, 1, 1);

        button_num_3 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_3);
        button_num_3->setObjectName("button_num_3");
        button_num_3->setMaximumSize(QSize(70, 42));
        button_num_3->setSizeIncrement(QSize(1, 1));
        button_num_3->setBaseSize(QSize(70, 70));
        button_num_3->setFont(font);
        button_num_3->setText(QString::fromUtf8("3"));
        button_num_3->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_3, 2, 2, 1, 1);

        button_num_9 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_9);
        button_num_9->setObjectName("button_num_9");
        sizePolicy.setHeightForWidth(button_num_9->sizePolicy().hasHeightForWidth());
        button_num_9->setSizePolicy(sizePolicy);
        button_num_9->setMaximumSize(QSize(70, 42));
        button_num_9->setFont(font);
        button_num_9->setText(QString::fromUtf8("9"));
        button_num_9->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_9, 5, 2, 1, 1);

        button_num_4 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_4);
        button_num_4->setObjectName("button_num_4");
        button_num_4->setMaximumSize(QSize(70, 42));
        button_num_4->setFont(font);
        button_num_4->setText(QString::fromUtf8("4"));
        button_num_4->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_4, 4, 0, 1, 1);

        button_num_5 = new QPushButton(gridLayoutWidget);
        numButtonGroup->addButton(button_num_5);
        button_num_5->setObjectName("button_num_5");
        button_num_5->setMaximumSize(QSize(70, 42));
        button_num_5->setFont(font);
        button_num_5->setText(QString::fromUtf8("5"));
        button_num_5->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_num_5, 4, 1, 1, 1);

        button_factorial = new QPushButton(gridLayoutWidget);
        button_factorial->setObjectName("button_factorial");
        button_factorial->setMaximumSize(QSize(70, 42));
        button_factorial->setFont(font);
        button_factorial->setText(QString::fromUtf8("n!"));
        button_factorial->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_factorial, 1, 2, 1, 1);

        button_add = new QPushButton(gridLayoutWidget);
        button_add->setObjectName("button_add");
        button_add->setMaximumSize(QSize(70, 42));
        button_add->setSizeIncrement(QSize(1, 1));
        button_add->setBaseSize(QSize(70, 70));
        QFont font2;
        font2.setPointSize(14);
        button_add->setFont(font2);
        button_add->setText(QString::fromUtf8("+"));
        button_add->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_add, 1, 3, 1, 1);

        button_subtract = new QPushButton(gridLayoutWidget);
        button_subtract->setObjectName("button_subtract");
        button_subtract->setMaximumSize(QSize(70, 42));
        button_subtract->setSizeIncrement(QSize(1, 1));
        button_subtract->setBaseSize(QSize(70, 70));
        button_subtract->setFont(font2);
        button_subtract->setText(QString::fromUtf8("\342\210\222"));
        button_subtract->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_subtract, 2, 3, 1, 1);

        button_multiply = new QPushButton(gridLayoutWidget);
        button_multiply->setObjectName("button_multiply");
        button_multiply->setMaximumSize(QSize(70, 42));
        button_multiply->setSizeIncrement(QSize(1, 1));
        button_multiply->setBaseSize(QSize(70, 70));
        button_multiply->setFont(font2);
        button_multiply->setText(QString::fromUtf8("\303\227"));
        button_multiply->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_multiply, 4, 3, 1, 1);

        button_divide = new QPushButton(gridLayoutWidget);
        button_divide->setObjectName("button_divide");
        button_divide->setMaximumSize(QSize(70, 42));
        button_divide->setSizeIncrement(QSize(1, 1));
        button_divide->setBaseSize(QSize(70, 70));
        button_divide->setFont(font2);
        button_divide->setText(QString::fromUtf8("\303\267"));
        button_divide->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_divide, 5, 3, 1, 1);

        button_equal = new QPushButton(gridLayoutWidget);
        button_equal->setObjectName("button_equal");
        button_equal->setEnabled(true);
        button_equal->setMaximumSize(QSize(70, 42));
        button_equal->setSizeIncrement(QSize(1, 1));
        button_equal->setBaseSize(QSize(70, 70));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setKerning(true);
        font3.setStyleStrategy(QFont::PreferDefault);
        button_equal->setFont(font3);
        button_equal->setAcceptDrops(false);
        button_equal->setAutoFillBackground(false);
        button_equal->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 127); color: white"));
        button_equal->setText(QString::fromUtf8("="));
        button_equal->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_equal, 6, 3, 1, 1);

        button_absolute = new QPushButton(gridLayoutWidget);
        button_absolute->setObjectName("button_absolute");
        button_absolute->setMaximumSize(QSize(70, 42));
        button_absolute->setFont(font);
        button_absolute->setText(QString::fromUtf8("|x|"));
        button_absolute->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_absolute, 0, 1, 1, 1);

        button_close_parenthesis = new QPushButton(gridLayoutWidget);
        button_close_parenthesis->setObjectName("button_close_parenthesis");
        button_close_parenthesis->setMaximumSize(QSize(70, 42));
        button_close_parenthesis->setFont(font);
        button_close_parenthesis->setText(QString::fromUtf8(")"));
        button_close_parenthesis->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_close_parenthesis, 1, 1, 1, 1);

        button_open_parenthesis = new QPushButton(gridLayoutWidget);
        button_open_parenthesis->setObjectName("button_open_parenthesis");
        button_open_parenthesis->setMaximumSize(QSize(70, 42));
        button_open_parenthesis->setFont(font);
        button_open_parenthesis->setText(QString::fromUtf8("("));
        button_open_parenthesis->setIconSize(QSize(30, 30));

        gridLayout->addWidget(button_open_parenthesis, 1, 0, 1, 1);

        txtDisplay = new QLineEdit(centralwidget);
        txtDisplay->setObjectName("txtDisplay");
        txtDisplay->setGeometry(QRect(0, 75, 311, 31));
        QFont font4;
        font4.setPointSize(16);
        txtDisplay->setFont(font4);
        txtDisplay->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        txtDisplay->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        txtDisplay->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 2px solid transparent;"));
        txtDisplay->setInputMask(QString::fromUtf8(""));
        txtDisplay->setText(QString::fromUtf8(""));
        txtDisplay->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        txtDisplay->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 141, 41));
        QFont font5;
        font5.setPointSize(18);
        label->setFont(font5);
        hisDisplay = new QLineEdit(centralwidget);
        hisDisplay->setObjectName("hisDisplay");
        hisDisplay->setGeometry(QRect(0, 50, 311, 26));
        QFont font6;
        font6.setPointSize(12);
        font6.setWeight(QFont::Light);
        hisDisplay->setFont(font6);
        hisDisplay->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        hisDisplay->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        hisDisplay->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        hisDisplay->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: 2px solid transparent;\n"
""));
        hisDisplay->setInputMask(QString::fromUtf8(""));
        hisDisplay->setText(QString::fromUtf8(""));
        hisDisplay->setFrame(false);
        hisDisplay->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        hisDisplay->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(txtDisplay, button_num_1);
        QWidget::setTabOrder(button_num_1, button_num_2);
        QWidget::setTabOrder(button_num_2, button_num_3);
        QWidget::setTabOrder(button_num_3, button_num_4);
        QWidget::setTabOrder(button_num_4, button_num_5);
        QWidget::setTabOrder(button_num_5, button_num_6);
        QWidget::setTabOrder(button_num_6, button_num_7);
        QWidget::setTabOrder(button_num_7, button_num_8);
        QWidget::setTabOrder(button_num_8, button_num_9);
        QWidget::setTabOrder(button_num_9, button_num_0);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        label->setText(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
