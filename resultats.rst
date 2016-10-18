Correction du TP1
~~~~~~~~~~~~~~~~~

Étudiant
========

Istvan Szalai (SZAI29079604)

Résultat
========

+-------------------------+-----------------------------+-----------+-----------+
| Critère                 | Description                 | Note      | Sur       |
+=========================+=============================+===========+===========+
|                         | Affichage de la montagne,   |           |           |
| Fonctionnabilité        | affichage de l'eau,         | 38        | 40        |
|                         | validation                  |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Modularité fonctionnelle    | 10        | 10        |
| Qualité du code         +-----------------------------+-----------+-----------+
|                         | Style et documentation      | 12        | 15        |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Respect du format Markdown, |           |           |
| Fichier README          | qualité du contenu          | 8         | 10        |
|                         |                             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Compilation et nettoyage    |           |           |
| Makefile                | (``make`` et                | 9         | 10        |
|                         | ``make clean``)             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | *Commits* liés à une tâche  |           |           |
| Utilisation de Git      | spécifique, message clair   | 15        | 15        |
|                         | et pertinent                |           |           |
+-------------------------+-----------------------------+-----------+-----------+
| Pénalité (retard)       |                             | -9        |           |
+-------------------------+-----------------------------+-----------+-----------+
| **Total**                                             | **83**    | **100**   |
+-------------------------+-----------------------------+-----------+-----------+

Commentaires
============

- Sur Mac OS, tous les tests passent et le programme compile avec deux
  avertissements (``-Wunused-value`` et ``-Wunused-parameter``).
- Excellente modularité.
- Bonne qualité du code en général. Indentation parfois inégale.  Aérer
  davantage autour des opérateurs et des parenthèses/accolades.
- Plusieurs valeurs magiques (utiliser des constantes, même pour les chaînes de
  caractères).
- Excellente documentation des fonctions.
- Fichier README plutôt bien. Mettre les noms de fichier entre apostrophes
  inversés. Les exemples de fonctionnement pourraient être mieux présentés.
- Makefile correct (ne pas oublier l'option ``-Wall``).
- Bonne utilisation de Git.
