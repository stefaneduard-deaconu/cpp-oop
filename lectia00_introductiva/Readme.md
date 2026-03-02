# Lecția 00 - Introductivă

Patru subiecte de examen formulate concis, fără comentarii pedagogice.

---

## Subiectul 1: Organizarea unui Festival

**Descriere:**
O companie are nevoie de un program pentru organizarea unui festival de muzică. Programul trebuie să proceseze diverse comenzi în funcție de un caracter citit inițial (`a`, `b` sau `c`), urmat de datele specifice.

**Cerințe:**
Prin crearea unor clase specifice (ex: `Tranzactie`, `Formatie`) cu atribute private și metode de acces, rezolvați următoarele:

- **a)** Dintr-o listă de $N$ tranzacții (Nume persoană, Număr bilete achiziționate), găsiți persoanele care au cumpărat cumulat mai mult de 5 bilete (este posibil să se cumpere bilete de către aceeași persoană în mai multe tranzacții).
- **b)** Dându-se $M$ zile de festival și o listă de formații cu nivelul lor de popularitate (de la 1 — cele mai populare, la 3 — cele mai puțin populare), formați seturi de câte 3 trupe din fiecare nivel de popularitate pentru fiecare zi de concert.
- **c)** Dintr-o listă de $T$ formații, afișați numele acestora în ordine alfabetică pentru a le pune pe un poster.

> 💡 **Ai nevoie de ajutor?** [Ghid pas cu pas pentru Subiectul 1](subiect1/Readme.md)

---

## Subiectul 2: Gestiunea Containerelor

**Descriere:**
O firmă transportă containere având trei forme geometrice posibile: Cub, Sferă și Cilindru. Fiecare formă are propriile reguli de calcul pentru volum și suprafață.

- **Cub:** Volum = $L^3$, Suprafață = $6L^2$
- **Sferă:** Volum = $\frac{4 \pi R^3}{3}$, Suprafață = $4 \pi R^2$
- **Cilindru:** Volum = $\pi R^2 H$, Suprafață = $2 \pi R (R + H)$

**Cerințe:**

- Implementați trei clase independente (`Cub`, `Sfera`, `Cilindru`).
- Fiecare clasă trebuie să aibă atributele specifice private (Latură $L$, Rază $R$, Înălțime $H$) și constructori pentru inițializare.
- Implementați în fiecare clasă metodele publice `calculeazaVolum()` și `calculeazaSuprafata()`.
- Citind informații despre $N$ containere, calculați și afișați suma totală a volumelor și suma totală a suprafețelor pentru toate containerele procesate.

---

## Subiectul 3: Calculul Tarifelor pentru Transport

**Descriere:**
O firmă de transport oferă mai multe servicii, printre care Autobuz cu Bilet, Taxi și Camion de marfă. Prețul fiecărui serviciu se calculează diferit, astfel:

- **AutobuzBilet:** preț bilet
- **Taxi:** tarif pornire + timp staționare × tarif staționare + distanța parcursă × tarif distanță
  - unde tarif staționare = $10 \times \left(1 + \left(\frac{\text{timp staționare}}{100}\right)^2\right)$
  - și tarif distanță = $10 \times e^{-\text{distanța parcursă}}$
- **Camion:** greutate marfă × distanță parcursă / 500

**Cerințe:**

- Implementați câte o clasă independentă pentru fiecare serviciu (`AutobuzBilet`, `Taxi`, `Camion`).
- Încapsulați atributele necesare fiecărui serviciu ca date private (de tip `double`).
- Implementați o metodă publică `calculeazaPret()` în fiecare clasă respectând formulele date.
- Pornind de la o listă de $N$ servicii efectuate, calculați și afișați suma totală încasată de firmă.

---

## Subiectul 4: Simulare Ecosistem (Consumul de resurse)

**Descriere:**
Într-un ecosistem există o cantitate inițială de iarbă (`CT_iarba`) și carne (`CT_carne`). Există două tipuri de animale: Erbivor și Carnivor. Fiecare animal consumă hrană în funcție de greutatea sa, astfel:

- **Erbivor:** consumă o cantitate de mâncare = $\frac{\text{greutate} \times \text{CT\_iarba}}{5000}$, dar nu mai puțin de 5, cu excepția cazului când cantitatea totală de iarbă rămasă este mai mică de 5 (caz în care consumă tot ce a rămas).
- **Carnivor:** consumă o cantitate de mâncare = $\frac{e^{\text{greutate}/50} \times \text{CT\_carne}}{370}$, dar nu mai puțin de 10, cu excepția cazului când cantitatea totală de carne rămasă este mai mică de 10 (caz în care consumă tot ce a rămas).

**Cerințe:**

- Creați clasele `Erbivor` și `Carnivor` având ca atribute private: ID (`string`) și greutate (`double`).
- Implementați în fiecare clasă o metodă `consumaMancare(double& cantitate_disponibila)` care calculează cât mănâncă animalul respectiv, scade cantitatea consumată din resursa totală transmisă ca parametru și returnează valoarea consumată.
- Se dau cantitățile inițiale de iarbă și carne, urmate de $N$ animale. Determinați și afișați ID-ul animalului care a consumat cea mai mare cantitate de hrană la prima masă.
