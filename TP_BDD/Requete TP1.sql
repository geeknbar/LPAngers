SQL requete


/***************************************************/
/*2*/
create table client(
  num_secu CHAR(30) PRIMARY KEY,
  nom VARCHAR(30),
  prenom VARCHAR(30));
  
create table vehicule(
  num_imat CHAR(30) PRIMARY KEY,
  modele VARCHAR(30),
  annee INT(4),
  num_secu CHAR(30)
  )
  ;
  
create table sinistre(
  num numeric(10),
  num_imat CHAR(30),
  num_secu CHAR(30),
  responsabilite numeric(3),
  montant numeric(10,2),
  constraint sinistrekey primary key (num), /*revient au meme que mettre PRIMARY KEY*/
  check (responsabilite <=100)
  )
  ;
/***************************************************/

/*3.1*/

insert into client values ('1710549123456','Rudoux','Patrick');
/*3.2*/
insert into client values ('1670649234567','Lenoir','Herve');
/*3.3*/
insert into client values ('2740749345678','Drabert','Severine');

/*3.4*/
insert into vehicule values ('1234 TZ 49','Twingo','2000','1710549123456');
/*3.5*/
insert into vehicule values ('2345 RA 49','R21','1980','1670649234567');
/*3.6*/
insert into vehicule values ('3456 RZ 49','Supercinq','1984','1710549123456');
/*3.7*/
insert into sinistre values ('200201','2345 RA 49','1670649234567','0','1000');
/*insert into sinistre values (200202,'1234 TZ 49','1710549123456',50,null); */
/*3.8*/
insert into sinistre values ('200202','1710549123456','','50%');
/*3.9*/
update vehicule set num_imat='4321 RZ 49' where num_imat='1234 TZ 49';
/*3.10*/
update vehicule set annee=annee+1;
/*update vehicule set annee = annee+1 where annee >1983;


/***************************************************/

/*4.1*/


Select * from vehicule where num_secu='1710549123456';
Select * from vehicule where num_secu='2740749345678';

/*4.2*/
select num_secu from client where nom='Rudoux';
/*select num_secu as "numéro de sécu" from client where nom='Rudoux';*/
/*4.3 A faire avec les jointures*/
/*select num_imat,nom,prenom from client
join vehicule on client.num_secu=vehicule.num_secu;*/

/*moche*/ select vehicule.num_imat,nom,prenom from client,vehicule
where client.num_secu=vehicule.num_secu;

--ou-- 
select vehicule.num_imat, nom,prenom
from vehicule natural join client;

--ou--
select vehicule.num_imat,nom,prenom
from vehicule join client using (num_secu);

--ou--
select vehicule.num_imat,nom,prenom
from vehicule join client on vehicule.num_secu=client.num_secu;

/*4.4*/

select annee 
from vehicule natural join client
where nom='Rudoux';


/*4.5*/
select num from sinistre where montant='';
/*4.6*/
select nom from client,sinistre 
where sinistre.num='200110'
and client.num_secu=sinistre.num_secu;

/***************************************************/

/*5.1*/
delete from sinistre where num='200202';
/*5.2*/

delete from client where nom like '%o%';
/*5.3*/
delete from sinistre;
/*5.4*/
drop table client,sinistre,vehicule;