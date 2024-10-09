#ifndef CARDINFO_H
#define CARDINFO_H

#include <QString>

class CardInfo {
public:
    CardInfo();
    CardInfo(int id, const QString& name, int attack, int defense);

    int getId() const;
    QString getName() const;
    int getAttack() const;
    int getDefense() const;

    // カードをデータベースに保存
    bool saveToDatabase();

    // カードをデータベースから読み込む
    static CardInfo loadFromDatabase(int id);

    //

private:
    int id;
    QString name;
    int attack;
    int defense;
};

#endif // CARDINFO_H
