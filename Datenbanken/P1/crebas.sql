/*==============================================================*/
/* DBMS name:      PostgreSQL 9.x                               */
/* Created on:     27.11.2020 10:59:22                          */
/*==============================================================*/


drop index FLIEGT_FK;

drop index HAT_FK;

drop index ABFLUG_PK;

drop table ABFLUG;

drop index FLUGHAFEN_PK;

drop table FLUGHAFEN;

drop index FLUGZEUG_PK;

drop table FLUGZEUG;

drop index ZIEL_FK;

drop index START_FK;

drop index VERBINDUNG_PK;

drop table VERBINDUNG;

/*==============================================================*/
/* Table: ABFLUG                                                */
/*==============================================================*/
create table ABFLUG (
   FLUGNR               VARCHAR(10)          not null,
   DATUM                DATE                 not null,
   KENNZEICHEN          VARCHAR(10)          not null,
   constraint PK_ABFLUG primary key (DATUM)
);

/*==============================================================*/
/* Index: ABFLUG_PK                                             */
/*==============================================================*/
create unique index ABFLUG_PK on ABFLUG (
DATUM
);

/*==============================================================*/
/* Index: HAT_FK                                                */
/*==============================================================*/
create  index HAT_FK on ABFLUG (
FLUGNR
);

/*==============================================================*/
/* Index: FLIEGT_FK                                             */
/*==============================================================*/
create  index FLIEGT_FK on ABFLUG (
KENNZEICHEN
);

/*==============================================================*/
/* Table: FLUGHAFEN                                             */
/*==============================================================*/
create table FLUGHAFEN (
   IATA                 VARCHAR(3)           not null,
   LANGENGRAD           VARCHAR(25)          not null,
   BREITENGRAD          VARCHAR(25)          not null,
   NAME                 VARCHAR(255)         null,
   constraint PK_FLUGHAFEN primary key (IATA)
);

/*==============================================================*/
/* Index: FLUGHAFEN_PK                                          */
/*==============================================================*/
create unique index FLUGHAFEN_PK on FLUGHAFEN (
IATA
);

/*==============================================================*/
/* Table: FLUGZEUG                                              */
/*==============================================================*/
create table FLUGZEUG (
   KENNZEICHEN          VARCHAR(10)          not null,
   TYP                  VARCHAR(255)         null,
   SITZPLATZE           INT4                 null,
   constraint PK_FLUGZEUG primary key (KENNZEICHEN)
);

/*==============================================================*/
/* Index: FLUGZEUG_PK                                           */
/*==============================================================*/
create unique index FLUGZEUG_PK on FLUGZEUG (
KENNZEICHEN
);

/*==============================================================*/
/* Table: VERBINDUNG                                            */
/*==============================================================*/
create table VERBINDUNG (
   FLUGNR               VARCHAR(10)          not null,
   START                VARCHAR(3)           not null,
   ZIEL                 VARCHAR(3)           not null,
   constraint PK_VERBINDUNG primary key (FLUGNR)
);

/*==============================================================*/
/* Index: VERBINDUNG_PK                                         */
/*==============================================================*/
create unique index VERBINDUNG_PK on VERBINDUNG (
FLUGNR
);

/*==============================================================*/
/* Index: START_FK                                              */
/*==============================================================*/
create  index START_FK on VERBINDUNG (
START
);

/*==============================================================*/
/* Index: ZIEL_FK                                               */
/*==============================================================*/
create  index ZIEL_FK on VERBINDUNG (
ZIEL
);

alter table ABFLUG
   add constraint FK_ABFLUG_FLIEGT_FLUGZEUG foreign key (KENNZEICHEN)
      references FLUGZEUG (KENNZEICHEN)
      on delete restrict on update restrict;

alter table ABFLUG
   add constraint FK_ABFLUG_HAT_VERBINDU foreign key (FLUGNR)
      references VERBINDUNG (FLUGNR)
      on delete restrict on update restrict;

alter table VERBINDUNG
   add constraint FK_VERBINDU_START_FLUGHAFE foreign key (START)
      references FLUGHAFEN (IATA)
      on delete restrict on update restrict;

alter table VERBINDUNG
   add constraint FK_VERBINDU_ZIEL_FLUGHAFE foreign key (ZIEL)
      references FLUGHAFEN (IATA)
      on delete restrict on update restrict;

