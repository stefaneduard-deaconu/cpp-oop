# Lecția 03 — Moștenire și Polimorfism

Patru exerciții care te pregătesc pas cu pas pentru colocvii. Fiecare introduce un concept nou.

---

### Exercițiul 1: Containere (Moștenire simplă)
**Ce faci:** Refactorizezi Cub, Sfera, Cilindru dintr-o clasă de bază `Container` cu `virtual`.

**Cum:** Completezi `main.cpp` din folderul `exercitiu1_containere`

**De ce:** Să înveți sintaxa `class Derivata : public Baza` și `virtual` / `override`.

---

### Exercițiul 2: Transport (Polimorfism cu pointeri)
**Ce faci:** Creezi `Transport` cu metode pur virtuale (`= 0`) și derivate AutobuzBilet, Taxi, Camion. Stochezi totul într-un `vector<Transport*>`.

**Cum:** Completezi `main.cpp` din folderul `exercitiu2_transport`

**De ce:** Să înveți `vector<Base*>`, `new`, `->` și de ce `if` pe tip e doar la citire.

---

### Exercițiul 3: Alergători (Simulare un pas)
**Ce faci:** Simulezi un singur moment de timp pentru sprinteri și maratoniști. Cine parcurge cea mai mare distanță?

**Cum:** Completezi `main.cpp` din folderul `exercitiu3_alergatori`

**De ce:** Formulele sunt identice cu colocviul, dar fără regenerare sau retragere.

---

### Exercițiul 4: Ecosistem (Simulare K pași)
**Ce faci:** Simulezi K momente de timp: animalele mănâncă, resursele scad, unele mor. Câte rămân vii?

**Cum:** Completezi `main.cpp` din folderul `exercitiu4_ecosistem`

**De ce:** Formulele sunt identice cu colocviul Animale, dar fără deplasare sau omor.

---

## Cum Se Lucrează

### Pasul 1: Mergi în folderul exercițiului
```
cd exercitiu1_containere
```

### Pasul 2: Deschide README.md și citește pașii

### Pasul 3: Completează TODO-urile din main.cpp

### Pasul 4: Compilează și testează
```
g++ -o main main.cpp -lm
./main
```

### Pasul 5: Treci la exercițiul următor

---

## Progresie

| Exercițiu | Concept nou | Legătura cu colocviul |
|-----------|------------|----------------------|
| 1 — Containere | `virtual`, `override`, moștenire | Structura claselor |
| 2 — Transport | `= 0` (pur virtual), `vector<Base*>`, `new`, `->` | Colocviu Transport (cerințele A + B) |
| 3 — Alergători | Formule `exp`, simulare 1 pas | Colocviu Alergători (cerința a) |
| 4 — Ecosistem | `double&` referință, buclă K pași, moarte | Colocviu Animale (cerințele a + b) |
