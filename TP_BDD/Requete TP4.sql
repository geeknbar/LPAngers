--sql TP3


--etudiants (ine,nom,prenom,nomcursus)

--cursus(nom,nomresponsable)

--note(ineetudiant,nommatiere,note)

create table Cursus(
	nom varchar(15) primary key,
	responsable varchar(15)
	)ENGINE=InnoDB;
create table Etudiant(
	ine numeric(10) primary key,
	nom varchar(15),
	prenom varchar(15),
	cursus varchar(15),
	index(cursus),
	constraint curs foreign key(cursus) references Cursus(nom)
	)ENGINE=InnoDB;
create table Examen(
	cursus varchar(15),
	matiere varchar(15),
	index(cursus),
	index(matiere),
	constraint exkey primary key (cursus, matiere),
	constraint curs2 foreign key(cursus) references Cursus(nom)
	)ENGINE=InnoDB;
create table Note(
	etudiant numeric(10),
	matiere varchar(15),
	note numeric(2) check (note >= 0 and note <= 20),
	constraint nkey primary key (etudiant, matiere),
	index(etudiant),
	constraint etud foreign key(etudiant) references Etudiant(ine),
	constraint mat foreign key(matiere) references Examen(matiere)
)ENGINE=InnoDB;


insert into Cursus values ('Licence pro', 'F. Lardeux');
insert into Examen values ('Licence pro', 'BD');
insert into Examen values ('Licence pro', 'Systeme');
insert into Examen values ('Licence pro', 'Objets');

insert into Cursus values ('Master', 'F. Saubion');
insert into Examen values ('Master', 'BD');
insert into Examen values ('Master', 'Logique');

insert into Etudiant values (23, 'Accroc', 'Arthur', 'Licence pro');
insert into Note values (23, 'BD', 14);
insert into Note values (23, 'Systeme', 10);
insert into Note values (23, 'Objets', 12);
insert into Etudiant values (32, 'Rambo', 'John', 'Master');
insert into Note values (32, 'BD', 10);
insert into Note values (32, 'Logique', 3);
insert into Etudiant values (28, 'Ingalls', 'Laura', 'Licence pro');
insert into Note values (28, 'BD', 3);
insert into Note values (28, 'Systeme', 14);
insert into Note values (28, 'Objets', 12);

--1--

select matiere
from Etudiant, Examen
where Etudiant.cursus = Examen.cursus
and Etudiant.nom = 'Rambo'
and Etudiant.prenom = 'John';


select matiere
from Etudiant natural join Examen
where Etudiant.nom = 'Rambo'
and Etudiant.prenom = 'John';


--2--
select count(*)
from Etudiant
where cursus='Licence pro';

--3--

select count(distinct matiere)
from Examen


select matiere
from Examen
group by matiere;

--4--

select nom ,prenom
from Etudiant
order by nom, prenom;


select nom
from Etudiant
group by nom;


select prenom
from Etudiant
group by prenom;



--5--
select nom, note
from Etudiant, Note
where Note.etudiant = Etudiant.ine 
and Note.matiere='BD'
order by Note.note desc;

--6--
select avg(Note.note)
from Etudiant join Note on (Etudiant.ine= Note.etudiant)
where cursus='Licence pro'
and matiere='BD';

--7--

select nom from Etudiant join Note on (Note.etudiant=Etudiant.ine) where note <10;


select nom
from Etudiant, Note
where Note.etudiant = Etudiant.ine 
and note between 0 and 9;

--8--

select nom
from Etudiant
where not exists (select null from Note where Note.etudiant=Etudiant.ine and note <10); --sous requête dépendante

--9--
--bien mais attention si deux notes sont égales 
select nom, note, matiere 
from Etudiant, Note
where Note.etudiant = Etudiant.ine 
order by Note.note desc
limit 1;


select nom, note, matiere 
from Etudiant, Note
where note >= all (select note from Note) and Note.etudiant = Etudiant.ine ;

--10--
select nom,prenom
from Etudiant join Note on (Etudiant.ine= Note.etudiant)
where cursus='Licence pro'
and matiere='BD'
and note >= (
select avg(Note.note)
from Etudiant join Note on (Etudiant.ine= Note.etudiant)
where cursus='Licence pro'
and matiere='BD');

--11--
--dependant
select nom,prenom
from Note, Etudiant 
where (Etudiant.ine= Note.etudiant)
and matiere='BD'
and note >= 10
and exists ( select NULL from Note where (Note.etudiant=Etudiant.ine) and note <10);  

--independant
select nom,prenom
from Note, Etudiant 
where (Etudiant.ine= Note.etudiant)
and matiere='BD'
and note >= 10
and Etudiant.ine in( select etudiant from Note where note <10);  


--12--
select cursus, matiere
from Examen
where not exists (select null from Note, Etudiant where Note.Etudiant= Etudiant.ine and note <10 and Etudiant.cursus= Examen.cursus and Note.matiere= Examen.matiere);

select cursus, matiere
from Examen
where (cursus,matiere) not in (select Etudiant.cursus, Note.matiere from Note, Etudiant where Note.etudiant = Etudiant.ine and note <10);

--13--
select Note.matiere, Etudiant.cursus
from Note, Etudiant
where Note.Etudiant= Etudiant.ine and note >=10
group by Note.matiere, Etudiant.cursus
having count(*) >=2;


--4.1--
start transaction;
delete from Etudiant where ine in (select etuidant from note where matiere = 'Logique' and note <10);
rollback;

