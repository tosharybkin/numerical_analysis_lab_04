/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *k_in_main;
    QLineEdit *accuracy_in_main;
    QLabel *label_3;
    QLineEdit *max_iters_in_main;
    QLineEdit *m_y_partitions_in_main;
    QPushButton *calc_button_main;
    QLabel *label_4;
    QLineEdit *n_x_partitions_in_main;
    QLabel *label_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QTableWidget *out_table_2_main;
    QTableWidget *out_table_main;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLabel *accuracy_lbl_main;
    QLabel *test_accurac_lbl_main;
    QLabel *label_6;
    QLabel *step_num_lbl_main;
    QLabel *label_10;
    QTableWidget *out_table_3_main;
    QWidget *tab_4;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLineEdit *m_y_partitions_in_test;
    QLineEdit *max_iters_in_test;
    QLineEdit *n_x_partitions_in_test;
    QLabel *label_9;
    QLineEdit *accuracy_in_test;
    QLabel *label_13;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *k_in_test;
    QPushButton *calc_button_test;
    QTableWidget *out_table_test;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_6;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *accuracy_lbl_test;
    QLabel *test_accurac_lbl_test;
    QLabel *step_num_lbl_test;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *out_table_2_test;
    QTableWidget *out_table_3_test;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 798);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDocumentMode(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 100));
        groupBox->setMaximumSize(QSize(760, 100));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        k_in_main = new QLineEdit(groupBox);
        k_in_main->setObjectName(QString::fromUtf8("k_in_main"));

        gridLayout_2->addWidget(k_in_main, 0, 5, 1, 1);

        accuracy_in_main = new QLineEdit(groupBox);
        accuracy_in_main->setObjectName(QString::fromUtf8("accuracy_in_main"));
        accuracy_in_main->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(accuracy_in_main, 0, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        max_iters_in_main = new QLineEdit(groupBox);
        max_iters_in_main->setObjectName(QString::fromUtf8("max_iters_in_main"));
        max_iters_in_main->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(max_iters_in_main, 1, 3, 1, 1);

        m_y_partitions_in_main = new QLineEdit(groupBox);
        m_y_partitions_in_main->setObjectName(QString::fromUtf8("m_y_partitions_in_main"));
        m_y_partitions_in_main->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(m_y_partitions_in_main, 1, 1, 1, 1);

        calc_button_main = new QPushButton(groupBox);
        calc_button_main->setObjectName(QString::fromUtf8("calc_button_main"));

        gridLayout_2->addWidget(calc_button_main, 1, 5, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 2, 1, 1);

        n_x_partitions_in_main = new QLineEdit(groupBox);
        n_x_partitions_in_main->setObjectName(QString::fromUtf8("n_x_partitions_in_main"));
        n_x_partitions_in_main->setMaximumSize(QSize(150, 16777215));

        gridLayout_2->addWidget(n_x_partitions_in_main, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 3, 0, 1, 1);

        out_table_2_main = new QTableWidget(tab_3);
        out_table_2_main->setObjectName(QString::fromUtf8("out_table_2_main"));
        out_table_2_main->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_2_main->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_2_main->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_4->addWidget(out_table_2_main, 1, 0, 1, 3);

        out_table_main = new QTableWidget(tab_3);
        out_table_main->setObjectName(QString::fromUtf8("out_table_main"));
        out_table_main->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_main->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_main->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_4->addWidget(out_table_main, 0, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 100));
        groupBox_2->setMaximumSize(QSize(760, 100));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 0, 1, 1, 1);

        accuracy_lbl_main = new QLabel(groupBox_2);
        accuracy_lbl_main->setObjectName(QString::fromUtf8("accuracy_lbl_main"));

        gridLayout_3->addWidget(accuracy_lbl_main, 1, 0, 1, 1);

        test_accurac_lbl_main = new QLabel(groupBox_2);
        test_accurac_lbl_main->setObjectName(QString::fromUtf8("test_accurac_lbl_main"));

        gridLayout_3->addWidget(test_accurac_lbl_main, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        step_num_lbl_main = new QLabel(groupBox_2);
        step_num_lbl_main->setObjectName(QString::fromUtf8("step_num_lbl_main"));

        gridLayout_3->addWidget(step_num_lbl_main, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 0, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 4, 1, 1, 1);

        out_table_3_main = new QTableWidget(tab_3);
        out_table_3_main->setObjectName(QString::fromUtf8("out_table_3_main"));
        out_table_3_main->setToolTipDuration(-1);
        out_table_3_main->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_3_main->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_3_main->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_4->addWidget(out_table_3_main, 2, 0, 1, 3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_7 = new QGridLayout(tab_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 100));
        groupBox_3->setMaximumSize(QSize(760, 100));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        m_y_partitions_in_test = new QLineEdit(groupBox_3);
        m_y_partitions_in_test->setObjectName(QString::fromUtf8("m_y_partitions_in_test"));
        m_y_partitions_in_test->setMaximumSize(QSize(150, 16777215));

        gridLayout_5->addWidget(m_y_partitions_in_test, 1, 1, 1, 1);

        max_iters_in_test = new QLineEdit(groupBox_3);
        max_iters_in_test->setObjectName(QString::fromUtf8("max_iters_in_test"));
        max_iters_in_test->setMaximumSize(QSize(150, 16777215));

        gridLayout_5->addWidget(max_iters_in_test, 1, 3, 1, 1);

        n_x_partitions_in_test = new QLineEdit(groupBox_3);
        n_x_partitions_in_test->setObjectName(QString::fromUtf8("n_x_partitions_in_test"));
        n_x_partitions_in_test->setMaximumSize(QSize(150, 16777215));

        gridLayout_5->addWidget(n_x_partitions_in_test, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        accuracy_in_test = new QLineEdit(groupBox_3);
        accuracy_in_test->setObjectName(QString::fromUtf8("accuracy_in_test"));
        accuracy_in_test->setMaximumSize(QSize(150, 16777215));

        gridLayout_5->addWidget(accuracy_in_test, 0, 3, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_5->addWidget(label_13, 0, 4, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 1, 2, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 2, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 1, 0, 1, 1);

        k_in_test = new QLineEdit(groupBox_3);
        k_in_test->setObjectName(QString::fromUtf8("k_in_test"));

        gridLayout_5->addWidget(k_in_test, 0, 5, 1, 1);

        calc_button_test = new QPushButton(groupBox_3);
        calc_button_test->setObjectName(QString::fromUtf8("calc_button_test"));

        gridLayout_5->addWidget(calc_button_test, 1, 5, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 3, 1, 1, 1);

        out_table_test = new QTableWidget(tab_4);
        out_table_test->setObjectName(QString::fromUtf8("out_table_test"));
        out_table_test->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_test->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_test->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_7->addWidget(out_table_test, 0, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 100));
        groupBox_4->setMaximumSize(QSize(760, 100));
        gridLayout_6 = new QGridLayout(groupBox_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_6->addWidget(label_14, 0, 0, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 0, 2, 1, 1);

        accuracy_lbl_test = new QLabel(groupBox_4);
        accuracy_lbl_test->setObjectName(QString::fromUtf8("accuracy_lbl_test"));

        gridLayout_6->addWidget(accuracy_lbl_test, 1, 0, 1, 1);

        test_accurac_lbl_test = new QLabel(groupBox_4);
        test_accurac_lbl_test->setObjectName(QString::fromUtf8("test_accurac_lbl_test"));

        gridLayout_6->addWidget(test_accurac_lbl_test, 1, 1, 1, 1);

        step_num_lbl_test = new QLabel(groupBox_4);
        step_num_lbl_test->setObjectName(QString::fromUtf8("step_num_lbl_test"));

        gridLayout_6->addWidget(step_num_lbl_test, 1, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_4, 4, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        out_table_2_test = new QTableWidget(tab_4);
        out_table_2_test->setObjectName(QString::fromUtf8("out_table_2_test"));
        out_table_2_test->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_2_test->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_2_test->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_7->addWidget(out_table_2_test, 1, 0, 1, 3);

        out_table_3_test = new QTableWidget(tab_4);
        out_table_3_test->setObjectName(QString::fromUtf8("out_table_3_test"));
        out_table_3_test->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_3_test->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        out_table_3_test->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_7->addWidget(out_table_3_test, 2, 0, 1, 3);

        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(n_x_partitions_in_main, m_y_partitions_in_main);
        QWidget::setTabOrder(m_y_partitions_in_main, accuracy_in_main);
        QWidget::setTabOrder(accuracy_in_main, max_iters_in_main);
        QWidget::setTabOrder(max_iters_in_main, calc_button_main);
        QWidget::setTabOrder(calc_button_main, n_x_partitions_in_test);
        QWidget::setTabOrder(n_x_partitions_in_test, m_y_partitions_in_test);
        QWidget::setTabOrder(m_y_partitions_in_test, accuracy_in_test);
        QWidget::setTabOrder(accuracy_in_test, max_iters_in_test);
        QWidget::setTabOrder(max_iters_in_test, out_table_main);
        QWidget::setTabOrder(out_table_main, out_table_test);
        QWidget::setTabOrder(out_table_test, tabWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 4", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\265\321\202\320\276\320\264\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\240\320\260\320\267\320\261\320\270\320\265\320\275\320\270\320\271 \320\277\320\276 X</span></p></body></html>", nullptr));
        k_in_main->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        accuracy_in_main->setText(QCoreApplication::translate("MainWindow", "0.00001", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214</span></p></body></html>", nullptr));
        max_iters_in_main->setText(QCoreApplication::translate("MainWindow", "100000", nullptr));
        m_y_partitions_in_main->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        calc_button_main->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214!", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\230\321\202\320\265\321\200\320\260\321\206\320\270\320\270</span><span style=\" font-size:10pt; vertical-align:sub;\">max</span></p></body></html>", nullptr));
        n_x_partitions_in_main->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\240\320\260\320\267\320\261\320\270\320\265\320\275\320\270\320\271 \320\277\320\276 Y</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "k:", nullptr));
#if QT_CONFIG(tooltip)
        out_table_2_main->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">V2</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        out_table_main->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">V</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\271 \320\267\320\260\320\264\320\260\321\207\320\270 \342\206\223</span></p></body></html>", nullptr));
        accuracy_lbl_main->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        test_accurac_lbl_main->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\224\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202\320\260\321\217 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\274\320\265\321\202\320\276\320\264\320\260 \342\206\223</span></p></body></html>", nullptr));
        step_num_lbl_main->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\247\320\270\321\201\320\273\320\276 \320\267\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\275\321\213\321\205 \321\210\320\260\320\263\320\276\320\262 \342\206\223</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        out_table_3_main->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">|V - V2|</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        out_table_3_main->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">|V - V2|</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\265\321\202\320\276\320\264\320\260", nullptr));
        m_y_partitions_in_test->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        max_iters_in_test->setText(QCoreApplication::translate("MainWindow", "100000", nullptr));
        n_x_partitions_in_test->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\240\320\260\320\267\320\261\320\270\320\265\320\275\320\270\320\271 \320\277\320\276 X</span></p></body></html>", nullptr));
        accuracy_in_test->setText(QCoreApplication::translate("MainWindow", "0.00001", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "k:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\230\321\202\320\265\321\200\320\260\321\206\320\270\320\270</span><span style=\" font-size:10pt; vertical-align:sub;\">max</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\240\320\260\320\267\320\261\320\270\320\265\320\275\320\270\320\271 \320\277\320\276 Y</span></p></body></html>", nullptr));
        k_in_test->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        calc_button_test->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214!", nullptr));
#if QT_CONFIG(tooltip)
        out_table_test->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">V</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\224\320\276\321\201\321\202\320\270\320\263\320\275\321\203\321\202\320\260\321\217 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\274\320\265\321\202\320\276\320\264\320\260 \342\206\223</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 \321\202\320\265\321\201\321\202\320\276\320\262\320\276\320\271 \320\267\320\260\320\264\320\260\321\207\320\270 \342\206\223</span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\247\320\270\321\201\320\273\320\276 \320\267\320\260\321\202\321\200\320\260\321\207\320\265\320\275\320\275\321\213\321\205 \321\210\320\260\320\263\320\276\320\262 \342\206\223</span></p></body></html>", nullptr));
        accuracy_lbl_test->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        test_accurac_lbl_test->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        step_num_lbl_test->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
#if QT_CONFIG(tooltip)
        out_table_2_test->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">U</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        out_table_3_test->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">|V - U|</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
