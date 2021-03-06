--Flughäfen--
DELETE FROM buchung;
DELETE FROM abflug;
DELETE FROM verbindung;
DELETE FROM flughafen;
DELETE FROM wartung;
DELETE FROM flugzeug;
DELETE FROM passagier;


INSERT INTO flughafen (iata, name, langengrad, breitengrad) VALUES  ('ATL', 'Hartsfield-Jackson International Airport Atlanta', '-84.428056', '33.636667'),
                                                                    ('PEK', 'Beijing Capital International Airport', '116.5975', '40.0725'),
                                                                    ('DXB', 'Dubai International Airport', '55.364444', '25.252778'),
                                                                    ('ORD', 'Chicago O Hare International Airport', '-87.904722', '41.978611'),
                                                                    ('HND', 'Tokyo International Airport', '139.781111', '35.553333'),
                                                                    ('LHR', 'Heathrow Airport',  '-0.461389', '51.4775'),
                                                                    ('LAX', 'Los Angeles International Airport','-118.408056', '33.9425'),
                                                                    ('HKG', 'Hong Kong International Airport', '113.914444', '22.308889'),
                                                                    ('CDG', 'Paris Charles de Gaulle Airport', '2.547778', '49.009722'),
                                                                    ('DFW', 'Dallas International Airport' , '-97.038056', '32.896944'),
                                                                    ('FRA', 'Frankfurt Airport ', '8.570556', '50.033333'),
                                                                    ('IST', 'Istanbul Atatürk Airport', '28.814167', '40.976111'),
                                                                    ('WDH', 'Hosea Kutako International Airport', '17.47095', '-22.479894');


 INSERT INTO flugzeug (kennzeichen, typ, sitzplatze) VALUES ('D-ABBB', 'Airbus A330-300', 236),
                                                            ('D-ABBC', 'Airbus A330-300', 240),
                                                            ('D-ABBD', 'Airbus A330-300', 221),
                                                            ('D-ABBE', 'Airbus A330-300', 231),
                                                            ('D-ABBF', 'Airbus A340-300', 280),
                                                            ('D-ABBG', 'Airbus A340-300', 271),
                                                            ('D-ABBH', 'Airbus A340-300', 243),
                                                            ('D-ABBI', 'Airbus A340-600', 266),
                                                            ('D-ABBK', 'Airbus A340-600', 293),
                                                            ('D-ABBL', 'Airbus A380-800', 509),
                                                            ('D-ABBM', 'Airbus A350-900', 293),
                                                            ('D-ABBO', 'Airbus A350-900', 297),
                                                            ('D-ABBP', 'Airbus A350-900', 288),
                                                            ('D-ABBQ', 'Airbus A350-900', 288),
                                                            ('D-ABBR', 'Airbus A320-200', 168),
                                                            ('D-ABBS', 'Airbus A320-200', 168),
                                                            ('D-ABBT', 'Airbus A320-200', 170),
                                                            ('D-ABBU', 'Airbus A320-200', 142),
                                                            ('D-ABBW', 'Boeing B747-8'  , 364),
                                                            ('D-ABBX', 'Boeing B747-8'  , 364),
                                                            ('D-ABBY', 'Boeing B747-8'  , 364),
                                                            ('D-ABBZ', 'Boeing B747-8'  , 364),
                                                            ('D-ABCA', 'Boeing B737-700',  86),
                                                            ('D-ABCC', 'Boeing B737-700',  88);

 INSERT INTO verbindung (flugnr, ziel, start) VALUES    ('LH-100', 'ATL', 'FRA'),
                                                        ('LH-102', 'DXB', 'FRA'),
                                                        ('LH-103', 'ORD', 'FRA'),
                                                        ('LH-104', 'HND', 'FRA'),
                                                        ('LH-105', 'LHR', 'FRA'),
                                                        ('LH-106', 'LAX', 'FRA'),
                                                        ('LH-107', 'HKG', 'FRA'),
                                                        ('LH-108', 'CDG', 'FRA'),
                                                        ('LH-109', 'DFW', 'FRA'),
                                                        ('LH-110', 'IST', 'FRA'),
                                                        ('LH-200', 'ATL', 'LHR'),
                                                        ('LH-201', 'PEK', 'LHR'),
                                                        ('LH-202', 'DXB', 'LHR'),
                                                        ('LH-203', 'ORD', 'LHR'),
                                                        ('LH-204', 'FRA', 'LHR');

 INSERT INTO abflug (flugnr, abflugdatum, kennzeichen) VALUES   ('LH-100', '2018-01-10', 'D-ABBL'),
                                                                ('LH-100', '2018-02-10', 'D-ABBL'),
                                                                ('LH-100', '2018-03-10', 'D-ABBL'),
                                                                ('LH-100', '2018-04-10', 'D-ABBL'),
                                                                ('LH-100', '2018-05-10', 'D-ABBL'),
                                                                ('LH-100', '2018-06-10', 'D-ABBL'),
                                                                ('LH-100', '2018-07-10', 'D-ABBK'),
                                                                ('LH-100', '2018-08-10', 'D-ABBK'),
                                                                ('LH-102', '2018-02-10', 'D-ABBB'),
                                                                ('LH-102', '2018-04-10', 'D-ABBB'),
                                                                ('LH-102', '2018-06-10', 'D-ABBB'),
                                                                ('LH-103', '2018-09-10', 'D-ABBB'),
                                                                ('LH-104', '2018-03-10', 'D-ABBB'),
                                                                ('LH-104', '2018-05-10', 'D-ABBB'),
                                                                ('LH-104', '2018-07-10', 'D-ABBB'),
                                                                ('LH-104', '2018-09-10', 'D-ABBB'),
                                                                ('LH-105', '2018-01-10', 'D-ABBB'),
                                                                ('LH-105', '2018-02-10', 'D-ABBB'),
                                                                ('LH-105', '2018-03-10', 'D-ABBB'),
                                                                ('LH-200', '2018-01-10', 'D-ABCA'),
                                                                ('LH-200', '2018-02-10', 'D-ABCA'),
                                                                ('LH-201', '2018-03-10', 'D-ABCA'),
                                                                ('LH-201', '2018-05-10', 'D-ABBR'),
                                                                ('LH-202', '2018-05-10', 'D-ABCA'),
                                                                ('LH-202', '2018-09-10', 'D-ABCA'),
                                                                ('LH-203', '2018-04-10', 'D-ABCA'),
                                                                ('LH-203', '2018-05-10', 'D-ABCA'),
                                                                ('LH-203', '2018-06-10', 'D-ABCC'),
                                                                ('LH-204', '2018-01-10', 'D-ABBF'),
                                                                ('LH-204', '2018-03-10', 'D-ABBI'),
                                                                ('LH-204', '2018-08-10', 'D-ABBM');

 INSERT INTO passagier (knr, nachname, vorname, bonusmeilen) VALUES (1, 'Roth', 'Michael', 0),
                                                                    (2, 'Schestag ', 'Inge', 0),
                                                                    (3, 'Störl', 'Uta', 0),
                                                                    (4, 'Muth', 'Peter', 0),
                                                                    (5, 'Peter', 'Thorsten', 0),
                                                                    (6, 'Ruehl', 'Stefan', 0);

 INSERT INTO buchung (knr, flugnr, abflugdatum, preis) VALUES   (1, 'LH-100', '2018-01-10', 100),
                                                                (5, 'LH-102', '2018-04-10', 100),
                                                                (6, 'LH-104', '2018-07-10', 100);
