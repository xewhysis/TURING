#include "turingmachine.h"

void TuringMachine::reset() {
    tape.clear();
    rules.clear();
    head = 0;
    currentState = "q0";
}

void TuringMachine::setBlank(QChar b) {
    blank = b;
}

void TuringMachine::setTape(const QString &input) {
    tape.clear();
    for (int i = 0; i < input.size(); i++)
        tape[i] = input[i];
}

void TuringMachine::setRule(const QString &state,
                            QChar symbol, const Rule &rule) {
    rules[state][symbol] = rule;
}

bool TuringMachine::step() {
    QChar current = tape.contains(head) ? tape[head] : blank;

    if (!rules.contains(currentState) ||
        !rules[currentState].contains(current))
        return false;

    Rule r = rules[currentState][current];

    tape[head] = r.write;
    head += r.move;
    currentState = r.nextState;

    return true;
}

QString TuringMachine::getState() const {
    return currentState;
}

int TuringMachine::getHead() const {
    return head;
}

QChar TuringMachine::getSymbol(int pos) const {
    return tape.contains(pos) ? tape[pos] : blank;
}
