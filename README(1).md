# TOT CE TREBUIE SA STII DESPRE PROGRAMAREA DINAMICA
https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03 -link lab
## ce e mai exact?

Ideea de bază este simplă: trebuie sa calculezi cea mai buna chestie pentru primele i
elemente stiind care este deja cea mai buna chestie pt i-1 elemente. si tu trebuie sa
decizi daca e okay sa adaugi si elementul v[i] sau nu.

FOLOSESTI:
- N mare, complexitate mica
- ai multe chestii

### SSM

-> subsecvente de lungime maxima - nr consecutive
-> daca dp[i - 1] < 0, creezi subsecv noua
-> dp[i-1] > 0, adaugi si v[i]

### SCMAX

-> subsir de lungime maxima - nr random din vector, dar ordonate - subșir ordonat strict crescător si indicii in ordine

-> pt dp[i] te uiti la toatee numerele din vector de dinainte care sunt mai mici decat v[i](v[j] < v[i])
si vezi care dintre ele are dp[j] maxim

-> dp[1] = 1 si dp[i] = 1 + max(dp[j]), v[j] < v[i], max returneaza 0 daca nu exista v[j] < v[i]


### ZARURI

-> cand dam cu zarul numarul i ne gandim cum am putea completa sumele de la zarul i - 1
-> pt nr de moduri in care putem obtine o suma j, adunam nr de moduri in care putem obtine primele f sume
mai mici decat j - adica de la j - f la j - 1

### MONEDE

-> vrei sa vezi cat de putine monede poti sa folosesti ca sa poti obtine o suma data
-> la inceput initializezi toate sumele in afara de prima cu INFINIT, prima e 0
-> vrei sa faci toate sumele de la 1 la suma data, folosind cat mai putine monede
-> pt fiecare i(o suma gen 1, 2, 3,...), trebuie sa calculezi dp[i] pe care il poti obtine folosind
fiecare moneda
-> trebuie sa verifici inainte daca moneda ta e mai mica decat suma pe care vrei sa o obtii
-> si daca suma de care vrei sa te ajuti dp[i - v[j]] exista adica nu e INFINITA
adica daca ai 3 monede 1 2 4 o sa ai 3 dp[i], pt ca o sa aduni la sumele anterioare 1, 2 sau 4
-> o sa obtii astfel 3 valori pentru dp[i] si tu o vrei pe cea mai mica

### CLSC

-> dp cu matrice
-> n linii, m coloane, unde n si m sunt lungimile sirurilor
-> dp[i][j] reprezinta lungimea maxima folosind primele i nr din primul sir si primele j din al doilea
-> compari pe rand fiecare nr din primul sir cu fiecare nr din al doilea adica 2 for uri
-> daca a[i] = b[j] - ne uitam pe diagonala adica dp[i-1][j-1] care reprezinta lung. max. obtinuta cu toate numerele de dinainte
-> altfel, Dacă caracterele nu sunt egale, atunci lungimea CMLSC este cea mai mare dintre:
Subsecvența comună care nu include caracterul v[i] (dp[i - 1][j]).
Subsecvența comună care nu include caracterul w[j] (dp[i][j - 1]).
