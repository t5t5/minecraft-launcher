#include <QApplication>

#include <ml/Launcher>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


	ml::DataModelPointer model = ml::DataModelPointer::create();

	ml::Launcher launcher;
	launcher.setModel(model);
	launcher.show();

	return a.exec();
}
