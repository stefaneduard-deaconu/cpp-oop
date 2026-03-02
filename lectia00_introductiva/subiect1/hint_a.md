# Hint A — Cumularea biletelor per persoană

**Cerință rezumat:** Din $N$ tranzacții (nume + nr. bilete), afișează persoanele cu total > 5 bilete.

---

## Pas 1: Clasa `Tranzactie`

Ai nevoie de o clasă cu atribute **private** și metode de acces (getteri).

```cpp
class Tranzactie {
private:
    string nume;
    int nrBilete;
public:
    Tranzactie() : nume(""), nrBilete(0) {}
    Tranzactie(string n, int b) : nume(n), nrBilete(b) {}

    string getNume() { return nume; }
    int getNrBilete() { return nrBilete; }
};
```

---

## Pas 2: Citirea tranzacțiilor

Citești `N`, apoi pentru fiecare tranzacție citești numele și numărul de bilete.

```cpp
int N;
cin >> N;

Tranzactie tranzactii[100]; // sau vector<Tranzactie>
for (int i = 0; i < N; i++) {
    string nume;
    int bilete;
    cin >> nume >> bilete;
    tranzactii[i] = Tranzactie(nume, bilete);
}
```

---

## Pas 3: Cumularea biletelor

Problema-cheie: aceeași persoană poate apărea de mai multe ori. Trebuie să **aduni** biletele per nume.

**Strategie simplă (fără `map`):** Folosește două tablouri paralele — unul de nume unice și unul de totaluri.

```cpp
string numeUnice[100];
int totalBilete[100];
int nrPersoane = 0;

for (int i = 0; i < N; i++) {
    string numeT = tranzactii[i].getNume();
    int bileteT = tranzactii[i].getNrBilete();

    // Caută dacă persoana există deja
    int gasit = -1;
    for (int j = 0; j < nrPersoane; j++) {
        if (numeUnice[j] == numeT) {
            gasit = j;
            break;
        }
    }

    if (gasit != -1) {
        totalBilete[gasit] += bileteT;  // adaugă la total existent
    } else {
        numeUnice[nrPersoane] = numeT;  // persoană nouă
        totalBilete[nrPersoane] = bileteT;
        nrPersoane++;
    }
}
```

> **Alternativă cu STL:** Poți folosi `map<string, int>` pentru a cumula automat.

---

## Pas 4: Afișarea rezultatului

Parcurgi array-ul de totaluri și afișezi doar persoanele cu > 5 bilete.

```cpp
for (int i = 0; i < nrPersoane; i++) {
    if (totalBilete[i] > 5) {
        cout << numeUnice[i] << " " << totalBilete[i] << endl;
    }
}
```

---

## Exemplu complet de rulare

**Input:**
```
a
6
Ana 3
Bob 2
Ana 4
Carol 6
Bob 1
Ana 1
```

**Output:**
```
Ana 8
Carol 6
```

Ana are 3+4+1=8 > 5, Carol are 6 > 5, Bob are 2+1=3 ≤ 5.
