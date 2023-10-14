# Minimalno število postaj

## Opis
Vprašanje je, koliko je največje stevilo postaj oz. intervalov, ki jih lahko odstranimo, da bomo celo pot še vedno znotraj radija vsaj ene postaje.

## Uporaba
zaženemo aplikacijo preko CMD in kot drugi argument damo datoteko s podatki o intervalih.
Podatki v datoteki o intervalih so v obliki: 

celotna_dolzina st_postaj

lokacija_prve_postaje radij_prve_postaje
druga...
.
.

![image](https://github.com/zanivanusa/Minimalno_st_intervalov/assets/60394411/656f3a7d-0a09-40a9-9b1c-e18bdfe7e23a)


v tem primeru je celotna dolžina 40 enot, postaje pa so 3.
prva postaja je na lokaciji 5 in ima radius velikosti 5, torej pokrije območje od 0-10.
druga krije območje od 10-30
tretja pa od 30-50
torej so celotna pot (0-40) pokrita in ne moramo odstranit nobene postaje.

V tem naslednjem primeru pa lahko odstranimo kar dve:

![image](https://github.com/zanivanusa/Minimalno_st_intervalov/assets/60394411/eaae0666-a76f-4038-9822-56ef0390e845)

In sicer postajo 11 8 in 30 3, saj nista obvezni, oz. enako območje pokriva druga postaja, katera je obvezna(njenega območja ne pokriva nobena validna postaja)


## zagon
```
\.bencinskaPostaja.exe  vhodni_pdatki.txt
