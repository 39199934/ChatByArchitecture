#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatByArchitecture.h"

class ChatByArchitecture : public QMainWindow
{
	Q_OBJECT

public:
	ChatByArchitecture(QWidget *parent = Q_NULLPTR);

private:
	Ui::ChatByArchitectureClass ui;
};
