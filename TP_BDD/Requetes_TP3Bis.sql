--TP3
-- Licence Pro Informatique
-- Correction TP 3 MySQL

-- ModÃ©lisation
create table magazine(
	nom varchar(20) primary key,
	prix numeric(4,2)
);
create table client(
	numero integer primary key,
	prenom varchar(20),
	nom varchar(20),
	ville varchar(20)
);
create table abonnement(
	numeroclient integer,
	nommagazine varchar(20),
	echeance integer,
	constraint akey primary key(numeroclient, nommagazine),
	constraint fk_client foreign key(numeroclient) references client(numero),
	constraint fk_magazine foreign key(nommagazine) references magazine(nom)
);
create table invendus(
	nommagazine varchar(20) references magazine(nom),
	numeromag integer,
	stock integer,
	constraint ikey primary key(nommagazine, numeromag)
);
create table commande(
	numeroclient integer references client(numero),
	nommagazine varchar(20) references magazine(nom),
	numeromag integer,
	constraint cokey primary key(numeroclient, nommagazine, numeromag)
);

-- Insertion
insert into magazine values ('BD Hebdo', 2);
insert into magazine values ('Oraclemag', 4);
insert into client values (5, 'Patrick', 'Rudoux', 'Angers');
insert into client values (8, 'Roland', 'Lebrun', 'Nantes');
insert into client values (10, 'Herve', 'Lenoir', 'Angers');
insert into abonnement values (5, 'Oraclemag', 27);
insert into abonnement values (8, 'Oraclemag', 30);
insert into abonnement values (8, 'BD Hebdo', 78);
insert into commande values (5, 'BD Hebdo', 4);
insert into commande values (8, 'BD Hebdo', 60);
insert into commande values (10, 'BD Hebdo', 60);
insert into commande values (10, 'BD Hebdo', 61);
insert into invendus values ('BD Hebdo', 60, 10);
insert into invendus values ('BD Hebdo', 61, 3);
insert into invendus values ('Oraclemag', 22, 6);

--4.1

grant select on magazine to regis;

--4.2
grant select, update(echeance) on abonnement to regis;

--5.1

select count(distinct ville) --distinct permet d'enlever les doublons
from client, commande
where  (client.numero =commande.numeroclient)
and commande.nommagazine='BD Hebdo';

--version prefere

select count(distinct ville) --distinct permet d'enlever les doublons
from client join commande on (client.numero =commande.numeroclient)
where commande.nommagazine='BD Hebdo';

--5.2

select nommagazine, count(*) as nbabo
from abonnement
group by nommagazine
order by nbabo desc; --ou order by 2;

--5.3
select numeroclient
from abonnement
natural join commande;

select numeroclient
from abonnement join commande using (nommagazine,numeroclient);

--5.4
select nom
from client join abonnement
on client.numero= abonnement.numeroclient
where client.ville='Nantes'
group by client.numero
having count(*) >= 2;

--5.5
select nom
from client join abonnement on (client.numero= abonnement.numeroclient)
left join commande on ((abonnement.numeroclient=commande.numeroclient)and(abonnement.nommagazine=commande.nommagazine))
group by numero
having count(commande.nommagazine)=0;


select nom from client join abonnement on (client.numero=abonnement.numeroclient)
where numero not in (select numeroclient from abonnement join commande using(nommagazine,numeroclient));
-- 5.6

select sum(prix) as totalAncienNum
from magazine join commande on( magazine.nom =commande.nommagazine);

--5.7

select c2.nom
from client c1, abonnement a1, client c2, abonnement a2
where c1.nom ='Rudoux' 
and a1.numeroclient=c1.numero
and c2.ville = c1.ville 
and a2.numeroclient =c2.numero
and a2.nommagazine = a1.nommagazine
--and c2.numero != c1.numero; //non obligatoire mais permet d'enelever le nom du mec que l'on cherche

--5.8

--version simple, mauvais niveau algorithme. Et ne répond pas forcement 
select nom,prenom, count(*) as c
from client join commande on numero=numeroclient
group by numero
order by c desc
limit 1;

--ou

select nom,prenom from
  (select numeroclient, count(*) as c 
    from  commande
    group by numeroclient
    having count(*)=(
      select max(s) 
	from (select count(*)s
		from commande 
		group by numeroclient)temp) -- il faut donner un nom aux sous -requette qui créer une table.
  )t join client on numeroclient=numero;

