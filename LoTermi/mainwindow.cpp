#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "randqi.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    //修改窗口标题
    setWindowTitle("LoTermi");
    //下拉菜单
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    QMenu *fileMenu = menuBar->addMenu("文件...");
    QAction *newAction = fileMenu->addAction("新建...");
    QAction *openAction = fileMenu->addAction("打开...");
    QMenu *aboutMenu = menuBar->addMenu("关于...");
    QAction *licenseAction = aboutMenu->addAction("许可证条款...");
    QAction *aboutAction = aboutMenu->addAction("关于LoTermi...");
    //菜单事件
    connect(newAction, &QAction::triggered, this, [this]() {
        // 生成随机数
        int rn = randRange(1,100);
        //显示
        if(!MainWindow::label){
            label = new QLabel(QString("随机数(1~100): %1").arg(rn), this);
        }
        QFont font = label->font();
        font.setPointSize(20);
        label->setFont(font);
        label->adjustSize();
        label->move(438, 250);
        label->setText(QString("随机数(1~100): %1").arg(rn));
        label->show();
    });
    connect(aboutAction, &QAction::triggered, this, [this]() {
         QMessageBox::about(this, "关于", QString("本程序版本：%1\n本程序使用的 C++ 版本：%2\nLoTermi是Lottery1.x的后继，原名Lottery2，别名LAT，全名Lottery And Terminal.").arg(VER).arg(__cplusplus));
         return 0;
    });
    connect(licenseAction, &QAction::triggered, this, [this]() {
        QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"), "", tr("所有文件 (*)"));
            if (!fileName.isEmpty()) {
                //打开文件后的处理逻辑
                qDebug() << "打开的文件：" << fileName;
                QFile file(fileName);
                       if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                           QTextStream in(&file);
                           QString content = in.readAll();
                           file.close();
                           // 在这里可以对读取到的文件内容进行处理
                           QMessageBox msgBox;
                           msgBox.setIcon(QMessageBox::Information);
                           msgBox.setText("文件内容");
                           msgBox.setInformativeText(QString(content.left(20)+"%1").arg("..."));
                           msgBox.setDetailedText(content);
                           msgBox.exec();
                           qDebug() << "文件内容：" << content;
                       } else {
                           qDebug() << "无法打开文件。";
                       }
            }
         QMessageBox::about(this, QString("%1许可证").arg(VER), QString("%1:\nMyLICENSE-v1.0.240927\ncpp%2:cpp license").arg(VER).arg("").arg(__cplusplus));
         return 0;
    });
    connect(openAction, &QAction::triggered, this, [this](){
        QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"), "", tr("所有文件 (*)"));
            if (!fileName.isEmpty()) {
                //打开文件后的处理逻辑
                qDebug() << "打开的文件：" << fileName;
                QFile file(fileName);
                       if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                           QTextStream in(&file);
                           QString content = in.readAll();
                           file.close();
                           // 在这里可以对读取到的文件内容进行处理
                           QMessageBox msgBox;
                           msgBox.setIcon(QMessageBox::Information);
                           msgBox.setText("文件内容");
                           msgBox.setInformativeText(QString(content.left(20)+"%1").arg("..."));
                           msgBox.setDetailedText(content);
                           msgBox.exec();
                           qDebug() << "文件内容：" << content;
                       } else {
                           qDebug() << "无法打开LICENSE文件。";
                       }
            }

    });
    //按钮事件
    ui->lunchButton->setStyleSheet("QPushButton { font-size: 18pt; }");
    connect(ui->lunchButton, &QPushButton::clicked, this, [this](){
        ui->lunchButton->setEnabled(false);
        QMessageBox::information(this,"吃饭顺序","即将揭晓吃饭顺序……");
        for (int i=0;i<50;i++) {
            std::vector<int> vl;
            for (int i=0;i<8;i++) {
                vl.push_back(i+1);
            }
            QString rn="";
            while(!vl.empty()) {
                int ri=randRange(0,vl.size()-1);
                rn=rn+QString::number(vl[ri]);
                vl.erase(vl.begin()+ri);
            }
            QString s=QString("吃饭顺序:%1").arg(rn);
            if(!MainWindow::label){
                label = new QLabel(s, this);
            }
            QFont font = label->font();
            font.setPointSize(22);
            label->setFont(font);
            label->adjustSize();
            label->setText(s);
            label->move(415, 250);
            label->show();
            QEventLoop loop;
            QTimer::singleShot(100, &loop, &QEventLoop::quit);
            loop.exec();
        }
        ui->lunchButton->setEnabled(true);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

