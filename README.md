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
* .gitgignore -> Permet d'ignorer les fichiers non destinés a être versionés. 
* LICENCE -> Notice de la Licence sous laquelle le projet est distribué.
* README.md -> Informations générale sur le projet ainsi que les instructions pour l'utiliser.
* .gitlab-ci.yml -> Contient les specifications pour l'integrations continue sur gitlab.com
* tp1.c -> Contient le code source du projet.
* test.bats -> Tests du projet.

## Références

* [Documentation du Language C](http://www.tutorialspoint.com/c_standard_library/)
* [Specification du Projet](http://lacim.uqam.ca/~blondin/fr/inf3135-tp1)

## Statut

**FINI** 