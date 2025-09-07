<?xml version="1.0" encoding="UTF-8"?>
<Algo>
    <description courant="SI (v1x*v2x+v1y*v2y==0) ALORS" texte="Demander à l’usager d’entrer chacune des composantes x et y des deux vecteurs. Lire les composantes de l’usager. Multiplier les 2 composantes x chaque vecteur. Additionner le résultat à la multiplication des 2 composantes y de chaque vecteur.  Si le résultat donne 0, afficher que les vecteurs sont orthogonaux. Sinon, afficher que les vecteurs ne sont pas orthogonaux. "/>
    <extension extnom="inactif"/>
    <fonction fctetat="inactif" fctcode=""/>
    <F2 F2para="" F2etat="inactif" F2lignes="" F2defaut=""/>
    <repere repetat="inactif" repcode="-10#10#-10#10#2#2"/>
    <param maxBoucle="500000" totalAffichages="1000" epaisseurPoint="2" arrondiAuto="vrai" epaisseurLigne="2" nbDecimales="8" totalBoucles="5000000"/>
    <item code="200#declarationfonctions" algoitem="FONCTIONS_UTILISEES"/>
    <item code="100#declarationsvariables" algoitem="VARIABLES">
        <item code="1#NOMBRE#v1x" algoitem="v1x EST_DU_TYPE NOMBRE"/>
        <item code="1#NOMBRE#v1y" algoitem="v1y EST_DU_TYPE NOMBRE"/>
        <item code="1#NOMBRE#v2x" algoitem="v2x EST_DU_TYPE NOMBRE"/>
        <item code="1#NOMBRE#v2y" algoitem="v2y EST_DU_TYPE NOMBRE"/>
    </item>
    <item code="101#debutalgo" algoitem="DEBUT_ALGORITHME">
        <item code="4#Ce code va vous dire si deux vecteur 2d sont orthogonaux ou pas#0" algoitem="AFFICHER &quot;Ce code va vous dire si deux vecteur 2d sont orthogonaux ou pas&quot;"/>
        <item code="4#La composante x du premier vecteur#0" algoitem="AFFICHER &quot;La composante x du premier vecteur&quot;"/>
        <item code="2#v1x#pasliste" algoitem="LIRE v1x"/>
        <item code="4#La composante y du premier vecteur#0" algoitem="AFFICHER &quot;La composante y du premier vecteur&quot;"/>
        <item code="2#v1y#pasliste" algoitem="LIRE v1y"/>
        <item code="4#La composante x du deuxieme vecteur#0" algoitem="AFFICHER &quot;La composante x du deuxieme vecteur&quot;"/>
        <item code="2#v2x#pasliste" algoitem="LIRE v2x"/>
        <item code="4#La composante y du deuxieme vecteur#0" algoitem="AFFICHER &quot;La composante y du deuxieme vecteur&quot;"/>
        <item code="2#v2y#pasliste" algoitem="LIRE v2y"/>
        <item code="6#v1x*v2x+v1y*v2y==0" algoitem="SI (v1x*v2x+v1y*v2y==0) ALORS">
            <item code="7#debutsi" algoitem="DEBUT_SI"/>
            <item code="4#Les vecteurs sont orthogonaux.#0" algoitem="AFFICHER &quot;Les vecteurs sont orthogonaux.&quot;"/>
            <item code="8#finsi" algoitem="FIN_SI"/>
            <item code="9#sinon" algoitem="SINON">
                <item code="10#debutsinon" algoitem="DEBUT_SINON"/>
                <item code="4#Les vecteurs ne sont pas orthogonaux.#0" algoitem="AFFICHER &quot;Les vecteurs ne sont pas orthogonaux.&quot;"/>
                <item code="11#finsinon" algoitem="FIN_SINON"/>
            </item>
        </item>
    </item>
    <item code="102#finalgo" algoitem="FIN_ALGORITHME"/>
</Algo>
