#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTimer;
class QLineEdit;
QT_END_NAMESPACE
class MainWindow : public QMainWindow {
	Q_OBJECT
	public:
		MainWindow();
		
	private slots:
		void runClock();
		void startButtonClick();
		void stopButtonClick();
		
	private:
		QLabel *textLabel;
		QPushButton *startButton;
		QPushButton *stopButton;
		QTimer *myTimer;
		int mySeconds;
		QLineEdit *timeEdit;
};
#endif
