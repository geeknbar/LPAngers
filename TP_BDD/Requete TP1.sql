SQL requete


/***************************************************/
/*2*/
create table [if not exists] client(
  num_secu VARCHAR(30) PRIMARY KEY,
  nom VARCHAR(30),
  prenm VARCHAR(30),
  )
  ;
  
create table [if not exists] vehicule
  num_imat VARCHAR(30) PRIMARY KEY,
  modele VARCHAR(30),
  annee INT(4),
  num_secu VARCHAR(30),
  )
  ;
  
create table [if not exists] sinistre
  num INT (10) PRIMARY KEY,
  num_secu VARCHAR(30),
  montant int(10),
  responsabilite VARCHAR(30),
  )
  ;
/***************************************************/

/*3.1*/

insert into client values ('1710549123456','Rudoux','Patrick',null);
/*3.2*/
insert into client values ('1670649234567','Lenoir','Herve',null);
/*3.3*/
insert into client values ('2740749345678','Drabert','Severine',null);

/*3.4*/
insert into vehicule values ('1234 TZ 49','Twingo','2000','1710549123456');
/*3.5*/
insert into vehicule values ('2345 RA 49','R21','1980','1670649234567');
/*3.6*/
insert into vehicule values ('3456 RZ 49','Supercinq','1984','1710549123456');
/*3.7*/
insert into sinistre values ('200201','1710549123456','1000','non respo');
/*3.8*/
insert into sinistre values ('200202','1710549123456','','50%');
/*3.9*/
update vehicule set num_imat='4321 RZ 49' where num_imat='1234 TZ 49';
/*3.10*/
update vehicule set annee=annee+1;


/***************************************************/

/*4.1*/


Select * from vehicule where num_secu='1710549123456';
Select * from vehicule where num_secu='2740749345678';

/*4.2*/
select num_secu from client where nom='Rudoux';
/*4.3*/

/*4.4*/

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


/*5.3*/
delete from sinistre;
/*5.4*/
drop table client,sinistre,vehicule;