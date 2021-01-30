#ifndef DATAMODEL_P_H
#define DATAMODEL_P_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QString>

#include <Qpe/Qpe>

namespace ml
{

class DataModel;
class DataModelPrivate
{
	QPE_DECLARE_PUBLIC(DataModel);
protected:
	DataModel* q_ptr;
public:
	DataModelPrivate();
	~DataModelPrivate();

	void initialize();

	QString login;
	int memorySize;

	bool isSystemJava;
	QString pathJava;

	QString parameters;
};

} // namespace ml

#endif // DATAMODEL_P_H
