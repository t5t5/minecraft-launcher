#include "datamodel.h"
#include "datamodel_p.h"

namespace ml
{

DataModelPrivate::DataModelPrivate()
{
}

DataModelPrivate::~DataModelPrivate()
{
}

void DataModelPrivate::initialize()
{
	// TODO: load settings
	// TODO: java search
}

// ------------------------------------------------------------------------
#ifndef Q_QDOC
namespace __________ { }
#endif // Q_QDOC
// ------------------------------------------------------------------------

DataModel::DataModel(QObject* parent /* = nullptr */)
	: QObject(parent)
	, d_ptr(new DataModelPrivate())
{
	QA_D();
	d->q_ptr = this;
	d->initialize();
}

DataModel::~DataModel()
{
}

QString DataModel::login() const
{
	QA_D();
	return d->login;
}

void DataModel::setLogin(const QString& login)
{
	QA_D();
	d->login = login;
}

int DataModel::memorySize() const
{
	QA_D();
	return d->memorySize;
}

void DataModel::setMemorySize(int memorySize)
{
	QA_D();
	d->memorySize = memorySize;
}

bool DataModel::isSystemJava() const
{
	QA_D();
	return d->isSystemJava;
}

void DataModel::setIsSystemJava(bool isSystemJava)
{
	QA_D();
	d->isSystemJava = isSystemJava;
}

QString DataModel::pathJava() const
{
	QA_D();
	return d->pathJava;
}

void DataModel::setPathJava(const QString& pathJava)
{
	QA_D();
	d->pathJava = pathJava;
}

QString DataModel::parameters() const
{
	QA_D();
	return d->parameters;
}

void DataModel::setParameters(const QString& parameters)
{
	QA_D();
	d->parameters = parameters;
}

void DataModel::run()
{
	// TODO: application launch here!
}

} // namespace ml
