#include "datamodel.h"
#include "datamodel_p.h"

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QRegularExpression>
#include <QSettings>

namespace ml
{

static const QLatin1String TEMPLATE_FILE_NAME("%1.ini");

static const QLatin1String KEY_LOGIN("main/login");
static const QLatin1String KEY_LOGINS("main/logins");
static const QLatin1String KEY_JAVA_PATH("java/path");
static const QLatin1String KEY_JAVA_MEMORY("java/memory");
static const QLatin1String KEY_JAVA_MEMORY_MIN("java/memoryMin");
static const QLatin1String KEY_JAVA_MEMORY_MAX("java/memoryMax");

static const int DEFAULT_MEMORY_SIZE = 2048;
static const int DEFAULT_MEMORY_MIN_SIZE = 1024;
static const int DEFAULT_MEMORY_MAX_SIZE = 32768;

static const QLatin1String ARGUMENT_VERSION("-version");
static const QLatin1String VALUE_JAVA("java");
static const QLatin1String VALUE_JRE("jre");
static const QLatin1String REGEX_JRE("^jre");
static const QLatin1String TEMPLATE_LOCAL_JAVA("%1/%2/bin/java");

DataModelPrivate::DataModelPrivate()
	: settings(nullptr)
	, javaType(DataModel::JavaType::AutoJava)
{
}

DataModelPrivate::~DataModelPrivate()
{
	if (settings != nullptr) {
		delete settings;
	}
}

void DataModelPrivate::initialize()
{
	fileName = QString(TEMPLATE_FILE_NAME).arg(QCoreApplication::instance()->applicationName());
	currentDir = QCoreApplication::instance()->applicationDirPath();

	settings = new QSettings(fileName, QSettings::IniFormat);

	if (QFile::exists(fileName)) {
		readSettings();
	} else {
		setDefaultSettings();
		writeSettings();
	}

	searchJava(DataModel::LocalJava);
	// TODO: load settings
	// TODO: java search
}

void DataModelPrivate::readSettings()
{
	login = settings->value(KEY_LOGIN).toString();
	logins = settings->value(KEY_LOGINS).toStringList();

	pathJava = settings->value(KEY_JAVA_PATH).toString();
	memorySize = settings->value(KEY_JAVA_MEMORY, DEFAULT_MEMORY_SIZE).toInt();
	memorySizeMin = settings->value(KEY_JAVA_MEMORY_MIN, DEFAULT_MEMORY_MIN_SIZE).toInt();
	memorySizeMax = settings->value(KEY_JAVA_MEMORY_MAX, DEFAULT_MEMORY_MAX_SIZE).toInt();
}

void DataModelPrivate::writeSettings()
{
	settings->setValue(KEY_LOGIN, login);
	settings->setValue(KEY_LOGINS, logins);
	settings->setValue(KEY_JAVA_PATH, pathJava);
	settings->setValue(KEY_JAVA_MEMORY, memorySize);
	settings->setValue(KEY_JAVA_MEMORY_MIN, memorySizeMin);
	settings->setValue(KEY_JAVA_MEMORY_MAX, memorySizeMax);
}

void DataModelPrivate::setDefaultSettings()
{
	login = "User";
	logins.clear();
	logins.append(login);
	logins.append("1,");
	logins.append("2");


	memorySize = DEFAULT_MEMORY_SIZE;
	memorySizeMin = DEFAULT_MEMORY_MIN_SIZE;
	memorySizeMax = DEFAULT_MEMORY_MAX_SIZE;
}

bool DataModelPrivate::searchJava(DataModel::JavaType type) const
{
	bool result = true;
	QString command;
	switch (type) {
	case DataModel::SystemJava:
		command = VALUE_JAVA;
		break;
	case DataModel::LocalJava: {
		result = searchLocalJava(command);
		break;
	}
	case DataModel::CustomJava:
		command = pathJava;
		break;
	default:
		result = false;
		break;
	}
	if (!result) { return false; }
	int code = QProcess::execute(command, { ARGUMENT_VERSION });
	return code == 0;
}

bool DataModelPrivate::searchLocalJava(QString& pathJava) const
{
	QDir dir(currentDir);
	if (!dir.cd(VALUE_JRE)) { return false; }

	const QStringList entries = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
	const QStringList filtered = entries.filter(QRegularExpression(REGEX_JRE));
	if (filtered.isEmpty()) { return false; }
	for (const QString& v : filtered) {
		QString command = QString(TEMPLATE_LOCAL_JAVA).arg(dir.absolutePath() ,v);
		int code = QProcess::execute(command, { ARGUMENT_VERSION });
		if (code == 0) {
			pathJava = command;
			return true;
		}
	}
	return false;
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

QStringList DataModel::logins() const
{
	QA_D();
	return d->logins;
}

void DataModel::setLogin(const QString& login)
{
	QA_D();
	d->login = login;
}

void DataModel::setLogins(const QStringList& logins)
{
	QA_D();
	d->logins = logins;
}

int DataModel::memorySize() const
{
	QA_D();
	return d->memorySize;
}

int DataModel::memorySizeMin() const
{
	QA_D();
	return d->memorySizeMin;
}

int DataModel::memorySizeMax() const
{
	QA_D();
	return d->memorySizeMax;
}

void DataModel::setMemorySize(int memorySize)
{
	QA_D();
	d->memorySize = memorySize;
}

//bool DataModel::isSystemJava() const
//{
//	QA_D();
//	return d->isSystemJava;
//}

//void DataModel::setIsSystemJava(bool isSystemJava)
//{
//	QA_D();
//	d->isSystemJava = isSystemJava;
//}

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

DataModel::JavaType DataModel::javaType() const
{

}

bool DataModel::isJavaValid(DataModel::JavaType javaType) const
{
	QA_D();
	return d->searchJava(javaType);
	return true;
}

void DataModel::setParameters(const QString& parameters)
{
	QA_D();
	d->parameters = parameters;
}

void DataModel::setJavaType(DataModel::JavaType javaType)
{

}


void DataModel::run()
{
	// TODO: application launch here!
}

} // namespace ml
