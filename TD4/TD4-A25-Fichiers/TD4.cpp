////////////////////////////////////////////////////////////////////////////////
/// TD4 Automne 2025, INF1005C.
/// \file    TD4.cpp
/// \authors Sofiene Beji et François-R Boyer
////////////////////////////////////////////////////////////////////////////////

#pragma region "Inclusions" //{

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <span>  // Noter que si votre compilateur ne supporte pas bien C++20, on peut inclure "gsl/span" en C++17.
#include "cppitertools/range.hpp"

using namespace std;
#ifdef ITERBASE_HPP_
using namespace iter;
#endif
#ifdef GSL_SPAN_H
using namespace gsl;
#endif

#pragma endregion //}



#pragma region "Déclaration" //{

#define JUSTE_POUR_QUE_CA_COMPILE return {}; //TODO: Toutes les lignes qui indiquent JUSTE_POUR_QUE_CA_COMPILE sont à éliminer, à mesure que vous écrivez vos fonctions; elles sont là uniquement pour que le programme compile avant d'avoir écrit les fonctions qui doivent retourner une valeur.

#pragma region "Constantes" //{

static const unsigned tailleMaxImage = 30;         ///< La taille maximale d'une image, en pixels, dans chaque dimension.
static const unsigned tailleMaxGroupeImages = 20; ///< Le nombre maximum d'images dans un groupe.

static const int minConcentrationCouleurPrimare = 0;   ///< Valeur minimale que peut prendre une concentration de couleur dans un pixel d'image.
static const int maxConcentrationCouleurPrimare = 255; ///< Valeur maximale que peut prendre une concentration de couleur dans un pixel d'image.

static const unsigned tailleEntete = 50;        ///< Taille, en nombre de caractères, des lignes de séparation dans les affichages d'entêtes; voir exemple dans l'énoncé. 
static const char caractereEnteteGroupe = '*'; ///< Le caractère à afficher pour les entêtes de groupe.
static const char caractereEnteteImage  = '='; ///< Le caractère à afficher pour les entêtes d'image.

static const string nomFichierImages = "Images.txt"; ///< Le nom du fichier à charger.

static const int aucun = -1; ///< Constante à utiliser lorsqu'un indice n'existe pas, par exemple lorsqu'une recherche ne trouve pas.

// Constantes pour indiquer sur quelle dimension s'applique certaines fonctions (i.e. doublerTaille).
// Devrait être un enum mais est seulement matière au chapitre 8 du cours.
static const int dimensionLargeur = 1; ///< Choisit d'appliquer sur la largeur.
static const int dimensionHauteur = 2; ///< Choisit d'appliquer sur la hauteur.

#pragma endregion //}


#pragma region "Structures" //{

/// La couleur composée d'un pixel.
/// Les concentrations de chaque couleur primaire sont entre minConcentrationCouleurPrimare et maxConcentrationCouleurPrimare dans une image.
/// Ce type est aussi utilisé pour la différence entre deux compositions de couleur, et à ce moment les valeurs peuvent être aussi bien positives que négatives.
struct Pixel {
	int tauxRouge;           ///< La concentration de la couleur rouge dans le pixel.
	int tauxVert;            ///< La concentration de la couleur verte dans le pixel.
	int tauxBleu;            ///< La concentration de la couleur bleu  dans le pixel.
};


/// Pour la taille des images, en nombre de pixels.
struct Taille2D {
	unsigned largeur;
	unsigned hauteur;
};


/// Les informations et données d'une image.
/// Utilise actuellement l'allocation statique puisque l'allocation dynamique est vue seulement au chapitre 7 du cours.
struct Image {
	string nomImage;
	Taille2D taille;         ///< Le nombre de pixels de l'image en largeur et hauteur; chaque dimension doit toujours être entre 0 et tailleMaxImage.
	Pixel pixels[tailleMaxImage][tailleMaxImage];   ///< L'ensemble des pixels de l'image dans l'ordre pixels[positionEnHauteur][positionEnLargeur]. Attention que le pixel de coordonnées (x,y) est donc à pixels[y][x].
};


/// Ensemble d'images appartenant au meme type.
/// Si une même image doit être dans plus d'un groupe, les données doivent actuellement être copiées car les pointeurs sont vus au chapitre 7 du cours.
struct GroupeImages {
	string type;                          ///< Le type des images appartenant à ce groupe.
	unsigned nImages;                     ///< Le nombre d'images dans ce groupe; doit être entre 0 et tailleMaxGroupeImages.
	Image images[tailleMaxGroupeImages];  ///< L'ensemble des images du groupe.
};

#pragma endregion //}


#pragma region "Prototypes de fonctions" //{

//  Fonctions pour les pixels 

Pixel creerPixel(int tauxRouge, int tauxVert, int tauxBleu);

void ajouterConcentrationCouleurPrimaire(int& concentrationAModifier, int increment);

void ajouterCouleurPixel(Pixel& pixelAModifier, const Pixel& increment);

char retournerCouleurPixel(const Pixel& pixel);


// Fonctions pour les images

Image creerImage(const string& nomImage, unsigned tailleEnLargeur, unsigned tailleEnHauteur);

void doublerTaille(Image& image, int doitDoublerQuelleDimension, const Pixel& couleur);

void affecterPixel(Image& image, unsigned positionEnLargeur, unsigned positionEnHauteur, const Pixel& pixel);

void afficherImage(const Image& image);


// Fonctions pour les groupes d'images

void ajouterImage(GroupeImages& groupeImages, const Image& image);

void modifierType(GroupeImages& groupeImages, const string& type);

int chercherImageParNom(const GroupeImages& groupeImages, const string& nomImage);

void afficherGroupeImages(const GroupeImages& groupeImages);

GroupeImages lireFichier(const string& nomFichier);


#pragma endregion //}

#pragma endregion //}

void autresTests()
{

}

void testAfficherGroupeImagesBrut(const GroupeImages& groupeImages)
{
	// Affiche groupeImage brut
	for (Image image : groupeImages.images) {
		if (image.nomImage.empty()) {
			continue;
		}
		cout << image.nomImage << ' ' << image.taille.largeur << ' ' << image.taille.hauteur << endl;
		for (int i = 0; i < image.taille.hauteur; i++) {
			for (int j = 0; j < image.taille.largeur; j++) {
				cout << image.pixels[i][j].tauxRouge << image.pixels[i][j].tauxVert << image.pixels[i][j].tauxBleu << ' ';
				//cout << retournerCouleurPixel({ image.pixels[i][j].tauxRouge, image.pixels[i][j].tauxVert, image.pixels[i][j].tauxBleu }) << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
}
void testAfficherImagesBrut(const Image& image)
{
	cout << image.nomImage << ' ' << image.taille.largeur << ' ' << image.taille.hauteur << endl;
	for (int i = 0; i < image.taille.hauteur; i++) {
		for (int j = 0; j < image.taille.largeur; j++) {
			cout << image.pixels[i][j].tauxRouge << ':' << image.pixels[i][j].tauxVert << ':' << image.pixels[i][j].tauxBleu << ' ';
			//cout << retournerCouleurPixel({ image.pixels[i][j].tauxRouge, image.pixels[i][j].tauxVert, image.pixels[i][j].tauxBleu }) << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	// 1 Recuperer (lire) le group d'images à partir du fichier fourni, vérifier qu'il y a le bon nombre d'images, et que la première image a la bonne taille.
	GroupeImages groupeImages = lireFichier(nomFichierImages);

	// 2 Modifier le type de ce groupe d'images par "Images de tests".
	modifierType(groupeImages, "Images de tests");

	// 3 Chercher, dans ce groupe, les images ayant les nom "Image_Verte", "Image_Rouge", et "Blabla".
	Image imageVerte = groupeImages.images[chercherImageParNom(groupeImages, "Image_Verte")];
	Image imageRouge = groupeImages.images[chercherImageParNom(groupeImages, "Image_Rouge")];
	Image imageBlabla = groupeImages.images[chercherImageParNom(groupeImages, "Blabla")];

	// 4 Doubler la taille de Image_Verte en hauteur, en ajoutant des pixels bleus.
	doublerTaille(imageVerte, dimensionHauteur, creerPixel(minConcentrationCouleurPrimare, minConcentrationCouleurPrimare, maxConcentrationCouleurPrimare));

	// 5 Doublee la taille des Image_Rouge en largeur, en ajoutant des pixels rouges.
	doublerTaille(imageRouge, dimensionLargeur, creerPixel(maxConcentrationCouleurPrimare, minConcentrationCouleurPrimare, minConcentrationCouleurPrimare));

	// 6 Modifier la couleur du pixel (1,1) de l'Image_Rouge en augmentant la concetration du bleu de 50 unités et en diminuant la concentration du rouge de 255 unités.
	ajouterCouleurPixel(imageRouge.pixels[0][0], creerPixel(-255, 0, 50));

	// 7 Modifier la couleur du pixel (2,1) de l'Image_Verte en augementant la concetration du bleu de 100 unités.
	ajouterCouleurPixel(imageVerte.pixels[1][0], creerPixel(0, 0, 100));

	// 8 Afficher le groupe d'images.
	groupeImages.images[chercherImageParNom(groupeImages, "Image_Verte")] = imageVerte;
	groupeImages.images[chercherImageParNom(groupeImages, "Image_Rouge")] = imageRouge;
	afficherGroupeImages(groupeImages);
}

#pragma region "Définitions" //{

#pragma region "Fonctions" //{

#pragma region "Fonctions pour les pixels" //{

Pixel creerPixel(int tauxRouge, int tauxVert, int tauxBleu)
{
	// Créer un pixel à partir des informations en paramètres et le retourner.
	return { tauxRouge, tauxVert, tauxBleu };
}


void ajouterConcentrationCouleurPrimaire(int& concentrationAModifier, int increment)
{
	// Augmenter ou diminuer ( suivant le signe de increment ) la concentration de la couleur primaire passée en paramètre. La concentration finale doit être entre minConcentrationCouleurPrimare et maxConcentrationCouleurPrimare .
	concentrationAModifier += increment;

	if (concentrationAModifier > maxConcentrationCouleurPrimare) {
		concentrationAModifier = maxConcentrationCouleurPrimare;
	}
	else if (concentrationAModifier < minConcentrationCouleurPrimare) {
		concentrationAModifier = minConcentrationCouleurPrimare;
	}
}


void ajouterCouleurPixel(Pixel& pixelAModifier, const Pixel& increment)
{
	// Ajoute, composante par composante, l'increment au pixelAModifier, en s'assurant que chaque concentration résultante est dans les bornes.
	ajouterConcentrationCouleurPrimaire(pixelAModifier.tauxRouge, increment.tauxRouge);
	ajouterConcentrationCouleurPrimaire(pixelAModifier.tauxVert, increment.tauxVert);
	ajouterConcentrationCouleurPrimaire(pixelAModifier.tauxBleu, increment.tauxBleu);
}


char retournerCouleurPixel(const Pixel& pixel)
{
	// Retourner  'R' (respectivement 'V' et 'B') pour un pixel contenant uniquement du rouge (respectivement uniquement du vert et uniquement du bleu); ' ' pour un pixel contenant aucun rouge, ni vert, ni bleu; 'Q' pour tout autre couleur de pixel.
	if ((pixel.tauxRouge > 0) && (pixel.tauxVert == 0) && (pixel.tauxBleu == 0))
		return 'R';
	else if ((pixel.tauxRouge == 0) && (pixel.tauxVert > 0) && (pixel.tauxBleu == 0))
		return 'V';
	else if ((pixel.tauxRouge == 0) && (pixel.tauxVert == 0) && (pixel.tauxBleu > 0))
		return 'B';
	else if ((pixel.tauxRouge == 0) && (pixel.tauxVert == 0) && (pixel.tauxBleu == 0))
		return ' ';
	else
		return 'Q';
}

#pragma endregion //}


#pragma region "Fonctions pour les images" //{

Image creerImage(const string& nomImage, unsigned tailleEnLargeur, unsigned tailleEnHauteur)
{
	Image image;

	image.nomImage = nomImage;
	image.taille.largeur = tailleEnLargeur;
	image.taille.hauteur = tailleEnHauteur;
	
	return image;
}


void doublerTaille(Image& image, int doitDoublerQuelleDimension, const Pixel& couleur)
{
	// Doubler la taille de l'image suivant doitDoublerQuelleDimension en paramètre (voir les définitions de constantes pour les valeurs possibles de ce paramètre) en respectant la taille maximale de l'image et en ajoutant des pixels de la couleur spécifiée en paramètre.

	if (image.taille.largeur * 2 > tailleMaxImage || image.taille.hauteur * 2 > tailleMaxImage) {
		return;
	}

	if (doitDoublerQuelleDimension == 1) {
		for (int i = 0; i < image.taille.hauteur; i++) {
			for (int j = (image.taille.largeur); j < (image.taille.largeur * 2); j++) {
				affecterPixel(image, j, i, couleur);
			}
		}
		image.taille.largeur *= 2;
	}
	else if (doitDoublerQuelleDimension == 2) {
		for (int i = (image.taille.hauteur); i < (image.taille.hauteur * 2); i++) {
			for (int j = 0; j < image.taille.largeur; j++) {
				affecterPixel(image, j, i, couleur);
			}
		}
		image.taille.hauteur *= 2;
	}
}


void affecterPixel(Image& image, unsigned positionEnLargeur, unsigned positionEnHauteur, const Pixel& pixel)
{
	// Remplacer le pixel de l'image à la position indiquée par positionEnLargeur et positionEnHauteur par la valeur du pixel passé en paramètre.
	image.pixels[positionEnHauteur][positionEnLargeur] = pixel;
}


void afficherImage(const Image& image)
{
	// Afficher l'image au complet, avec entête pour son nom, chaque pixel étant représenté par un caractère; le caractère à utiliser est indiqué dans la fonction retournerCouleurPixel.  Vous trouverez un exemple d'affichage dans l'enoncé.
	// Cette fonction ne doit avoir aucun ancien "for".

	for (int i : range(tailleEntete)) {
		cout << caractereEnteteImage;
	}
	cout << endl << "Nom de l'image: " << image.nomImage << endl;
	for (int i : range(tailleEntete)) {
		cout << caractereEnteteImage;
	}
	cout << endl;

	for (auto& row : span(image.pixels, image.taille.hauteur)) {
		cout << setw(4) << right;
		for (Pixel pixel : span(row, image.taille.largeur)) {
			cout << retournerCouleurPixel(creerPixel(pixel.tauxRouge, pixel.tauxVert, pixel.tauxBleu));
		}
		cout << endl;
	}
	for (int i : range(tailleEntete)) {
		cout << caractereEnteteImage;
	}
	cout << endl;
}

#pragma endregion //}


#pragma region "Fonctions pour les groupes d'images" //{

void ajouterImage(GroupeImages& groupeImages, const Image& image)
{
	// Si il y a encore de l'espace dans groupeImages, ajouter l'image en paramètre.
	for (Image& i : groupeImages.images) { // & pour modifier la valeur dans groupeImages
		if (i.nomImage.empty()) {
			i = image;
			return;   
		}
	}
}


void modifierType(GroupeImages& groupeImages, const string& type)
{
	// Modifier le type du groupeImages par le type en paramètre.
	groupeImages.type = type;
}


int chercherImageParNom(const GroupeImages& groupeImages, const string& nomImage)
{
	// Retourner l'indice de l'image du groupeImages dont le nom est celui donné par le paramètre nomImage.  Retourner la constante 'aucun' si ce nom n'est pas trouvé.
	int indexImage = 0;

	for (Image image : groupeImages.images) {
		if (image.nomImage == nomImage) {
			return indexImage;
		}
		indexImage++;
	}
	return aucun;
}


void afficherGroupeImages(const GroupeImages& groupeImages)
{
	// Afficher le groupe d'images, soit l'entête pour le type d'images et toutes les images du groupe. (Vous trouverez dans l'énoncé un exemple)
	// Cette fonction ne doit avoir aucun ancien "for".

	for (int i : range(tailleEntete)) {
		cout << caractereEnteteGroupe;
	}
	cout << endl << "Type du groupe d'images: " << groupeImages.type << endl;
	for (int i : range(tailleEntete)) {
		cout << caractereEnteteGroupe;
	}
	cout << endl;
	
	for (const Image& image : span(groupeImages.images, groupeImages.nImages)) {
		afficherImage(image);
	}
}


GroupeImages lireFichier(const string& nomFichier)
{
	// Récuperer (lire), à partir du fichier dont le nom est donné en paramètre, l'ensemble des images stockés, puis retourner un groupe d'images contenant ces images. Le type de ce groupe d'images n'est pas spécifié.
	
	GroupeImages groupeImages = {};

	ifstream imagesTxt(nomFichier);

	unsigned indexImage = 0U;
	while (!ws(imagesTxt).eof()) {
		string nomImage;
		unsigned largeurImage, hauteurImage;

		imagesTxt >> nomImage
			>> largeurImage
			>> hauteurImage;

		Image image = creerImage(nomImage, largeurImage, hauteurImage);

		for (int i = 0; i < hauteurImage; i++) {
			for (int j = 0; j < largeurImage; j++) {
				
				int pixelRouge, pixelVert, pixelBleu;
				imagesTxt >> pixelRouge >> pixelVert >> pixelBleu;
				affecterPixel(image, j, i, creerPixel(pixelRouge, pixelVert, pixelBleu));
			}
		}
		ajouterImage(groupeImages, image);
		indexImage++;
	}
	groupeImages.nImages = indexImage;
	
	return groupeImages;
}

#pragma endregion //}

#pragma endregion //}

#pragma endregion //}
