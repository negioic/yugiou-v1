#include "CardInfo.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

CardInfo::CardInfo() : id(0), attack(0), defense(0) {}

CardInfo::CardInfo(int id, const QString& name, int attack, int defense)
    : id(id), name(name), attack(attack), defense(defense) {}

int CardInfo::getId() const { return id; }
QString CardInfo::getName() const { return name; }
int CardInfo::getAttack() const { return attack; }
int CardInfo::getDefense() const { return defense; }

bool CardInfo::saveToDatabase() {
    QSqlQuery query;

    qDebug() << "saveToDatabase execute...";

    query.prepare("INSERT INTO cards (id, name, attack, defense) "
                  "VALUES (:id, :name, :attack, :defense)");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":attack", attack);
    query.bindValue(":defense", defense);

    if (!query.exec()) {
        qDebug() << "Failed to insert card:" << query.lastError();
        return false;
    }
    return true;
}

CardInfo CardInfo::loadFromDatabase(int id) {
    qDebug() << "loadFromDatabase execute...";

    QSqlQuery query;
    query.prepare("SELECT id, name, attack, defense FROM cards WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return CardInfo(query.value(0).toInt(),
                        query.value(1).toString(),
                        query.value(2).toInt(),
                        query.value(3).toInt());
    } else {
        qDebug() << "Failed to load card:" << query.lastError();
        return CardInfo();
    }
}


