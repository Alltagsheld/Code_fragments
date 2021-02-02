ALTER TABLE buchung ADD CONSTRAINT preis_limit CHECK (preis < CAST(1000 AS money));
-- Test Case Fails: Insert into buchung (knr, flugnr, abflugdatum, preis) VALUES (5, 'LH-102', '2019-04-10', 1100);
-- Test Case Success: Insert into buchung (knr, flugnr, abflugdatum, preis) VALUES (5, 'LH-102', '2019-04-10', 100);

ALTER TABLE flugzeug ADD CONSTRAINT keine_leeren_flugzeuge CHECK (sitzplatze > 0);
-- Tet Case Fails: INSERT INTO flugzeug (kennzeichen, typ, sitzplatze) VALUES ('D-ABVD', 'Airbus A330-302', -12); 
-- Tet Case Success: INSERT INTO flugzeug (kennzeichen, typ, sitzplatze) VALUES ('D-ABVD', 'Airbus A330-302', 12); 

ALTER TABLE flugzeug ALTER COLUMN sitzplatze SET DEFAULT 100;
-- Test Case Success: INSERT INTO flugzeug (kennzeichen, typ) VALUES ('D-AB', 'Airbus A330-302');