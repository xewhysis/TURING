#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include <QMap>
#include <QString>

struct Rule {
    QChar write;
    int move;
    QString nextState;
};

class TuringMachine {
public:
    void reset();
    void setTape(const QString &input);
    void setRule(const QString &state, QChar symbol, const Rule &rule);
    void setBlank(QChar b);

    bool step();

    QString getState() const;
    int getHead() const;
    QChar getSymbol(int pos) const;

private:
    QMap<int,QChar> tape;
    QMap<QString, QMap<QChar, Rule>> rules;

    int head = 0;
    QString currentState = "q0";
    QChar blank = '_';
};

#endif
