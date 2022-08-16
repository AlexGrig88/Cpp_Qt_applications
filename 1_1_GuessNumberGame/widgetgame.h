#ifndef WIDGETGAME_H
#define WIDGETGAME_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetGame; }
QT_END_NAMESPACE

class WidgetGame : public QWidget
{
    Q_OBJECT

public:
    WidgetGame(QWidget *parent = nullptr);
    ~WidgetGame();
    void setInitialStateOfGame(); // установка начального состояния игры и генерация нового секретного числа

private slots:
    void on_guessBtn_clicked();

    void on_startOverBtn_clicked();

private:
    static const QVector<QString> m_phrases_for_lesser ;
    static const QVector<QString> m_phrases_for_greater ;
    Ui::WidgetGame *ui;
    int m_guessNumber;
    int m_secretNumber;
    int m_attemptCounter; // счетчик попыток
};

#endif // WIDGETGAME_H
