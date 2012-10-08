--1.1

select nom from membre where mod(numero,2)=0;


--1.2

select nom, if (salaire > 7000,'Bienpayé','Mal payé') as NiveauSalaire from membre;

--1.3

select avg(salaire) as SalaireMoyen from membre;

--1.4

select employe, count(projet) as NombreProjet
from affectation
group by employe;  

--1.5
select projet, max(salaire)
from affectation join membre on numero= employe
group by projet;


select projet, max(salaire)
from affectation, membre
where membre.numero=affectation.employe
group by projet;

--1.6

select nom, count(projet) as NombreProjet
from affectation, membre
where membre.numero=affectation.employe
group by employe;  

select nom,nb
from (select employe, count(*) as nb from affectation group by employe) table_temp join membre on (numero=employe);

--1.7

select m1.nom, count(m2.superieur)as PersonneDepend
from membre m1 join membre m2 on (m1.numero =m2.superieur)
group by m1.nom;

--1.8