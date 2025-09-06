def findTxtINF(phrase):
    longueur = len(phrase)
    i = 0
    trouver = False
    while i < longueur:  # -2 pour éviter de dépasser
        if phrase[i] == "I":
            if phrase[i+1] == "N":
                if phrase[i+2] == "F":
                    print(i)  # affiche la position du "I"
                    trouver = True
        i += 1

    if trouver == False:
        print("-1")
    

# Test
findTxtINF("J’ai un cours d’INF1005C")
