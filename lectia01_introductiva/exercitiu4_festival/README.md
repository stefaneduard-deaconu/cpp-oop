# Exercițiul 4: Clasă Tranzactie și Filtrare

## Ce Trebuie Să Faci

Citești niste oameni și biletele lor.

Afișezi doar pe cei care au **mai mult de 5 bilete**.

De exemplu:
```
N = 4
Ion 3
Ana 7
Mihai 2
Elena 6
```

Output:
```
Ana a cumparat 7 bilete
Elena a cumparat 6 bilete
```

---

## Pași

### Pasul 1: Definiția și implementarea clasei
Scrii în `main.cpp`, **deasupra** funcției `main()`:

```cpp
class Tranzactie {
private:
    string nume;
    int nr_bilete;
public:
    Tranzactie(string n, int nr) {
        // TODO: salvează n și nr
    }

    string getNume() {
        // TODO: returnează nume
    }

    int getNrBilete() {
        // TODO: returnează nr_bilete
    }
};
```

---

### Pasul 2: Folosirea clasei în `main()`

```cpp
int main() {
    int N;
    // TODO: cin >> N;

    vector<Tranzactie> tranzactii;

    // TODO: for (int i = 0; i < N; i++) {
    //           string nume;
    //           int nr;
    //           cin >> nume >> nr;
    //           tranzactii.push_back(Tranzactie(nume, nr));
    //       }

    // TODO: for (Tranzactie t : tranzactii) {
    //           if (t.getNrBilete() > 5) {
    //               cout << t.getNume() << " a cumparat "
    //                    << t.getNrBilete() << " bilete" << endl;
    //           }
    //       }

    return 0;
}
```

---

### Pasul 3: Compilare
```
g++ -o test main.cpp
./test
```

Input exemplu:
```
4
Ion 3
Ana 7
Mihai 2
Elena 6
```

Output așteptat:
```
Ana a cumparat 7 bilete
Elena a cumparat 6 bilete
```

---

## 💡 Ghidare

- Constructor: `nume = n; nr_bilete = nr;`
- `cin >> N` = citire de la tastatură
- `if (nr_bilete > 5)` = filtrare
- `push_back()` = adaugă în vector
- `for (Tranzactie t : tranzactii)` = repetă pentru fiecare

---

## ✅ Checklist

- [ ] Am scris clasa Tranzactie în main.cpp
- [ ] Constructor salvează parametrii
- [ ] getNume() returnează nume
- [ ] getNrBilete() returnează nr_bilete
- [ ] main() citește N
- [ ] main() are loop de N ori
- [ ] main() adaugă în vector
- [ ] main() filtrează cu if > 5
- [ ] Compilează: `g++ -o test main.cpp`
- [ ] Afișează doar Ana și Elena

Succes! 🚀
