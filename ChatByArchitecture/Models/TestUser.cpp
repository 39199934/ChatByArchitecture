#include "TestUser.h"

TestUser::TestUser(QString n)
{
	this->name = n;
}

void TestUser::view()
{
	cout << "name:" << this->name.toStdString() << endl;
}
