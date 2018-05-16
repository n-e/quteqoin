#include "qqmlpalmipede.h"

#include <QApplication>
#include <QQmlContext>
/**
 * @brief QQmlPalmipede::QQmlPalmipede
 * @param parent
 */
QQmlPalmipede::QQmlPalmipede(QWidget *parent) : QQuickWidget(parent)
{
	setSource(QUrl("qrc:/qml/QQmlPalmi.qml"));
	rootContext()->setContextProperty("backend", this);

	// Rethrow QML Signals
	connect(rootObject(), SIGNAL(post(QString, QString)),
			this, SIGNAL(postMessage(QString,QString)));
}

/**
 * @brief QQmlPalmipede::insertReplaceText
 * @param txt
 */
void QQmlPalmipede::insertReplaceText(const QString &txt)
{
	QMetaObject::invokeMethod(rootObject(), "insertReplaceText",
			Q_ARG(QVariant, txt));
	QApplication::postEvent(this, new QFocusEvent(QEvent::FocusIn), Qt::LowEventPriority);
}

/**
 * @brief QQmlPalmipede::insertReplaceTextBoard
 * @param txt
 */
void QQmlPalmipede::insertReplaceTextBoard(const QString &board, const QString &txt)
{
	QMetaObject::invokeMethod(rootObject(), "insertReplaceTextBoard",
			Q_ARG(QVariant, board),
			Q_ARG(QVariant, txt));
	QApplication::postEvent(this, new QFocusEvent(QEvent::FocusIn), Qt::LowEventPriority);
}


void QQmlPalmipede::focusInEvent(QFocusEvent * event)
{
	QQuickWidget::focusInEvent(event);
	QMetaObject::invokeMethod(rootObject(), "setDefaultFocus");
	//m_ui->palmiEditor->setFocus();
}
