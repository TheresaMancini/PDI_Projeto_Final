/********************************************************************************
** Form generated from reading UI file 'zebtrackpdi.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEBTRACKPDI_H
#define UI_ZEBTRACKPDI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <labeltrack.h>

QT_BEGIN_NAMESPACE

class Ui_ZebtrackPDI
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QPushButton *Abrir_Video;
    QPushButton *Novo_Fundo;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *sampleRate;
    QCheckBox *Estatistico;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *back_frame;
    QPushButton *next_frame;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *T_inicial;
    QSlider *Slider_Inicial;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *T_final;
    QSlider *Slider_Final;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpinBox *threshold;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpinBox *processRate;
    QCheckBox *mostraFore;
    QPushButton *gerar_graficos;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *init_process;
    QPushButton *pause_process;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *back_process;
    QPushButton *next_process;
    labeltrack *figura;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ZebtrackPDI)
    {
        if (ZebtrackPDI->objectName().isEmpty())
            ZebtrackPDI->setObjectName(QStringLiteral("ZebtrackPDI"));
        ZebtrackPDI->resize(552, 383);
        centralWidget = new QWidget(ZebtrackPDI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Abrir_Video = new QPushButton(tab);
        Abrir_Video->setObjectName(QStringLiteral("Abrir_Video"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Abrir_Video->sizePolicy().hasHeightForWidth());
        Abrir_Video->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(Abrir_Video);

        Novo_Fundo = new QPushButton(tab);
        Novo_Fundo->setObjectName(QStringLiteral("Novo_Fundo"));
        sizePolicy1.setHeightForWidth(Novo_Fundo->sizePolicy().hasHeightForWidth());
        Novo_Fundo->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(Novo_Fundo);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        sampleRate = new QSpinBox(tab);
        sampleRate->setObjectName(QStringLiteral("sampleRate"));

        horizontalLayout->addWidget(sampleRate);


        verticalLayout_4->addLayout(horizontalLayout);

        Estatistico = new QCheckBox(tab);
        Estatistico->setObjectName(QStringLiteral("Estatistico"));
        sizePolicy1.setHeightForWidth(Estatistico->sizePolicy().hasHeightForWidth());
        Estatistico->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(Estatistico);


        gridLayout_5->addLayout(verticalLayout_4, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        back_frame = new QPushButton(tab);
        back_frame->setObjectName(QStringLiteral("back_frame"));
        sizePolicy1.setHeightForWidth(back_frame->sizePolicy().hasHeightForWidth());
        back_frame->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(back_frame);

        next_frame = new QPushButton(tab);
        next_frame->setObjectName(QStringLiteral("next_frame"));
        sizePolicy1.setHeightForWidth(next_frame->sizePolicy().hasHeightForWidth());
        next_frame->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(next_frame);


        gridLayout_5->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        T_inicial = new QLineEdit(tab);
        T_inicial->setObjectName(QStringLiteral("T_inicial"));
        T_inicial->setMaximumSize(QSize(30, 25));

        horizontalLayout_4->addWidget(T_inicial);


        verticalLayout_2->addLayout(horizontalLayout_4);

        Slider_Inicial = new QSlider(tab);
        Slider_Inicial->setObjectName(QStringLiteral("Slider_Inicial"));
        Slider_Inicial->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Slider_Inicial);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        T_final = new QLineEdit(tab);
        T_final->setObjectName(QStringLiteral("T_final"));
        T_final->setMaximumSize(QSize(30, 25));

        horizontalLayout_5->addWidget(T_final);


        verticalLayout_3->addLayout(horizontalLayout_5);

        Slider_Final = new QSlider(tab);
        Slider_Final->setObjectName(QStringLiteral("Slider_Final"));
        Slider_Final->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(Slider_Final);


        horizontalLayout_6->addLayout(verticalLayout_3);


        gridLayout_5->addLayout(horizontalLayout_6, 3, 0, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_5);

        threshold = new QSpinBox(tab_2);
        threshold->setObjectName(QStringLiteral("threshold"));
        sizePolicy1.setHeightForWidth(threshold->sizePolicy().hasHeightForWidth());
        threshold->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(threshold);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(label_6);

        processRate = new QSpinBox(tab_2);
        processRate->setObjectName(QStringLiteral("processRate"));
        sizePolicy1.setHeightForWidth(processRate->sizePolicy().hasHeightForWidth());
        processRate->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(processRate);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_7->addLayout(verticalLayout_5);

        mostraFore = new QCheckBox(tab_2);
        mostraFore->setObjectName(QStringLiteral("mostraFore"));

        verticalLayout_7->addWidget(mostraFore);

        gerar_graficos = new QPushButton(tab_2);
        gerar_graficos->setObjectName(QStringLiteral("gerar_graficos"));
        sizePolicy1.setHeightForWidth(gerar_graficos->sizePolicy().hasHeightForWidth());
        gerar_graficos->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(gerar_graficos);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        init_process = new QPushButton(tab_2);
        init_process->setObjectName(QStringLiteral("init_process"));
        sizePolicy1.setHeightForWidth(init_process->sizePolicy().hasHeightForWidth());
        init_process->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(init_process);

        pause_process = new QPushButton(tab_2);
        pause_process->setObjectName(QStringLiteral("pause_process"));
        sizePolicy1.setHeightForWidth(pause_process->sizePolicy().hasHeightForWidth());
        pause_process->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(pause_process);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        back_process = new QPushButton(tab_2);
        back_process->setObjectName(QStringLiteral("back_process"));
        sizePolicy1.setHeightForWidth(back_process->sizePolicy().hasHeightForWidth());
        back_process->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(back_process);

        next_process = new QPushButton(tab_2);
        next_process->setObjectName(QStringLiteral("next_process"));
        sizePolicy1.setHeightForWidth(next_process->sizePolicy().hasHeightForWidth());
        next_process->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(next_process);


        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_7->addLayout(verticalLayout_6);


        gridLayout_4->addLayout(verticalLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        figura = new labeltrack(centralWidget);
        figura->setObjectName(QStringLiteral("figura"));

        gridLayout->addWidget(figura, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        ZebtrackPDI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ZebtrackPDI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 552, 21));
        ZebtrackPDI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ZebtrackPDI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ZebtrackPDI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ZebtrackPDI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ZebtrackPDI->setStatusBar(statusBar);

        retranslateUi(ZebtrackPDI);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ZebtrackPDI);
    } // setupUi

    void retranslateUi(QMainWindow *ZebtrackPDI)
    {
        ZebtrackPDI->setWindowTitle(QApplication::translate("ZebtrackPDI", "ZebtrackPDI", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ZebtrackPDI", "GroupBox", Q_NULLPTR));
        Abrir_Video->setText(QApplication::translate("ZebtrackPDI", "Abrir V\303\255deo", Q_NULLPTR));
        Novo_Fundo->setText(QApplication::translate("ZebtrackPDI", " Calcular \n"
" Novo Fundo", Q_NULLPTR));
        label_2->setText(QApplication::translate("ZebtrackPDI", "Sample \n"
" Period ", Q_NULLPTR));
        Estatistico->setText(QApplication::translate("ZebtrackPDI", "Estatistico", Q_NULLPTR));
        back_frame->setText(QApplication::translate("ZebtrackPDI", "<<", Q_NULLPTR));
        next_frame->setText(QApplication::translate("ZebtrackPDI", ">>", Q_NULLPTR));
        label_3->setText(QApplication::translate("ZebtrackPDI", "Frame Inicial", Q_NULLPTR));
        label_4->setText(QApplication::translate("ZebtrackPDI", "Frame Final", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ZebtrackPDI", "V\303\255deo", Q_NULLPTR));
        label_5->setText(QApplication::translate("ZebtrackPDI", "Threshold", Q_NULLPTR));
        label_6->setText(QApplication::translate("ZebtrackPDI", "Process. Frame Rate", Q_NULLPTR));
        mostraFore->setText(QApplication::translate("ZebtrackPDI", "Foreground", Q_NULLPTR));
        gerar_graficos->setText(QApplication::translate("ZebtrackPDI", "Gerar Gr\303\241fico", Q_NULLPTR));
        init_process->setText(QApplication::translate("ZebtrackPDI", "Iniciar", Q_NULLPTR));
        pause_process->setText(QApplication::translate("ZebtrackPDI", "Pausa", Q_NULLPTR));
        back_process->setText(QApplication::translate("ZebtrackPDI", "<<", Q_NULLPTR));
        next_process->setText(QApplication::translate("ZebtrackPDI", ">>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ZebtrackPDI", "Processamento", Q_NULLPTR));
        figura->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ZebtrackPDI: public Ui_ZebtrackPDI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEBTRACKPDI_H
