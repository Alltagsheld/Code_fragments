/*==============================================================*/
/* DBMS name:      PostgreSQL 9.x                               */
/* Created on:     06.12.2020 13:19:16                          */
/*==============================================================*/


drop index FLIEGT_FK;

drop index HAT_FK;

drop index ABFLUG_PK;

drop table ABFLUG cascade;

drop index BUCHUNG2_FK;

drop index BUCHUNG_FK;

drop index BUCHUNG_PK;

drop table BUCHUNG cascade;

drop index FLUGHAFEN_PK;

drop table FLUGHAFEN cascade;

drop index FLUGZEUG_PK;

drop table FLUGZEUG cascade;

drop index PASSAGIER_PK;

drop table PASSAGIER cascade;

drop index ZIEL_FK;

drop index START_FK;

drop index VERBINDUNG_PK;

drop table VERBINDUNG cascade;

drop index WIRD_GEWARTET_FK;

drop index WARTUNG_PK;

drop table WARTUNG cascade;

/*==============================================================*/
/* Table: ABFLUG                                                */
/*==============================================================*/
create table ABFLUG (
   FLUGNR               VARCHAR(10)          not null,
   ABFLUGDATUM          DATE                 not null,
   KENNZEICHEN          VARCHAR(10)          not null,
   constraint PK_ABFLUG primary key (FLUGNR, ABFLUGDATUM)
);

/*==============================================================*/
/* Index: ABFLUG_PK                                             */
/*==============================================================*/
create unique index ABFLUG_PK on ABFLUG (
FLUGNR,
ABFLUGDATUM
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
/* Table: BUCHUNG                                               */
/*==============================================================*/
create table BUCHUNG (
   FLUGNR               VARCHAR(10)          not null,
   ABFLUGDATUM          DATE                 not null,
   KNR                  INT8                 not null,
   PREIS                MONEY                null,
   constraint PK_BUCHUNG primary key (FLUGNR, ABFLUGDATUM, KNR)
);

/*==============================================================*/
/* Index: BUCHUNG_PK                                            */
/*==============================================================*/
create unique index BUCHUNG_PK on BUCHUNG (
FLUGNR,
ABFLUGDATUM,
KNR
);

/*==============================================================*/
/* Index: BUCHUNG_FK                                            */
/*==============================================================*/
create  index BUCHUNG_FK on BUCHUNG (
FLUGNR,
ABFLUGDATUM
);

/*==============================================================*/
/* Index: BUCHUNG2_FK                                           */
/*==============================================================*/
create  index BUCHUNG2_FK on BUCHUNG (
KNR
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
/* Table: PASSAGIER                                             */
/*==============================================================*/
create table PASSAGIER (
   KNR                  INT8                 not null,
   VORNAME              VARCHAR(255)         not null,
   NACHNAME             VARCHAR(255)         not null,
   BONUSMEILEN          INT8                 null default 0,
   constraint PK_PASSAGIER primary key (KNR)
);

/*==============================================================*/
/* Index: PASSAGIER_PK                                          */
/*==============================================================*/
create unique index PASSAGIER_PK on PASSAGIER (
KNR
);

/*==============================================================*/
/* Table: VERBINDUNG                                            */
/*==============================================================*/
create table VERBINDUNG (
   FLUGNR               VARCHAR(10)          not null,
   ZIEL                 VARCHAR(3)           not null,
   START                VARCHAR(3)           not null,
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
ZIEL
);

/*==============================================================*/
/* Index: ZIEL_FK                                               */
/*==============================================================*/
create  index ZIEL_FK on VERBINDUNG (
START
);

/*==============================================================*/
/* Table: WARTUNG                                               */
/*==============================================================*/
create table WARTUNG (
   KENNZEICHEN          VARCHAR(10)          not null,
   ABFERTIGUNGSDATUM    DATE                 not null,
   FREIGABE             BOOL                 null,
   constraint PK_WARTUNG primary key (KENNZEICHEN, ABFERTIGUNGSDATUM)
);

/*==============================================================*/
/* Index: WARTUNG_PK                                            */
/*==============================================================*/
create unique index WARTUNG_PK on WARTUNG (
KENNZEICHEN,
ABFERTIGUNGSDATUM
);

/*==============================================================*/
/* Index: WIRD_GEWARTET_FK                                      */
/*==============================================================*/
create  index WIRD_GEWARTET_FK on WARTUNG (
KENNZEICHEN
);

alter table ABFLUG
   add constraint FK_ABFLUG_FLIEGT_FLUGZEUG foreign key (KENNZEICHEN)
      references FLUGZEUG (KENNZEICHEN)
      on delete restrict on update restrict;

alter table ABFLUG
   add constraint FK_ABFLUG_HAT_VERBINDU foreign key (FLUGNR)
      references VERBINDUNG (FLUGNR)
      on delete restrict on update restrict;

alter table BUCHUNG
   add constraint FK_BUCHUNG_BUCHUNG_ABFLUG foreign key (FLUGNR, ABFLUGDATUM)
      references ABFLUG (FLUGNR, ABFLUGDATUM)
      on delete restrict on update restrict;

alter table BUCHUNG
   add constraint FK_BUCHUNG_BUCHUNG2_PASSAGIE foreign key (KNR)
      references PASSAGIER (KNR)
      on delete restrict on update restrict;

alter table VERBINDUNG
   add constraint FK_VERBINDU_START_FLUGHAFE foreign key (ZIEL)
      references FLUGHAFEN (IATA)
      on delete restrict on update restrict;

alter table VERBINDUNG
   add constraint FK_VERBINDU_ZIEL_FLUGHAFE foreign key (START)
      references FLUGHAFEN (IATA)
      on delete restrict on update restrict;

alter table WARTUNG
   add constraint FK_WARTUNG_WIRD_GEWA_FLUGZEUG foreign key (KENNZEICHEN)
      references FLUGZEUG (KENNZEICHEN)
      on delete restrict on update restrict;

