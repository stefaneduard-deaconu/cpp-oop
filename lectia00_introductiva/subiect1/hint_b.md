# Hint B — Formarea seturilor de formații pe zile

**Cerință rezumat:** Dându-se $M$ zile și o listă de formații cu nivel de popularitate (1, 2 sau 3), formează seturi de câte 3 trupe din fiecare nivel pentru fiecare zi.

---

## Pas 1: Clasa `Formatie`

```cpp
class Formatie {
private:
    string nume;
    int popularitate; // 1, 2 sau 3
public:
    Formatie() : nume(""), popularitate(0) {}
    Formatie(string n, int p) : nume(n), popularitate(p) {}

    string getNume() { return nume; }
    int getPopularitate() { return popularitate; }
};
```

---

## Pas 2: Citirea datelor

Citești numărul de zile `M`, apoi numărul total de formații și datele lor.

```cpp
int M;
cin >> M;

int nrFormatii;
cin >> nrFormatii;

Formatie formatii[100];
for (int i = 0; i < nrFormatii; i++) {
    string nume;
    int pop;
    cin >> nume >> pop;
    formatii[i] = Formatie(nume, pop);
}
```

---

## Pas 3: Separă formațiile pe niveluri de popularitate

Grupează formațiile în 3 liste separate (una per nivel).

```cpp
string nivel1[100], nivel2[100], nivel3[100];
int cnt1 = 0, cnt2 = 0, cnt3 = 0;

for (int i = 0; i < nrFormatii; i++) {
    if (formatii[i].getPopularitate() == 1) {
        nivel1[cnt1++] = formatii[i].getNume();
    } else if (formatii[i].getPopularitate() == 2) {
        nivel2[cnt2++] = formatii[i].getNume();
    } else {
        nivel3[cnt3++] = formatii[i].getNume();
    }
}
```

---

## Pas 4: Formează seturile pentru fiecare zi

Pentru fiecare din cele $M$ zile, extrage câte 3 formații din fiecare nivel.

```cpp
int idx1 = 0, idx2 = 0, idx3 = 0;

for (int zi = 1; zi <= M; zi++) {
    cout << "Ziua " << zi << ":" << endl;

    cout << "  Nivel 1: ";
    for (int j = 0; j < 3 && idx1 < cnt1; j++, idx1++)
        cout << nivel1[idx1] << " ";
    cout << endl;

    cout << "  Nivel 2: ";
    for (int j = 0; j < 3 && idx2 < cnt2; j++, idx2++)
        cout << nivel2[idx2] << " ";
    cout << endl;

    cout << "  Nivel 3: ";
    for (int j = 0; j < 3 && idx3 < cnt3; j++, idx3++)
        cout << nivel3[idx3] << " ";
    cout << endl;
}
```

> **Gândește-te:** Ce se întâmplă dacă nu ai destule formații pentru toate zilele? Codul de mai sus se oprește natural din extragere când lista se termină.

---

## Exemplu complet de rulare

**Input:**
```
b
2
10
Alpha 1
Beta 2
Gamma 3
Delta 1
Echo 2
Foxtrot 3
Golf 1
Hotel 2
India 3
Juliet 1
```

**Output:**
```
Ziua 1:
  Nivel 1: Alpha Delta Golf
  Nivel 2: Beta Echo Hotel
  Nivel 3: Gamma Foxtrot India
Ziua 2:
  Nivel 1: Juliet
  Nivel 2:
  Nivel 3:
```

Ziua 2 are doar 1 formație de nivel 1 rămasă și niciuna de nivel 2/3.
