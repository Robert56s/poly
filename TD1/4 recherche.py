def findTxtINF(phrase):
    longueur = len(phrase)
    i = 0
    while i < (longueur - 2):  # -2 pour éviter de dépasser
        if phrase[i] == "I":
            if phrase[i+1] == "N":
                if phrase[i+2] == "F":
                    return print(i)  # affiche la position du "I"
        i+=1
    print("-1")
    

# Test
findTxtINF("J’ai un cours d’INF1005C")
