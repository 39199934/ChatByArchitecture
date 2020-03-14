#pragma once
#include <QtCore>
#include <QUUID>
#include "BagProtocol.h"
#include <QImage>
class UserInfoProtocol:
	public BagProtocol
{
private:
	QString name;
	QString nickName;
	QString uuid;
	QImage photo;
public:
	QString getName();
	QString getNickName();
	QString getUuid();
	virtual void setName(QString name);
	virtual void setNickName(QString nickName);
	
protected:
	virtual void setValue() override;////��Ҫ�̳У����ڴ�doc��ת��Ϊ�����е�value����
	virtual void setDocument() override;///��Ҫ�̳У����ڴ�value��ת��Ϊ�����е�doc����
	
	virtual QJsonObject appendToSonsJson(QJsonObject* obj) override;
	virtual void appendToSonsValue(QJsonObject* obj) override;
	//virtual QJsonObject appendSonsJson(QJsonObject* obj);
	//virtual void appendSonsValue(QJsonObject* obj) = 0;
public:
	
	UserInfoProtocol();
	UserInfoProtocol(QString name, QString nick_name, QString user_uuid = QString());
	//virtual void fromBytes(QByteArray bytes) override;

	//virtual void fromBytes(QByteArray bytes) override;

	virtual ~UserInfoProtocol();
	void setUserInfoProtocol(QString name, QString nick_name,QString user_uuid = QString());
	virtual QString getDescription();
	//virtual void setValue() override;
	void createUuid();

	
	

};

