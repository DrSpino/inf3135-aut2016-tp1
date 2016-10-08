# Travail pratique 1 [![build status](https://gitlab.com/ventilooo/inf3135-aut2016-tp1/badges/master/build.svg)](https://gitlab.com/ventilooo/inf3135-aut2016-tp1/commits/master)

## Description

Projet individuel
(Construction et maintenance de logiciels, INF3135, UQAM, Automne 2016)

*Petit programe C, prenant des arguments afin de reproduire une chaine de montagne en caractere ASCII et de montrer les possibles retenues d'eau de cette formation rocheuse.*

## Auteur

Istvan Szalai (SZAI29079604)

## Fonctionnement

*Compilation:* `make`

### cas 1:
* Entrée : `./tp1 X E 1,2,4,2,5,1,2,3,1,5,3`
* Sortie : `----XEEEEX-
            --XEXEEEEX-
            --XEXEEXEXX
            -XXXXEXXEXX
            XXXXXXXXXXX`

### cas 1:
* Entrée : `./tp1 X 1,2,1`
* Sortie : `Nombre d'arguments invalides: il en faut 3`

## Contenu du projet

* Makfile -> Construction du projet.
* .gitgignore -> Permet d'ignorer les fichier non destiner a etre versioner. 
* LICENCE -> Notice de la Licence sous laquelle le projet est distribuer.
* README.md -> information generale sur le projet ainsi que les instruction pour l'utiliser.
* .gitlab-ci.yml -> contient les specification pour l'integratiosn contineu sur gitlab.com
* tp1.c -> contient le code source du projet.

## Références

* [Documentation du Language C](http://www.tutorialspoint.com/c_standard_library/)
* [Specification du Projet](http://lacim.uqam.ca/~blondin/fr/inf3135-tp1)

## Statut

Indiquer si le projet est complété et sans bogue. Sinon, expliquez ce qui
manque ou ce qui ne fonctionne pas.