#pragma once
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <QSqlError>
class DatabaseProtocol : public QObject
{
	Q_OBJECT

protected:
	QString sqlName;
	QString hostName;
	QString userName;
	QString password;
	QString databaseName;
	int port;


public:
	DatabaseProtocol(QObject * parent = nullptr);
	DatabaseProtocol(QString tableName, QObject* parent = nullptr);
	virtual ~DatabaseProtocol();
	virtual int createTable();
	virtual int dropTable();

public:
	virtual int append(const QJsonDocument& t) = 0;
	virtual int remove(QString key, QVariant value) = 0;
	virtual QVector<QJsonDocument> search(QString key, QVariant value) = 0;
	virtual int update(QString key, QVariant value, const QJsonDocument& t) = 0;
protected:
	virtual int query(QString queryString);
	virtual QString getCreateString() = 0;
protected:
	QSqlDatabase db;
	QString tableName;

signals:
	void signalDBHasError(const QSqlError& error);
};
