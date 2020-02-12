#Projet IN204 - Lancer de rayons

####Par Marie Kalouguine et Davy Simeu

![Image de plusieurs boules dont une réfléchissante sur un sol quadrillé](./images/image2.png)

##Description du projet
blablabla

##Utilisation du code pour synthétiser des images
####Consignes utilisateur

Le projet a été réalisé sous une distribution Linux et pour Linux, il est donc recommandé d'en être équipé. La compilation nécessite la version C++11 du compilateur.

Pour compiler le projet, il suffit d'entrer la commande `make` dans la ligne de commande.
Cela crée un fichier exécutable `raytracing`, qui permet d'analyser le fichier de description de scènes `scene.xml`(se trouvant dans le même répertoire), et synthétiser une image correspondante par lancer de rayons.

Pour tester le programme, modifiez le fichier XML à vos besoins, puis lancez la commande `./raytracing`

####Description de scènes avec XML
La description d'une scène se fait à l'aide de balises dans le fichier `scene.xml`, dans un langagé basé sur XML. La scène s'apparente ainsi à une structure d'arbre. La lecture du fichier se fait grâce à la bibliothèque tinyXML2, donc le code source a été inclus dans le dossier src.

À la racine de l'arbre se trouve la balise <world\>, dans laquelle on place les différents objets composant la scène. Parmi eux, il y a la balise caméra <camera\>, l'ensemble des éclairages <lights\>, ainsi que l'ensemble des objets à représenter <shapes\>.

Une caméra <camera\> est définie par le point duquel on regarde (origin), ainsi qu'un autre point indiquant la direction. Ce deuxième point est dans le plan de projection de la caméra, et l'angle de vue est déterminé par la taille de l'image finale en pixels (pxwidth et pxheight) ainsi que la largeur "réelle" du plan de projection (width). Sa hauteur n'est pas renseignée mais calculée automatiquement, afin d'éviter d'étirer l'image par inadvertence. La modification de pxwidth et pxheight infue autant sur l'angle vertical que sur la résolution de l'image (et donc la longueur de l'execution).

> La rotation de la caméra autour de cet axe est négligée, on considère que le bord bas du plan de projection est toujours horizontal.

À l'intérieur de la balise <lights\>, on peu placer autant de sources de lumière que souhaité, de type <sun\> (source à l'infini) ou de type <lamp\> (source ponctuelle). Chaque source lumineuse doit impérativement être dotée de sa position ainsi que de son intensité (attribut brightness).

À l'intérieur de la balise <shapes\>, on peu placer autant d'objets que souhaité, de type <sphere\> (sphère) ou de type <plane\> (plan infini). Tout objet est muni d'une couleur (attribut color), d'une réflexivité (attribut gloss). Un attribut supplémentaire chess peut être ajouté pour décorer la surface de l'objet avec un échiquier. La valeur de l'attribut doit valoir la couleur de l'échiquier à apposer. La valeur "default" lui donne la couleur opposée à celle de l'objet (un objet bleu obtient alors un échiquier orange).

Les couleurs pouvant être utilisées sont :  
red, green, blue, white, black, grey, yellow, cyan, orange, purple, pink, brown

Voici par exemple le fichier XML qui a servi à synthétiser l'image en tête du présent document :
```
<world>
	<camera pxwidth="2000" pxheight="500" width="3.3">
		<origin x="1" y="0" z="3"/>
		<target x="4" y="5" z="2"/>
	</camera>
	<lights>
		<lamp brightness="1.5">
			<point x="5" y="5" z="4"/>
		</lamp>
		<lamp brightness="1.5">
			<point x="10" y="5" z="3"/>
		</lamp>
		<lamp brightness="1.5">
			<point x="13" y="7" z="2"/>
		</lamp>
	</lights>
	<shapes>
		<sphere color="red" gloss="0" size="1.5" chess="green">
			<point x="9" y="11" z="1.5"/>
		</sphere>
		<sphere color="grey" gloss="1" size="1">
			<point x="6" y="11" z="1"/>
		</sphere>
		<sphere color="red" gloss="0" size="0.3">
			<point x="9" y="8" z="0.3"/>
		</sphere>
		<sphere color="white" gloss="0" size="0.6" chess="default">
			<point x="7" y="7.5" z="0.6"/>
		</sphere>
		
		<plane color="blue" gloss="0.1" chess="white">
			<origin x="0" y="0" z="0"/>
			<normal x="0" y="0" z="1"/>
		</plane>
		<plane color="white" gloss="0">
			<origin x="20" y="20" z="0"/>
			<normal x="-3" y="-1" z="0"/>
		</plane>
		<plane color="white" gloss="0">
			<origin x="20" y="20" z="0"/>
			<normal x="1" y="-3" z="0"/>
		</plane>
		<plane color="white" gloss="0">
			<origin x="-20" y="-20" z="0"/>
			<normal x="3" y="1" z="0"/>
		</plane>
		<plane color="white" gloss="0">
			<origin x="-20" y="-20" z="0"/>
			<normal x="-1" y="3" z="0"/>
		</plane>
		<plane color="white" gloss="0">
			<origin x="0" y="0" z="50"/>
			<normal x="0" y="0" z="-1"/>
		</plane>
	</shapes>
</world>
```

> **Attention :**  Le code permettant de lire le fichier xml ne contient pas encore de vérification quant au respect de la syntaxe.  
Un fichier mal écrit a de fortes chances de mener à une *Segmentation Fault*.

##Structure du projet

Pour réussir à couvrir l'ensemble des spécifications énoncées plus haut, on a pensé à une représention graphique des fonctionnalités désagrégées de notre programme :

![Décomposition fonctionelle](./images/functional_decomposition.svg)

Il ne fait pas afficher les differents grands axes de notre programme mais aussi l'enchaînement des tâches dans le processus de rendu de l'image.

En prenant le cas particulier du fichier *math_objects* (le plus large de tous), on y retrouve la définition de tous les objets mathématiques qu'on manipulera dans la résolution de notre problème. La classe **Point** qui désignera un point quelconque dans notre espace à trois dimensions et la classe **Ray** décrit des vecteurs au sens mathématique mais sont interprétés ici pour des besoins de correspondance aux rayons (en l'occurrence lumineux) partant d'un point vers un autre point de notre espace.

Avec ça, une *"interface"* de méthodes spécifiques pour appliquer les opérations mathématiques usuelles qu'on appliquerait sur de tels objets : *produit vectoriel, produit scalaire, norme, distance*, etc.

Le projet est séparé en plusieurs fichiers source, tous regroupés dans le dossier **src**. Le dossier **test** contient des tests unitaires qui ont été utilisés pour développer la syntaxe xml ainsi que la souvegarde d'une image au format .ppm depuis un tableau de couleurs rgb.
Les fichiers sources sont tous regroupés dans le dossier **src**.  
Le dossier **test** contient des tests unitaires qui ont été utilisés pour développer la syntaxe xml ainsi que la souvegarde d'une image au format .ppm depuis un tableau de couleurs rgb.   
Le dossier **image** n'est pas nécessaire à la compilation, il regroupe simplement quelques images obtenues le long des tests.

Les fichiers sources vont tous par paires, un fichier source c++ (extension .cpp) et son header (extension .hpp). La seule exception est le fichier raytracing.cpp, qui contient la fonction main(). Chaque paire correspond la plupart du temps à une ou plusieurs classes, ainsi les méthodes de classe correspondantes.  
Le fichier initialization.cpp (et son header correspondant) n'implémente pas une classe, mais la fonction permettant d'initialiser la scène en lisant le fichier xml.

Lors de la compilation séparée, les fichiers objets créés sont stockés dans un dossier **./obj** créé à l'occasion.

**Dependance des classes :**

![Diagramme des dépendances de classes](./images/class_dependencies.svg)

**Description des classes :**

* Les classes **Point** et **Ray** ont la particularité d'implémenter des objets purement mathématiques (d'où le nom du fichier les contenant, *math_objects.cpp*). Un point est un ensemble de trois coordonnées *double*, et un ray, c'est-à-dire un rayon, est un ensemble de deux points. Les deux peuvent être traités comme des vecteurs (le Ray étant juste un vecteur avec un point de départ), et sont munis de méthodes mathématiques permettant de les manipuler comme tels (produit scalaire, produit vectoriel, somme etc...).

* La classe **Color** est une classe paramétrée, car une couleur en code rgb peut aussi bien être représentée en *unsigned char* que en *float* (ou *double*). Pour des questions de confort, un objet sera décrit avec des couleurs en *Color<unsigned char\>*, puis la couleur d'un rayon de lumière sera décrite avec des *Color<float\>* (afin d'éviter le calcul modulo 255), puis repassée tout à la fin en *Color<unsigned char\>* pour sauvegarder l'image finale. Une petite bibliothèque de couleurs permet de spécifier la couleur d'un objet en donnant le nom (comme "red" ou "cyan") plutôt que la décomposition rgb.

* La classe **Shape** est une classe abstraite représentant n'importe quel objet physique dans la scène. Il est déterminé par la couleur de sa surface (qui peut être inhomogène), ainsi que sa réflexivité. Un objet quelconque implémente trois méthodes :
	* `bool is_crossed (const Ray& r, Point& I) const` qui permet de savoir si un rayon intersecte l'objet, et si oui renvoie le point d'intersection par référence
	* `Ray get_normal_vect(const Point& P) const` qui permet d'obtenir le vecteur normal et unitaire à la surface de l'objet à un point donné, avec l'origine sur ce point.
	* `Color<unsigned char> get_color(const Point& P) const` qui permet d'obtenir la couleur de la surface de l'objet à un point donné de celui-là.
	
	La classe **Shape** a deux classes filles **Sphere** et **Plane**, qui sont les implémentations des formes tridimensionnelles "sphère" et "plan infini".

* La classe **Light_source** est également une classe abstraite, représentant une source lumineuse lambda. Sa principale méthode consiste à obtenir le rayon lumineux dirigé vers elle depuis un point donné (méthode nécessaire pour calculer l'éclairage).  
La classe **Light_source** a deux classes filles **Sun** et **Lamp**, qui sont les implémentations des sources lumineuses respectivement à l'infini ou ponctuelle.

* La classe **Camera** implémente, comme son nom l'indique, la caméra qui permet d'observer la scène. La façon dont elle est définie est expliquée dans la partie "Description de scènes avec XML" du présent document.  
Sa méthode `Ray ray_from_pixel(unsigned x, unsigned y) const` permet d'obtenir le rayon qui passe par l'origine de la caméra et par un pixel donné sur l'image projetée.

* La classe **Environment** regroupe ces trois dernières classes, car elle n'est rien d'autre que l'ensemble des objets nécessaires pour construire l'image à synthétiser. Cette classe est la plus compliquée de toutes. Elle comporte une **Camera**, un vecteur de **shared_ptr<Shape\>** et un vecteur de **shared_ptr<Light_source\>**. L'utilisation des *shared_ptr* est nécessaire car les différentes classes filles ne prennent pas toutes le même espace mémoire, et un vecteur ne peut donner qu'un espacce constant pour chaque élément.  
Cette classe comporte les méthodes suivantes :
	* `int find_first_intersect(const Ray& r, Point& I) const` permet de trouver l'intersection la plus proche d'un rayon avec les objets de la scène. La valeur renvoyée vaut -1 s'il n'y a pas d'intersection, et l'indice de l'objet rencontré sinon. Le point d'intersection est renvoyé par référence.
	* `float lighting(const Point&, unsigned) const` permet d'obtenir l'éclairage d'un point sur un objet, en prenant en compte toutes les sources de lumière ainsi que les ombres des autres objets.
	* `Ray ray_from_pixel(unsigned x, unsigned y) const` permet d'obtenir le rayon depuis l'origine de la caméra, et correspondant à un pixel donné. Cette méthode réutilise une méthode de la classe **Camera**.
	* `Color<float> recursive_color_from_ray(Ray r, float coeff, unsigned counter) const` permet d'obtenir la couleur d'un rayon donné en comptant l'éclairage et les réflexions contre la surface. Les variables *coeff* et *counter* permettent d'arrêter la récursion.
	* `void recursive_raytracing() const` reprend les deux dernières méthodes pour construire l'image complète, en parcourant tous les pixels et en calculant ainsi leur couleur.
	* `Color<float> color_from_ray(Ray r) const` et `void raytracing() const` ont les mêmes rôles, mais n'implémentent pas la récursivité. Ce sont des restes de quand l'algorithme n'implémentait pas encore la réflexion.

 **L'algorithme théorique :** 
On commence par 
##Améliorations possibles

Le projet est loin d'être parfait, et il reste encore beaucoup à faire pour obtenir un réalisme parfait. Voici quelques idées pour poursuivre le projet :

