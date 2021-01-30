#include <QApplication>

#include <ml/Launcher>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ml::Launcher w;
	w.show();
	return a.exec();
}
