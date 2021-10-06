# evaluation-de-performance-
les tps du module Evaluations de performance 
TP1:  
./run estampile t0 t_min t_max p nw nr a h ph c s s_min s_max  
pour les argument veuillez suivre les instruction  
    -estampile:nombre de requete  
    -t0:le temps de depart  
    -t_min:la borne inferieur du temps  
    -t_max:la borne superieur du temps si (t_min==t_max) alors le temps varie avec un pas de t_min  
    -p:probalite que sa soit une ecriture si p==0 alors on va faire nw ecriture et nr ecriture  
    -a:l'adresse de depart  
          si(a>0)alors l'adresse sera sequenciel avec un pas de s  
          si(a==0) alors l'adresse de depart sera generer aleatoirement et evolura entre a(le chfire generer aleatoire et c)  
          sinon elle evoluera entre(le chfire generer aleatoire et c avec une probalibite ph d'etre en a et h)  
    -s:la taille des opration en octet  
    -s_min:la borne inferieur de la taille s  
    -s_max:la borne superieur  si (s>0) alors le temps varie avec un pas s
    
