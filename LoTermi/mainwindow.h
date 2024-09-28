#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//Qt include
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QtDebug>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QIcon>
#include <QInputDialog>
#include <QCoreApplication>
#include <QApplication>
#include <QTimer>
//cpp include
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include "randqi.h"
#define VER "LoTermi-2.0.1-Alpha"
#define lg long
#define db double
#define ll long long

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QLabel *label = nullptr;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
};


#endif // MAINWINDOW_H
