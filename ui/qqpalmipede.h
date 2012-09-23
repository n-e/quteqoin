#ifndef QQPALMIPEDE_H
#define QQPALMIPEDE_H

#include <QGroupBox>
#include <QString>

class QColor;
class QShortcut;

namespace Ui {
class QQPalmipede;
}

class QQPalmipede : public QGroupBox
{
	Q_OBJECT

public:
	explicit QQPalmipede(QWidget *parent = 0);
	~QQPalmipede();

	//QString getCurrentBouchot();

	void insertText(const QString &);
	void addBouchot(const QString & newBouchot, const QColor & newBouchotColor);
	void removeBouchot(const QString & oldBouchot);

signals:
	void postMessage(const QString & bouchot, const QString & message);

public slots:
	void changePalmiColor(const QColor &);
	void insertSurroundText(const QString &, const QString &);
	void insertReplaceText(const QString &);

private:
	void changeNorloges(const QString & bouchot);
	void setMinimal(bool minimal);

	Ui::QQPalmipede *ui;
	QShortcut *blamShortcut;
	QShortcut *pafShortcut;
	QString m_oldBouchot;

	bool m_minimal;

private slots:
	void boldClicked();
	void italicClicked();
	void underlineClicked();
	void strikeClicked();
	void momentClicked();
	void blamPafActivated(const QString & text);
	void bouchotSelectorActivated(int index);
	void insertBlam();
	void insertPaf();
	void postPushButtonClicked();
	void minimizePalmi();
	void maximizePalmi();
};

#endif // QQPALMIPEDE_H
