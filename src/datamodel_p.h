#ifndef DATAMODEL_P_H
#define DATAMODEL_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QString>
#include <QStringList>

#include <Qpe/Qpe>

#include "datamodel.h"

class QSettings;

namespace ml
{

class DataModelPrivate
{
	QPE_DECLARE_PUBLIC(DataModel);
protected:
	DataModel* q_ptr;
public:
	DataModelPrivate();
	~DataModelPrivate();

	void initialize();

	void readSettings();
	void writeSettings();
	void setDefaultSettings();
	bool searchJava(DataModel::JavaType type);
	bool searchLocalJava(QString& pathJava);

	QSettings* settings;
	QString fileName;
	QString currentDir;

	QString login;
	QStringList logins;
	int memorySize;
	int memorySizeMin;
	int memorySizeMax;

	DataModel::JavaType javaType;
//	bool isSystemJava;
	QString pathJava;

	QString parameters;
};

} // namespace ml

#endif // DATAMODEL_P_H
