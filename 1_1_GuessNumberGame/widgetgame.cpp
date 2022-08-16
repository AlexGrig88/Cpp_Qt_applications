#include "widgetgame.h"
#include "ui_widgetgame.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>
#include <QMessageBox>

WidgetGame::WidgetGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetGame)
{
    ui->setupUi(this);
    setInitialStateOfGame();

}

WidgetGame::~WidgetGame()
{
    delete ui;
}

const QVector<QString> WidgetGame::m_phrases_for_lesser {
    "Твое число меньше загаданного",
    "Маловато будет)))",
    "Не, ну у меня точно больше",
    "Бери больше!",
    "малыми цифрами оперируешь(",
    "эх, поболя надобно",
    "это мало и не правда!",
};
const QVector<QString> WidgetGame::m_phrases_for_greater {
    "Твое число больше загаданного",
    "Многовато будет)))",
    "Не, ну у меня точно меньше",
    "Снижай обороты!",
    "большими йифрами оперируешь)",
    "эх, надобно малость поменьше",
    "это много и не правда!",
};


void WidgetGame::on_guessBtn_clicked()
{
    ++m_attemptCounter;
    m_guessNumber = ui->spinBox->value();
    if (m_guessNumber == m_secretNumber) {
        QString text = "Поздравляю, вы отгадали число с " + QString::number(m_attemptCounter) +" попытки.";
        ui->guessBtn->setEnabled(false);
        ui->startOverBtn->setEnabled(true);
        QMessageBox::information(this, "Congratulations!", text, QMessageBox::Ok);
    }
    else if (m_guessNumber > m_secretNumber) {
        srand(time(NULL));
        int randIndex = rand() % WidgetGame::m_phrases_for_greater.size();

        ui->infoLabel->setText(WidgetGame::m_phrases_for_greater[randIndex]);
    }
    else {
        srand(time(NULL));
        int randIndex = rand() % WidgetGame::m_phrases_for_lesser.size();
        ui->infoLabel->setText(WidgetGame::m_phrases_for_lesser[randIndex]);
    }
}

void WidgetGame::on_startOverBtn_clicked()
{
    setInitialStateOfGame();
}

void WidgetGame::setInitialStateOfGame()
{
    m_attemptCounter = 0;
    srand(time(NULL));
    m_secretNumber = rand() % 20 + 1;

    ui->startOverBtn->setDisabled(true);
    ui->guessBtn->setDisabled(false);
    ui->infoLabel->setText("Ожидаю...");
    ui->spinBox->setValue(1);
    //qDebug() << "Secret number: " + QString::number(m_secretNumber) << endl;
}
