#ifndef POS_H
#define POS_H

struct Pos {
    int fila;
    int columna;

    Pos(int f = 0, int c = 0) : fila(f), columna(c) {}

    bool operator==(const Pos& other) const {
        return fila == other.fila && columna == other.columna;
    }

    bool operator!=(const Pos& other) const {
        return !(*this == other);
    }
};

#endif