#include "launcher.h"
#include "launcher_p.h"
#include "ui_launcher.h"

#include <QIntValidator>

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
	ui->javaSettingsBox->setHidden(true);
	q->adjustSize();

	memoryValidator = new QIntValidator(q);
	ui->memoryEdit->setValidator(memoryValidator);

	QObject::connect(
		ui->settingsButton, &QToolButton::clicked,
		q, [q] { q->adjustSize(); } );

}

void LauncherPrivate::reset()
{
	ui->loginComboBox->clear();
	if (model) {
		ui->loginComboBox->addItems(model->logins());
		ui->loginComboBox->setCurrentText(model->login());
		ui->memoryEdit->setText(QString::number(model->memorySize()));

		memoryValidator->setBottom(model->memorySizeMin());
		memoryValidator->setTop(model->memorySizeMax());
	} else {
		ui->memoryEdit->setText(QString());
		ui->memoryEdit->setText("0");
		memoryValidator->setBottom(0);
		memoryValidator->setTop(0);
	}
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
