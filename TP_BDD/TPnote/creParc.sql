-- Creation des tables et PK


drop table IF EXISTS Segment;
drop table IF EXISTS Type;
drop table IF EXISTS Salle;
drop table IF EXISTS Logiciel;
drop table IF EXISTS Poste;
drop table IF EXISTS Installer;


CREATE TABLE Segment
	(indIP      varchar(11),
	 nomSegment varchar(20) NOT NULL,
	 etage TINYINT(1),
	 CONSTRAINT pk_Segment PRIMARY KEY (indIP)) ENGINE = InnoDB;

CREATE TABLE Salle
	(nSalle     varchar(7),
	 nomSalle   varchar(20) NOT NULL,
	 nbPoste    TINYINT(2),
	 indIP      varchar(11),
	 CONSTRAINT pk_salle PRIMARY KEY (nSalle),
	 CONSTRAINT fk_Salle_indIP_Segment FOREIGN KEY(indIP) REFERENCES Segment(indIP)) ENGINE = InnoDB;

CREATE TABLE Types
	(typeLP   varchar(9), 
    nomType varchar(20),
	 CONSTRAINT pk_types PRIMARY KEY(typeLP)) ENGINE = InnoDB;

CREATE TABLE Poste
	(nPoste     varchar(7),
	 nomPoste   varchar(20) NOT NULL,
	 indIP      varchar(11),
	 ad         varchar(3),
	 typePoste  varchar(9),
	 nSalle     varchar(7),
	 CONSTRAINT pk_Poste PRIMARY KEY (nPoste),
 CONSTRAINT ck_ad    CHECK (ad BETWEEN '000' AND '255'),
	 INDEX (indIP),
 CONSTRAINT fk_P_i_S FOREIGN KEY(indIP) REFERENCES Segment(indIP),
 INDEX (nSalle),
 CONSTRAINT fk_P_n_S FOREIGN KEY(nSalle) REFERENCES Salle(nSalle),
 INDEX (typePoste),
 CONSTRAINT fk_P_t_T FOREIGN KEY(typePoste) REFERENCES Types(typeLP)
	) ENGINE = InnoDB;

CREATE TABLE Logiciel
	(nLog       varchar(5),
	 nomLog     varchar(20) NOT NULL,
	 dateAch    DATETIME,
	 version    varchar(7),
	 typeLog    varchar(9),
	 prix       DECIMAL(6,2),
	 CONSTRAINT pk_Logiciel PRIMARY KEY (nLog),
	 CONSTRAINT ck_prix     CHECK (prix >= 0),
	 CONSTRAINT fk_Logiciel_typeLog_Types FOREIGN KEY(typeLog) REFERENCES Types(typeLP)) ENGINE = InnoDB;

CREATE TABLE Installer
	(nPoste     varchar(7),
	 nLog       varchar(5),
	 numIns     INTEGER(5) AUTO_INCREMENT,
	 dateIns    TIMESTAMP DEFAULT NOW(),
	 delai      SMALLINT,
	 CONSTRAINT pk_Installer PRIMARY KEY(numIns),
 INDEX (nPoste),
	 CONSTRAINT fk_Inst_nPoste_Poste FOREIGN KEY(nPoste) REFERENCES Poste(nPoste),
INDEX (nLog),
	 CONSTRAINT fk_Installer_nLog_Logiciel FOREIGN KEY(nLog) REFERENCES Logiciel(nLog))
ENGINE = InnoDB;

