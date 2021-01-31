#ifndef DATAMODEL_H
#define DATAMODEL_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <QObject>
#include <QScopedPointer>
#include <QSharedPointer>

#include <Qpe/Qpe>

namespace ml
{

class DataModelPrivate;
class DataModel : public QObject
{
	Q_OBJECT
	QPE_DECLARE_PRIVATE(DataModel)
protected:
	QScopedPointer<DataModelPrivate> d_ptr;
public:
	DataModel(QObject* parent = nullptr);
	virtual ~DataModel() override;

	QString login() const;
	QStringList logins() const;
	int memorySize() const;
	int memorySizeMin() const;
	int memorySizeMax() const;
	bool isSystemJava() const;
	QString pathJava() const;
	QString parameters() const;

public slots:
	void setLogin(const QString& login);
	void setLogins(const QStringList& logins);
	void setMemorySize(int memorySize);
	void setIsSystemJava(bool isSystemJava);
	void setPathJava(const QString& pathJava);
	void setParameters(const QString& parameters);

	void run();
signals:
	void userNameChanged(const QString& userName);
	void memorySizeChanged(int memorySize);
	void memorySizeMinChanged(int memorySizeMin);
	void memorySizeMaxChanged(int memorySizeMax);
	void isSystemJavaChanged(bool isSystemJava);
	void pathJavaChanged(const QString& pathJava);
	void parametersChanged(const QString& parameters);
};

using DataModelPointer = QSharedPointer<DataModel>;

} // namespace ml

#endif // DATAMODEL_H
