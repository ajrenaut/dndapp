#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dice.h"
#include "data.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include <QDebug>

//TODO: Clean up includes

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");\
    QString dbPath = QDir::currentPath();
    qDebug() << dbPath;
    dbPath = dbPath + QString("/db.sqlite");
    db.setDatabaseName(dbPath);
    db.open();

    QSqlQuery query("CREATE TABLE adventurers ("
                    "advNum INTEGER PRIMARY KEY,"
                    "name TEXT NOT NULL,"
                    "level INTEGER,"
                    "perceptionMod INTEGER,"
                    "stealthMod INTEGER,"
                    "experience INTEGER)");

    query.exec("CREATE TABLE advancement ("
               "level INTEGER PRIMARY KEY,"
               "requiredXP INTEGER"
               "proficiency INTEGER)");



    // TODO: Make this dynamic.

    /*

    Data db;
    ui->adventurer1->setText(QString::fromStdString(db.getAdventurer(0).getName()));
    ui->curLevel1->setText(QString::number(db.getXPForLevel(db.getAdventurer(0).getLevel())));
    ui->nextLevel1->setText(QString::number(db.getXPForLevel(db.getAdventurer(0).getLevel()+1)));
    double xpPercent = static_cast<double>(db.getAdventurer(0).getExperience()
                       - db.getXPForLevel(db.getAdventurer(0).getLevel())) /
                       (db.getXPForLevel(db.getAdventurer(0).getLevel()+1)
                       - db.getXPForLevel(db.getAdventurer(0).getLevel()));
    int xpProgress = static_cast<int>(xpPercent * 100);
    ui->xpBar1->setValue(xpProgress);

    ui->adventurer2->setText(QString::fromStdString(db.getAdventurer(1).getName()));
    ui->curLevel2->setText(QString::number(db.getXPForLevel(db.getAdventurer(1).getLevel())));
    ui->nextLevel2->setText(QString::number(db.getXPForLevel(db.getAdventurer(1).getLevel()+1)));
    xpPercent = static_cast<double>(db.getAdventurer(1).getExperience()
                       - db.getXPForLevel(db.getAdventurer(1).getLevel())) /
                       (db.getXPForLevel(db.getAdventurer(1).getLevel()+1)
                       - db.getXPForLevel(db.getAdventurer(1).getLevel()));
    xpProgress = static_cast<int>(xpPercent * 100);
    ui->xpBar2->setValue(xpProgress);

    ui->adventurer3->setText(QString::fromStdString(db.getAdventurer(2).getName()));
    ui->curLevel3->setText(QString::number(db.getXPForLevel(db.getAdventurer(2).getLevel())));
    ui->nextLevel3->setText(QString::number(db.getXPForLevel(db.getAdventurer(2).getLevel()+1)));
    xpPercent = static_cast<double>(db.getAdventurer(2).getExperience()
                       - db.getXPForLevel(db.getAdventurer(2).getLevel())) /
                       (db.getXPForLevel(db.getAdventurer(2).getLevel()+1)
                       - db.getXPForLevel(db.getAdventurer(2).getLevel()));
    xpProgress = static_cast<int>(xpPercent * 100);
    ui->xpBar3->setValue(xpProgress);

    ui->adventurer4->setText(QString::fromStdString(db.getAdventurer(3).getName()));
    ui->curLevel4->setText(QString::number(db.getXPForLevel(db.getAdventurer(3).getLevel())));
    ui->nextLevel4->setText(QString::number(db.getXPForLevel(db.getAdventurer(3).getLevel()+1)));
    xpPercent = static_cast<double>(db.getAdventurer(3).getExperience()
                       - db.getXPForLevel(db.getAdventurer(3).getLevel())) /
                       (db.getXPForLevel(db.getAdventurer(3).getLevel()+1)
                       - db.getXPForLevel(db.getAdventurer(3).getLevel()));
    xpProgress = static_cast<int>(xpPercent * 100);
    ui->xpBar4->setValue(xpProgress);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

// TODO: Dice rolls need to update the log
// Use C++ iostream
void MainWindow::on_rollD4_clicked()
{
    if (ui->inputD4->text().isEmpty() || ui->inputD4Mod->text().isEmpty()) return;
    QString inputAmount = ui->inputD4->text();
    QString inputMod = ui->inputD4Mod->text();
    int amount = inputAmount.toInt();
    int modifier = inputMod.toInt();
    Dice d4roll(amount, 4);
    int *results = d4roll.getResults();
    int sum = modifier;
    for (int i = 0; i < amount; i++) sum += results[i];
    ui->resultD4->setText(QString::number(sum));
    QString logEntry1 = "Rolling " + QString::number(amount) + "d4+" + QString::number(modifier) + "...\n";
    QString logEntry2 = "";
    for (int i = 0; i < amount; i++) {
        logEntry2 += QString::number(results[i]);
        if ((i+1) == amount) break;
        else {
            logEntry2 += "+";
        }
    }
    logEntry2 += ", +" + QString::number(modifier) + " = " + QString::number(sum) + "\n";
    ui->rollHistoryLog->append(logEntry1);
    ui->rollHistoryLog->append(logEntry2);
}

void MainWindow::on_rollD6_clicked()
{
    QString inputAmount = ui->inputD6->text();
    QString inputMod = ui->inputD4Mod->text();
    int amount = inputAmount.toInt();
    int modifier = inputMod.toInt();
    Dice d6roll(amount, 6);
    int *results = d6roll.getResults();
    int sum = modifier;
    for (int i = 0; i < amount; i++) sum += results[i];
    ui->resultD6->setText(QString::number(sum));
    QString logEntry1 = "Rolling " + QString::number(amount) + "d6+" + QString::number(modifier) + "...\n";
    QString logEntry2 = "";
    for (int i = 0; i < amount; i++) {
        logEntry2 += QString::number(results[i]);
        if ((i+1) == amount) break;
        else {
            logEntry2 += "+";
        }
    }
    logEntry2 += ", +" + QString::number(modifier) + " = " + QString::number(sum) + "\n";
    ui->rollHistoryLog->append(logEntry1);
    ui->rollHistoryLog->append(logEntry2);
}

void MainWindow::on_rollD8_clicked()
{
    QString inputAmount = ui->inputD8->text();
    QString inputMod = ui->inputD4Mod->text();
    int amount = inputAmount.toInt();
    int modifier = inputMod.toInt();
    Dice d8roll(amount, 8);
    int *results = d8roll.getResults();
    int sum = modifier;
    for (int i = 0; i < amount; i++) sum += results[i];
    ui->resultD8->setText(QString::number(sum));
    QString logEntry1 = "Rolling " + QString::number(amount) + "d8+" + QString::number(modifier) + "...\n";
    QString logEntry2 = "";
    for (int i = 0; i < amount; i++) {
        logEntry2 += QString::number(results[i]);
        if ((i+1) == amount) break;
        else {
            logEntry2 += "+";
        }
    }
    logEntry2 += ", +" + QString::number(modifier) + " = " + QString::number(sum) + "\n";
    ui->rollHistoryLog->append(logEntry1);
    ui->rollHistoryLog->append(logEntry2);
}

void MainWindow::on_rollD10_clicked()
{
    QString inputAmount = ui->inputD10->text();
    QString inputMod = ui->inputD4Mod->text();
    int amount = inputAmount.toInt();
    int modifier = inputMod.toInt();
    Dice d10roll(amount, 10);
    int *results = d10roll.getResults();
    int sum = modifier;
    for (int i = 0; i < amount; i++) sum += results[i];
    ui->resultD10->setText(QString::number(sum));
    QString logEntry1 = "Rolling " + QString::number(amount) + "d10+" + QString::number(modifier) + "...\n";
    QString logEntry2 = "";
    for (int i = 0; i < amount; i++) {
        logEntry2 += QString::number(results[i]);
        if ((i+1) == amount) break;
        else {
            logEntry2 += "+";
        }
    }
    logEntry2 += ", +" + QString::number(modifier) + " = " + QString::number(sum) + "\n";
    ui->rollHistoryLog->append(logEntry1);
    ui->rollHistoryLog->append(logEntry2);
}

void MainWindow::on_rollD12_clicked()
{
    QString inputAmount = ui->inputD12->text();
    QString inputMod = ui->inputD4Mod->text();
    int amount = inputAmount.toInt();
    int modifier = inputMod.toInt();
    Dice d12roll(amount, 12);
    int *results = d12roll.getResults();
    int sum = modifier;
    for (int i = 0; i < amount; i++) sum += results[i];
    ui->resultD12->setText(QString::number(sum));
    QString logEntry1 = "Rolling " + QString::number(amount) + "d12+" + QString::number(modifier) + "...\n";
    QString logEntry2 = "";
    for (int i = 0; i < amount; i++) {
        logEntry2 += QString::number(results[i]);
        if ((i+1) == amount) break;
        else {
            logEntry2 += "+";
        }
    }
    logEntry2 += ", +" + QString::number(modifier) + " = " + QString::number(sum) + "\n";
    ui->rollHistoryLog->append(logEntry1);
    ui->rollHistoryLog->append(logEntry2);
}

void MainWindow::on_rollD20_clicked()
{
    QString inputAmount = ui->inputD20->text();
    QString inputMod = ui->inputD4Mod->text();
    int amount = inputAmount.toInt();
    int modifier = inputMod.toInt();
    Dice d20roll(amount, 20);
    int *results = d20roll.getResults();
    int sum = modifier;
    for (int i = 0; i < amount; i++) sum += results[i];
    ui->resultD20->setText(QString::number(sum));
    QString logEntry1 = "Rolling " + QString::number(amount) + "d20+" + QString::number(modifier) + "...\n";
    QString logEntry2 = "";
    for (int i = 0; i < amount; i++) {
        logEntry2 += QString::number(results[i]);
        if ((i+1) == amount) break;
        else {
            logEntry2 += "+";
        }
    }
    logEntry2 += ", +" + QString::number(modifier) + " = " + QString::number(sum) + "\n";
    ui->rollHistoryLog->append(logEntry1);
    ui->rollHistoryLog->append(logEntry2);
}

void MainWindow::on_rollD100_clicked()
{
    QString inputAmount = ui->inputD100->text();
    QString inputMod = ui->inputD4Mod->text();
    int amount = inputAmount.toInt();
    int modifier = inputMod.toInt();
    Dice d100roll(amount, 100);
    int *results = d100roll.getResults();
    int sum = modifier;
    for (int i = 0; i < amount; i++) sum += results[i];
    ui->resultD100->setText(QString::number(sum));
    QString logEntry1 = "Rolling " + QString::number(amount) + "d100+" + QString::number(modifier) + "...\n";
    QString logEntry2 = "";
    for (int i = 0; i < amount; i++) {
        logEntry2 += QString::number(results[i]);
        if ((i+1) == amount) break;
        else {
            logEntry2 += "+";
        }
    }
    logEntry2 += ", +" + QString::number(modifier) + " = " + QString::number(sum) + "\n";
    ui->rollHistoryLog->append(logEntry1);
    ui->rollHistoryLog->append(logEntry2);
}

void MainWindow::on_rollDX_clicked()
{
    QString inputAmount = ui->inputDX_amt->text();
    QString inputValue = ui->inputDX_val->text();
    QString inputMod = ui->inputD4Mod->text();
    int amount = inputAmount.toInt();
    int value = inputValue.toInt();
    int modifier = inputMod.toInt();
    Dice dXroll(amount, value);
    int *results = dXroll.getResults();
    int sum = modifier;
    for (int i = 0; i < amount; i++) sum += results[i];
    ui->resultDX->setText(QString::number(sum));
    QString logEntry1 = "Rolling " + QString::number(amount) + "d" + QString::number(value) + "+" + QString::number(modifier) + "...\n";
    QString logEntry2 = "";
    for (int i = 0; i < amount; i++) {
        logEntry2 += QString::number(results[i]);
        if ((i+1) == amount) break;
        else {
            logEntry2 += "+";
        }
    }
    logEntry2 += ", +" + QString::number(modifier) + " = " + QString::number(sum) + "\n";
    ui->rollHistoryLog->append(logEntry1);
    ui->rollHistoryLog->append(logEntry2);
}

void MainWindow::on_buttonRollStealth_clicked()
{
    //TODO: Make this dynamic
    Data db;
    int mods[4];
    for (int i = 0; i < 4; i++) {
        mods[i] = db.getAdventurer(i).getStealthMod();
    }
    if (ui->stealthProfCheck1->isChecked()) mods[0] += db.getAdventurer(0).getProficiencyMod();
    if (ui->stealthProfCheck2->isChecked()) mods[1] += db.getAdventurer(1).getProficiencyMod();
    if (ui->stealthProfCheck3->isChecked()) mods[2] += db.getAdventurer(2).getProficiencyMod();
    if (ui->stealthProfCheck4->isChecked()) mods[3] += db.getAdventurer(3).getProficiencyMod();

    int* results;
    Dice stealthRolls(4, 20);
    results = stealthRolls.getResults();
    for (int i = 0; i < 4; i++) {
        results[i] += mods[i];
    }
    ui->advRollResult1->setText(QString::number(results[0]));
    ui->advRollResult2->setText(QString::number(results[1]));
    ui->advRollResult3->setText(QString::number(results[2]));
    ui->advRollResult4->setText(QString::number(results[3]));
}

void MainWindow::on_buttonRollPerception_clicked()
{

}
