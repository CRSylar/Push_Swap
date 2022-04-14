# Push_Swap 42 Rome

[![cromalde's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl1z1axw3001109mox1m22pjp/project/2127721)](https://github.com/JaeSeoKim/badge42)


Project based on the learning of sorting algorithms and on the notion of complexity.

the goal is to write an algorithm to sort a stack (A) using only a few operations and another initially empty stack (B).

during the defense the algorithm was evaluated based on the number of operations carried out to obtain the ordering on stacks of different sizes (3, 5, 100, 500).

my approach was as follows:

I initially wrote a first algorithm based on a simple insertion sort that searches stack A for the minimum value and pushes it to B, until there are 3 numbers left in A (which can be ordered with a maximum of 2 moves) after which I push back all the data of B in A .
This approach obviously proves very slow for large stacks (100 or more elements). but very powerful for small stacks.
So I studied another algorithm to use for large Stacks using a mix of insertion sort starting from the maximum ascending ordered sequence.



As a bonus I used miniLib X to have a simple visual GUI of the operations performed.


Usage.
make bonus will produce 3 executables:
push_swap, checker and b_checker.

to use the GUI simply pipe push_swap | b_checker (given the same argument).
-------------------------------------------------------------------------------------------------

Progetto basato sull'apprendimento di algoritmi di ordinamento e sulla nozione di complessità.

l'obiettivo è quello di scrivere un algoritmo per ordinare uno stack (A) usando solo alcune operazioni e un'altro stack (B) inizialmente vuoto.

durante la difesa è stato valutato l'algoritmo in base al numero di operazioni svolte per ottenere l'ordinamento su stack di diversa grandezza (3, 5, 100, 500).

il mio approccio è stato il seguente :

ho inizialmente scritto un primo algoritmo basato su un semplice insertion sort che cerca nello stack A il valore minimo e lo spinge in B, finche in A non restano 3 numeri (ordinabili con massimo 2 mosse) dopodiche spingo indietro tutti i dati di B in A.
Questo approccio ovviamente si rivela molto lento  per stack grandi (100 o piu elementi). ma molto performante per stack piccoli.
Quindi ho studiato un altro algoritmo da usare per i grandi Stacks utilizzando un mix di insertion sort partendo dalla massima sequenza ordinata crescente.



Come bonus ho usato miniLib X per avere una semplice GUI visuale delle operazioni svolte.


Utilizzo.
make bonus produrrà 3 eseguibili:
push_swap, checker e b_checker.

per usare la GUI semplicemente usate in pipe push_swap | b_checker (dando lo stesso argomento).
