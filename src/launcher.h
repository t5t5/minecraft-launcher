#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QDialog>

#include <Qpe/Qpe>

#include <ml/DataModel>

namespace ml
{

class LauncherPrivate;
class Launcher : public QWidget
{
	Q_OBJECT
	QPE_DECLARE_PRIVATE(Launcher);
protected:
	QScopedPointer<LauncherPrivate> d_ptr;
public:
	Launcher(QWidget* parent = nullptr);
	virtual ~Launcher() override;

	void setModel(const DataModelPointer& model);
};

} // namespace ml

#endif // LAUNCHER_H
