#include "DatabaseProtocol.h"
#include <iostream>
#include <QDebug>
using namespace std;
DatabaseProtocol::DatabaseProtocol(QObject* parent )
	: QObject(parent),
	sqlName("QMYSQL"),
	hostName("192.168.31.101"),
	port(23306),
	userName("root"),
	password("lode801103?"),
	databaseName("chatSql")
{
	db = QSqlDatabase::addDatabase(sqlName);
	db.setDatabaseName(databaseName);
	db.setHostName(hostName);
	db.setPassword(password);
	db.setPort(port);
	db.setUserName(userName);
	auto rt = db.open();
	if (!rt) {
		emit signalDBHasError(db.lastError());
		cout << (db.lastError().text().toStdString());
	}
	
}

DatabaseProtocol::DatabaseProtocol(QString tableName, QObject* parent ):
	DatabaseProtocol(parent)
{
	this->tableName = tableName;
}

DatabaseProtocol::~DatabaseProtocol()
{
	if (db.isOpen()) {
		db.close();
	}
}

int DatabaseProtocol::createTable()
{
	QString oriStr = "CREATE TABLE `" + databaseName + "`.`" + tableName + "` ";
	oriStr = oriStr + getCreateString();
	return query(oriStr);
}

int DatabaseProtocol::dropTable()
{
	QString queryString = "DROP TABLE `" + databaseName + "`.`" + tableName + "`; ";
	
	return query(queryString);
}

int DatabaseProtocol::query(QString queryString)
{
	QSqlQuery sqlQuery(db);
	if (sqlQuery.exec(queryString)) {
		qDebug() << sqlQuery.executedQuery()<<"  number:"<<sqlQuery.numRowsAffected();
		return sqlQuery.numRowsAffected();
	}
	else {
		qDebug() << sqlQuery.executedQuery() << "  number:" << sqlQuery.numRowsAffected()<<" error:"<<sqlQuery.lastError();
		emit signalDBHasError(sqlQuery.lastError());
		return -1;
	}
	
	
}
