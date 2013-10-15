--------------------------------
Le casse brique en version texte
--------------------------------

Il s'agit de réaliser un casse brique en version texte en s'inspirant du code de la goutte d'eau.

Pour ceux qui ne connaissent pas le jeu du casse brique: voir e.g. http://www.jeux-gratuit.com/jeux-gratuits-casse-brique.html

Les graphismes seront fait en mode texte dans le terminal, en utilisant la même méthode que la goutte d'eau. Cela ressemblera à cela:


######################################
#                                    #
#                                    #
# HHHH HHHH HHHH HHHH HHHH HHHH HHHH #
# HHHH HHHH HHHH HHHH HHHH HHHH HHHH #
# HHHH HHHH HHHH HHHH HHHH HHHH HHHH #
# HHHH HHHH HHHH HHHH HHHH HHHH HHHH #
# HHHH HHHH HHHH      HHHH HHHH HHHH #
# HHHH HHHH           HHHH HHHH HHHH #
#                                    #
#                                    #
#                                    #
#                                    #
#                                    #
#                                    #
#     O                              #
#                                    #
#                                    #
#                                    #
#                                    #
#                                    #
#     ========                       #
#                                    #
######################################

Les briques sont en haut (les "HHHH"), la balle ('O') rebondit sur les murs du haut et des cotés et quand elle touche une brique, la brique disparait. L'utilisateur dirige le gallet en bas ("========") de gauche à droite et de droite à gauche avec les touches ("f" et "g" par exemple). Si la balle touche le mur du bas, elle
disparait et le l'utilisateur a perdu. La balle rebondit sur le gallet si ce dernier est sur sa trajectoire. Si toutes les briques ont disparues, l'utilisateur a gagné. 

Méthode:

Question 1) Commencez par adapter le programme de la goutte d'eau pour n'avoir qu'une seule goutte, qui rebondit contre les murs. Pour le rebond, il faut changer la vitesse de la goutte ("dx" et/ou "dy") lorsque la goutte est en contact avec un mur. Il vous faudra donc à chaque tour:
- détecter si la goutte est en contact avec un mur,
- changer dx ou dy en conséquence.

Question 2) Affichez le gallet et déplacez-le avec les touches "f" et "g", en vous inspirant de la goutte. Vous pouvez utiliser une nouvelle structure (struc) pour le gallet, indiquant ses coordonnées et sa largeur. Ensuite, il vous faudra détecter si le gallet est en contact avec la goutte, et si oui, changer le "dx" ou le "dy" de la
goutte en conséquence.

Question 3) ajoutez un tableau de brique. Vous utiliserez une structure (struct) vue en cours pour chaque brique. Cette structure contiendra les coordonnées de la brique, et aussi un booléen indiquant si elle est présente ou détruite. Vous n'afficherez que les briques présentes. Enfin, il faudra faire une fonction pour savoir si la balle touche une brique ou pas. Et si elle touche une brique donnée, elle doit la faire disparaitre et rebondir. 

Vous travaillerez en groupe de projet.

Planning:

- demain soir le 16/10 à minuit au plus tard: 
  déposer le résultat de la question 1) sur github dans votre projet, 
  dans un répertoire special CasseBrique/

- jeudi soir le 17/10 à minuit au plus tard:
  déposer le résultat de la question 2)

- dimanche soir le 20/10 à minuit au plus tard:
  déposer l'ensemble du programme.

Vous pouvez m'envoyer vos questions à ly@labri.fr sujet [AP1 PUF]

Bon courage !
