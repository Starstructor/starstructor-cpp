#include "mainwindow.hpp"

namespace Starstructor {

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow{parent}, m_ui{new Ui::ApplicationWindow{}}
{
    m_ui->setupUi(this);
}

}