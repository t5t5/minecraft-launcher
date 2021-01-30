#include "launcher.h"
#include "launcher_p.h"
#include "ui_launcher.h"

namespace ml
{

LauncherPrivate::LauncherPrivate()
	: ui(new Ui::Launcher())
{
}

LauncherPrivate::~LauncherPrivate()
{
	delete ui;
}

void LauncherPrivate::initialize()
{
	QA_Q();
	ui->setupUi(q);
}

void LauncherPrivate::reset()
{
}

// ------------------------------------------------------------------------
#ifndef Q_QDOC
namespace __________ { }
#endif // Q_QDOC
// ------------------------------------------------------------------------

Launcher::Launcher(QWidget *parent)
	: QWidget(parent)
	, d_ptr(new LauncherPrivate())
{
	QA_D();
	d->q_ptr = this;
	d->initialize();
}

Launcher::~Launcher()
{
}

void Launcher::setModel(const DataModelPointer& model)
{
	QA_D();
	if (d->model == model) { return; }
	if (d->model) {
		// TODO: disconnect
	}
	d->model = model;
	if (d->model) {
		// TODO: connect
	}
	d->reset();
}

} // namespace ml
