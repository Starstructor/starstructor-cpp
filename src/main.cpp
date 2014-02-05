#include "gui/mainwindow.hpp"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication application{ argc, argv };

    Starstructor::MainWindow window;
    window.show();

	return application.exec();
}
