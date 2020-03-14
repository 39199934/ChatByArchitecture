#pragma once

#include "DatabaseProtocol.h"
#include "TestUser.h"

class TestUserDatabase : public DatabaseProtocol
{
	Q_OBJECT

public:
	TestUserDatabase(QObject *parent = nullptr);
	~TestUserDatabase();

public:
	int append(const TestUser& t);
protected:
	virtual int append(const QJsonDocument& t) override;
	virtual int remove(QString key, QVariant value) override;
	virtual QVector<QJsonDocument> search(QString key, QVariant value) override;
	virtual int update(QString key, QVariant value, const QJsonDocument& t) override;
protected:
	
	virtual QString getCreateString() override;
};
