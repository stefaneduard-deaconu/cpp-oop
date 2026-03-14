Cerință:
Un furnizor de energie dorește să monitorizeze consumul zilnic al mai multor gospodării. Utilizând concepte de programare orientată pe obiecte, să se implementeze programul dorit de furnizor.

Se va defini clasa Gospodarie. Aceasta va avea următoarele date membre:

char*, char[] sau string nume: numele casei (max. 30 caractere)

unsigned int nZile: numărul de zile pentru care a fost urmărit consumul casei

double *consumZilnic: valoarea consumată (kW) în fiecare zi

double consumTotal: consumul total al gospodăriei în cele nZile (suma tuturor valorilor din consumZilnic)

Pentru clasa Gospodarie se vor implementa:

constructorul implicit

constructorul de inițializare

constructor de copiere (dacă este necesar)

operator de atribuire (dacă este necesar)

(opțional dar recomandat) operatorii de extragere și inserare din stream (operatorul>> și operatorul<<)

destructor (dacă este necesar)

Se va defini și clasa FurnizorEnergie, ce conține următoarele atribute:

char*, char[] sau string nume: numele furnizorului (max. 30 caractere)

double prag: pragul (kW) furnizorului peste care aplică un alt tarif pentru consumul de enrgie

double tarifRedus: tariful care se va aplica consumului de energie pâna la atingerea pragului

double tarifNormal: tariful care se aplică consumului de energie care este peste prag

unsigned int nclienti: numărul de clienți pe care îi gestionează furnizorul

Gospodarie *clienți: vector alocat dinamic care conține datele despre clienți

Pentru această clasă, FurnizorEnergie, se vor defini:

constructor implicit

constructor de inițializare

constructor de copiere (dacă este necesar)

operator de atribuire (dacă este necesar)

destructor (dacă este necesar)

funcția calculFactură: are scopul de a calcula factura pe baza consumului total. Declarație: double calculFactura(double consumTotal)

funcția de extragere a numărului de clienți: unsigned int getNCase()

(opțional dar recomandat) operatorii de extragere și inserare din stream (operatorul>> și operatorul<<)

operatorul de indexare: acesta va returna un obiect de tip Gospodarie (clientul corespunzător indexului trimis prin parametru) și va fi de forma Gospodarie& operator[](unsigned int index)

operator de apel de funcție: acesta are scopul de a calcula factura pentru clientul de pe poziția index, trimis ca parametru de intrare și de a returna rezultatul. Declarație: double operator()(unsigned int index)



Factura se va calcula utilizând următoarea ecuație:





Unde:

C = consumul total (corespunde consumTotal)

P = pragul (prag)

r = tarif redus (tarifRedus)

n = tarif normal (tarifNormal)

F(C) = valoarea facturii pentru consumul C



Pe lângă atributele și funcțiile obligatorii, la nevoie se pot defini și alte atribute/funcții/alți operatori.

În programul principal se va defini un obiect de tip FrunizorEnergie și se vor citi de la tastatură toate datele pentru FrunizorErnergie.

În continuare se citește o valoare de tip double: Val.

Se vor parcurge toți clienții obiectului de tip FrunizorEnergie și se vor afișa următoarele date pentru clienții care au valoarea facturii strict mai mare decât valoarea Val: nume client, consum total, valoare factură.

Dacă nu există niciun client cu valoarea facturii mai mare decât val, se afișează -1.

Toate valorile de tip double se vor afișa cu 2 zecimale utilizând setprecision din biblioteca iomanip (ex. cout << fixed << setprecision(2) << val;)

Date intrare:
Pe prima linie separate prin spațiu: nume furnizor, prag, tarifRedus, tarifNormal, nClienti

Pe următoarele nClienți linii separate prin spațiu: nume client, nZile, nzile valori de tip double

Pe următoarea linie: valoarea Val.



Date de ieșire:
Nume client, consum total și valoare factură pentru toți clienții care au valoarea facturii mai mare decât valoarea Val.



Exemplu:

Date de intrare:

enel 250 0.5 2.5 3

Casa_1 12 31.29 29.82 33.26 26.01 36.15 31.14 2.29 9.75 25.66 35.8 30.62 28.02

Casa_2 11 11.65 36.75 49.31 35.53 43.78 19.22 22.45 32.29 4.3 0.93 15.24

Casa_3 4 42.82 35.63 22.07 16.87

120

Date de ieșire:

Casa_1 319.81 299.52

Casa_2 271.45 178.62