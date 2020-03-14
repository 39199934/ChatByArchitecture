#include "TestUserDatabase.h"

TestUserDatabase::TestUserDatabase(QObject *parent)
	:DatabaseProtocol("testUser",parent)
{
}

TestUserDatabase::~TestUserDatabase()
{
}


int TestUserDatabase::append(const TestUser& t)
{
	QJsonObject obj;
	obj.insert("name", t.name);
	QJsonDocument doc;
	doc.setObject(obj);
	return append(doc);
	return 0;
}

int TestUserDatabase::append(const QJsonDocument& t)
{
	auto obj = t.object();
	QString queryString = "INSERT INTO `" + databaseName + "`.`" + tableName + "` (`name`) VALUES ( '" + obj.value("name").toString() + "' ); ";
	return query(queryString);
	return 0;
}

int TestUserDatabase::remove(QString key, QVariant value)
{
	return 0;
}

QVector<QJsonDocument> TestUserDatabase::search(QString key, QVariant value)
{
	return QVector<QJsonDocument>();
}

int TestUserDatabase::update(QString key, QVariant value, const QJsonDocument& t)
{
	return 0;
}

QString TestUserDatabase::getCreateString()
{
	return "( `name` CHAR(20) ) CHARSET=utf8; ";
}
