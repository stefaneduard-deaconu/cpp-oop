# Exercițiul 4: Ecosistem (Simulare K pași)

## Ce Trebuie Să Faci

Simulezi **K momente de timp**. La fiecare pas, fiecare animal mănâncă din resursa sa (iarbă sau carne). Dacă resursa s-a terminat, animalul moare. Afișezi:

**a)** Cine mănâncă cel mai mult la primul pas?
**b)** Câte animale sunt vii după K pași?

Formulele sunt identice cu colocviul Animale — dar fără deplasare și fără omor.

---

## Formule de consum

| Tip | Consum mâncare | Minim |
|-----|---------------|-------|
| **Erbivor** | `greutate * CT_iarba / 5000.0` | 5, sau cât a mai rămas dacă e sub 5 |
| **Carnivor** | `exp(greutate / 50.0) * CT_carne / 370.0` | 10, sau cât a mai rămas dacă e sub 10 |

La fiecare pas:
1. Calculezi cât mănâncă
2. Dacă resursa e 0, animalul **moare** (nu mai participă)
3. Scazi cantitatea din resursă (`CT_iarba` sau `CT_carne`)

---

## Pași

### Pasul 1: Clasa de bază Animal

```cpp
class Animal {
protected:
    string id;
    double greutate;
    bool viu;
public:
    Animal(string id, double g) {
        // TODO: salvează id, g; viu = true
    }

    virtual double mananca(double& resursa) = 0;

    bool esteViu() { return viu; }
    string getId() { return id; }
};
```

**Ce e nou:** `double&` — parametru prin referință. Când modifici `resursa` în metodă, se modifică și variabila originală (`CT_iarba` sau `CT_carne`).

---

### Pasul 2: Clasa Erbivor

```cpp
class Erbivor : public Animal {
public:
    Erbivor(string id, double g) : Animal(id, g) {}

    double mananca(double& resursa) override {
        // TODO:
        // if (resursa <= 0) { viu = false; return 0; }
        // double mancare = greutate * resursa / 5000.0;
        // if (mancare < 5) mancare = 5;
        // if (mancare > resursa) mancare = resursa;
        // resursa -= mancare;
        // return mancare;
    }
};
```

**Logica:** calculezi, aplici minimul 5, dar nu poți mânca mai mult decât ce a rămas.

---

### Pasul 3: Clasa Carnivor

```cpp
class Carnivor : public Animal {
public:
    Carnivor(string id, double g) : Animal(id, g) {}

    double mananca(double& resursa) override {
        // TODO:
        // if (resursa <= 0) { viu = false; return 0; }
        // double mancare = exp(greutate / 50.0) * resursa / 370.0;
        // if (mancare < 10) mancare = 10;
        // if (mancare > resursa) mancare = resursa;
        // resursa -= mancare;
        // return mancare;
    }
};
```

---

### Pasul 4: Citirea datelor

```cpp
int n;
cin >> n;

vector<Animal*> animale;
for (int i = 0; i < n; i++) {
    string tip, id;
    double greutate;
    cin >> tip >> id >> greutate;

    if (tip == "ERBIVOR") {
        animale.push_back(new Erbivor(id, greutate));
    } else {
        animale.push_back(new Carnivor(id, greutate));
    }
}

double ct_iarba, ct_carne;
cin >> ct_iarba >> ct_carne;

int k;
cin >> k;
```

---

### Pasul 5: Simularea K pași

```cpp
string idMaxPas1 = "";
double maxMancarePas1 = 0;

for (int pas = 0; pas < k; pas++) {
    for (int i = 0; i < animale.size(); i++) {
        if (!animale[i]->esteViu()) continue;

        // TODO: Determină resursa corectă
        // Erbivor → ct_iarba, Carnivor → ct_carne
        // Foloseste metoda mananca() — polimorfismul se ocupă de formulă

        // La primul pas (pas == 0), reține cine mănâncă cel mai mult
    }
}
```

**Problemă:** Cum știi dacă e erbivor sau carnivor pentru a trimite resursa corectă?

**Soluție:** Adaugă o metodă virtuală `bool esteErbivor()` care returnează `true` în Erbivor și `false` în Carnivor. Sau mai elegant: adaugă un `double& getResursa(double& iarba, double& carne)` virtual.

---

### Pasul 6: Afișare

```cpp
cout << "a) " << idMaxPas1 << endl;

int vii = 0;
for (int i = 0; i < animale.size(); i++) {
    if (animale[i]->esteViu()) vii++;
}
cout << "b) " << vii << endl;
```

---

### Pasul 7: Compilare și testare
```
g++ -o main main.cpp -lm
./main
```

**Input** (adaptat din colocviu, fără energie și locație):
```
5
CARNIVOR LEU 50
ERBIVOR CERB 70
CARNIVOR LEOPARD 40
ERBIVOR MAIMUTA 40
ERBIVOR ELEFANT 120
1000 1000
10
```

**Output așteptat:**
```
a) ELEFANT
b) 3
```

**Verificare la pasul 1:**
- LEU: exp(50/50)*1000/370 = 2.718*2.703 = 7.35 → min 10 → mănâncă **10**
- CERB: 70*1000/5000 = 14 → mănâncă **14**
- LEOPARD: exp(40/50)*990/370 = 2.226*2.676 = 5.95 → min 10 → mănâncă **10**
- MAIMUTA: 40*986/5000 = 7.89 → mănâncă **7.89**
- ELEFANT: 120*978.11/5000 = **23.47** ← cel mai mult

→ Cerința a): **ELEFANT**

---

## 💡 Gândește-te

La colocviu, animalele au și energie, deplasare și omor. Dar formula de mâncare e **identică**!

---

## ✅ Checklist

- [ ] Clasa Animal cu virtual mananca(double&) = 0
- [ ] Erbivor: formula cu min 5, nu depășește resursa
- [ ] Carnivor: formula cu exp(), min 10, nu depășește resursa
- [ ] double& modifică resursa originală
- [ ] Buclă K pași, animale moarte sunt sărite
- [ ] Cerința a: ID-ul celui care mănâncă cel mai mult la pasul 1
- [ ] Cerința b: Câte animale vii după K pași
- [ ] Compilează și afișează ELEFANT / 3
