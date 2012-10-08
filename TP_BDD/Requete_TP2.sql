Create table membre(
numero integer primary key auto_increment,
nom varchar (20),
prenom varchar(20),
superieur integer);
create table projet(
nom varchar(10) primary key,
priorite numeric(2),
dirigeant integer,
echeance date);
create table affectation(
employe integer,
projet varchar(10),
constraint akey primary key(employe,projet));


insert into membre (nom,prenom, superieur) 
values ('Karamazof','Serge',NULL),('Deray','Odile',1),('Gilet','Gilles',2),('Simon','Jeremi',1),('Lamar','Andre',2);
insert into projet (nom,priorite,dirigeant,echeance)
values ('PRJ1',5,2,'2006-10-14'),('PRJ2',7,5,'2007-04-07');
insert into affectation (employe,projet)
values (1,'PRJ1'),(3,'PRJ1'),(4,'PRJ1'),(5,'PRJ1'),(5,'PRJ2');

--3.1
alter table membre
add salaire numeric(10,2);
--3.2
update membre set salaire = 10000-1000*numero;
--3.3
alter table projet modify priorite numeric(4);
--3.4
update projet set priorite = priorite*100;
--3.5
select*from membre order by salaire limit 1; -- pour trouver celui qui a le salire le mlus faible
update membre set salaire = salaire+100 order by salaire limit 1; -- pour rajouter 100 à celui qui est le moins bien payé

-- 4.1 
select nom,prenom 
from membre
where superieur is NULL;

-- 4.2 
/*
select affectation.employe 
from projet,affectation 
where projet.nom=affectation.projet 
and projet.echeance>='2007-01-01';
*/
--ou
select employe
from affectation join projet on (affectation.projet=projet.nom)
where projet.echeance >='2007-01-01'

-- 4.3 
/*
select membre.prenom
from membre,affectation 
where membre.numero=affectation.employe 
and affectation.projet='PRJ2';
*/
--ou

select prenom
from affectation join membre on (affectation.employe=membre.numero)
where projet='PRJ2';


-- 4.4 
select superieur 
from membre 
where numero=3;

-- 4.5 

select m1.nom
from membre m1, membre m2
where m2.numero=3 and m1.numero =m2.superieur;

--ou

select m1.nom
from membre m1 join membre m2 on m1.numero=m2.superieur
where m2.numero=3;

/*
select nom 
from membre
where numero=(select superieur 
	      from membre 
	      where numero=3);
*/

-- 4.6 
/*
select membre.nom,prenom 
from membre
where membre.numero=(select membre.superieur 
		     from membre 
		     where membre.nom='Simon' 
		     and prenom='Jeremi');
*/
-- m1 superieur, m2 employer
select m1.nom
from membre m1, membre m2
where m2.nom 'Jeremi' and m2.nom='Simon' and m1.numero = m2;

--ou
select m1.nom
from membre m1 join membre m2 on (m1.numero=m2.superieur)
where m2.nom 'Jeremi' and m2.nom='Simon';


-- 4.7 
/*
select membre.nom,membre.prenom 
from membre,affectation
where affectation.employe=membre.numero
and affectation.projet!='PRJ2';
*/

select nom, prenom
from membre
where numero int(
  select employe
  from affectaton
  where = 'PRJ12');

--ou
  
select nom
from membre 
left join affectation on (membre.numero = affectation.employe and affectation.projet = 'PRJ2') where employe is NULL;

-- 4.8 
/*
select membre.nom 
from membre 
where membre.superieur=(select membre.numero 
			 from membre
			 where membre.nom='Karamazof');
*/

select m1.nom
from membre m1, membre m2
where (m1.superieur = m2.numero) and (m2.nom='Karamazof') and (m2.prenom = 'Serge';

--ou


select m1.nom
from membre m1 join membre m2 on (m1.superieur=m2.numero)
where m2.nom='Karamazof' and m2.prenom='Serge';



-- 4.9 
select m1.nom, m1.prenom, m2.nom
from membre m1 left join membre m2
on m1.superieur=m2.numero
order by m1.nom, m1.prenom;



-- 4.10  
select m1.nom
from membre m1, membre m2, membre m3
where (m1.superieur=m2.numero) and (m2.superieur=m3.numero) and (m3.nom='Karamazof') and (m3.prenom='Serge');

--ou

select m1.nom
from membre memb join membre sup join membre supsup
on (memb.superieur= sup.numero) and (sup.superieur= supsup.numero)
where (supsup.nom='Karamazof')and(supsup.prenom='Serge');
-- 5.1

drop table projet
where 


-- 5.2

Drop table affectation;
Drop table projet;
Drop table membre;