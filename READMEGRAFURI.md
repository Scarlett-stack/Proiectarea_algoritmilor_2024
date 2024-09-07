NU UITA!!!! GRAF NEORIENTAT -> ADAUGA SI DE LA V LA U MUCHIE

Folosești DFS (Depth-First Search) în problemele în care este necesară explorarea profundă a grafului sau a structurii de date similară. De exemplu, DFS este folosit în următoarele situații:

1. **Parcurgerea grafurilor**: DFS este frecvent folosit pentru a parcurge toate nodurile unui graf sau pentru a găsi un anumit nod sau un anumit tip de căutare în graf, cum ar fi găsirea unui ciclu sau a unui drum între două noduri.

2. **Determinarea conectivității grafurilor**: DFS poate fi folosit pentru a determina dacă un graf este conex sau nu.

3. **Verificarea existenței unui ciclu în graf**: DFS poate fi folosit pentru a verifica dacă un graf conține un ciclu sau nu.

BFS (Breadth-First Search) este folosit în problemele în care este necesară explorarea pe nivele a grafului sau a structurii de date similară. Iată câteva exemple:

1. **Găsirea celor mai scurte căi**: BFS este utilizat pentru a găsi cea mai scurtă cale între două noduri într-un graf neponderat sau într-o structură similară, deoarece acesta explorează nodurile în ordinea nivelului lor.

2. **Determinarea distanței minime**: BFS poate fi folosit pentru a calcula distanțele minime de la un nod sursă la toate celelalte noduri din graf.

3. **Determinarea componentelor conexe**: BFS poate fi folosit pentru a determina componentele conexe ale unui graf neorientat.

Sortarea topologică este folosită în problemele în care este necesară ordonarea nodurilor unui graf orientat astfel încât toate muchiile să fie direcționate de la nodurile cu indice mai mic către cele cu indice mai mare. Iată câteva exemple:

1. **Ordinarea sarcinilor**: Sortarea topologică poate fi folosită pentru a ordona sarcinile într-un proiect astfel încât o sarcină să nu înceapă înainte ca toate sarcinile de care depinde să fie finalizate.

2. **Detectarea ciclurilor**: Sortarea topologică poate fi folosită pentru a detecta dacă un graf orientat conține un ciclu.

3. **Ordinarea depedentelor**: În compilarea programelor, sortarea topologică este folosită pentru a determina ordinea în care fișierele sursă trebuie compilate astfel încât fiecare fișier să fie compilat înainte de a fi utilizat în alte fișiere.



### TARJAN
- gasesti componente tare conexe


### DIJKSTRA
- cand toate costurile din graf sunt pozitive

### BELLMAN-FORD
- permite costuri negative in graf, dar presupune ca nu exista cicluri negative
- iti detecteaza ciclul negativ

->Astea 2 de dinainte sunt pentru drumul minim de la un nod la toate celelalte


### ROY-FLOYD/FLOYD-WARSHALL
- eficient pt grafuri dense
- Acesta funcționează chiar și cu ponderi negative, cu condiția să nu existe cicluri de cost negativ.

### JOHNSON
- eficient pt grafuri rare

->Astea fac drumul cel mai scurt de la toate la toate
