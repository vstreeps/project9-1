#include <QtGui>
#include <QTimer>
#include <QMessageBox>
#include "mainwindow.h"

bool isPause = false;
bool isStarted = false;

MainWindow::MainWindow() {
	setWindowTitle(tr("Timer"));
	resize(700, 200);
	textLabel = new QLabel(this);
	textLabel->setText("000");
	textLabel->setGeometry(20, 150, 1200, 600);
	textLabel->setFont(QFont("Courier", 520, QFont::Bold));
	
	QPushButton *startButton = new QPushButton(tr("Start"), this);
	startButton->setGeometry(20, 5, 75, 30);
	startButton->setFont(QFont("Times", 18, QFont::Bold));
	connect(startButton, SIGNAL(clicked()), this, SLOT(startButtonClick()));
	
	QPushButton *stopButton = new QPushButton(tr("Stop"), this);
	stopButton->setGeometry(140, 5, 75, 30);
	stopButton->setFont(QFont("Times", 18, QFont::Bold));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(stopButtonClick()));
	
	timeEdit = new QLineEdit(this);
	timeEdit->setGeometry(20, 100, 200, 20);
	
	myTimer = new QTimer(this);
	connect(myTimer, SIGNAL(timeout()), this, SLOT(runClock()));
}

void MainWindow::startButtonClick() {
	if(isStarted) {
		if(isPause) {
			isPause = false;
			myTimer->start(1000);
		}
		else {
			isPause = true;
			myTimer->stop();
		}
		isStarted = true;
	}
	else {
		mySeconds = (timeEdit->text()).toInt();
		textLabel->setText(timeEdit->text());
		if( mySeconds < 100 )
		textLabel->setText("0" + timeEdit->text());
	
	if( mySeconds < 10 )
		textLabel->setText("00" + timeEdit->text());
		myTimer->start(1000);
		isStarted = true;
	}
}

void MainWindow::stopButtonClick() {
	isStarted = false;
	myTimer->stop();
}

void MainWindow::runClock() {
	mySeconds--;
	if( mySeconds < 1 )
		myTimer->stop();
	QString time;
	time.setNum(mySeconds);
	textLabel->setText(time);
	if( mySeconds < 100 )
		textLabel->setText("0" + time);
	
	if( mySeconds < 10 )
		textLabel->setText("00" + time);
}
