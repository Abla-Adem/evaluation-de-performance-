# evaluation-de-performance-
les tps du module Evaluations de performance 
TP1:  

             make           
            ./run estampile t0 t_min t_max p nw nr a h ph c s s_min s_max  
pour les arguments veuillez suivre les instructions:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    -estampile:nombre de requete  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    -t0:le temps de depart  
&nbsp;&nbsp;&nbsp;&nbsp;  &nbsp;&nbsp;&nbsp;&nbsp;  -t_min:la borne inferieur du temps  
&nbsp;&nbsp;&nbsp;&nbsp;  &nbsp;&nbsp;&nbsp;&nbsp;  -t_max:la borne superieur du temps si (t_min==t_max) alors le temps varie avec un pas de t_min  
   &nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;-p:probalite que sa soit une ecriture si p==0 alors on va faire nw ecriture et nr ecriture  
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -a:l'adresse de depart  
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;si(a>0)alors l'adresse sera sequenciel avec un pas de s  
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;si(a==0) alors l'adresse de depart sera generer aleatoirement et evolura entre a(le chfire generer aleatoire et c)  
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sinon elle evoluera entre(le chfire generer aleatoire et c avec une probalibite ph d'etre en a et h)  
   &nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;-s:la taille des opration en octet  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-s_min:la borne inferieur de la taille s  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-s_max:la borne superieur  si (s>0) alors le temps varie avec un pas s  
    pour la derniere question:
    
             ./run 10000 0 1 1 0.3 10 5 0 838860800 0.2 1073741182 0 4094 1084576
    
