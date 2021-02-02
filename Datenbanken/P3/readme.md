# Aufgabenbeschreibung zu den SQL-SELECTs

Diese readme.md dient als **Template** für Ihre SQL-SELECT Statements für Praktikum 3.
 
Nachdem Sie die zusätzlichen Daten (siehe Aufgabenbeschreibung Praktikum 3) in Ihre Datenbank geladen haben und Ihre SQL-SELECT Statements das erwartete Ergebnis (siehe bereitgestellte Lösungen in Moodle) liefern, fügen Sie diese SQL Statements hier in die entsprechenden Felder unter [SQL-SELECT Statements](#sql-select-statements) ein. Diese Statements werden geprüft und Gegenstand des Praktikums sein. 

Die Musterlösungen zu den einzelnen SQL-Statements werden Ihnen ausgehändigt, sodass Sie vor der Einreichung selbst kontrollieren können, ob Ihr Ergebnis korrekt ist. 

<br>

# Zu beachtende Regeln!
Beachten Sie bei der Bearbeitung dieser Aufgabe folgendes:

### Regel Nr. 1 
Formatieren sie die SQL-SELECT Statements so, dass es einfach ist diese zu lesen. Das bedeutet, schreiben Sie die SELECT-Statements **NICHT** in eine einzige Zeile, wie z.B.:    
```sql
SELECT  a.col1, b.col2, AVG(b.col3) AS avg, FROM table_a a, table_b b WHERE a.col1 = b.col2 GROUP BY a.col1, b.col2 ORDER BY avg HAVING (avg > (SELECT max(col1) FROM table_c)); 
```    
    
Schreiben Sie die Statements stattdessen mit den einzelnen SQL Key-Fragmenten (SELECT, FROM, WHERE, etc.) pro Zeile und mit den nötigen Indents (Einrückungen) auf, wie z.B. hier:
```sql
SELECT a.col1, b.col2, AVG(b.col3) AS avg
    FROM table_a a, table_b b
    WHERE a.col1 = b.col2
    GROUP BY a.col1, b.col2
    ORDER BY avg
    HAVING (avg < 
        (SELECT max(col1)
            FROM table_c));       
```  

<br>

### Regel Nr. 2 (WICHTIG!!!)
Machen Sie sich klar, dass Ihr SQL-Statement nicht dadurch automatisch korrekt ist, dass es die gleichen
Ausgaben liefert, wie sie in der Lösung stehen! Ihr Statement sollte die gestellte Frage beantworten, und nicht „rein zufällig“ die gleiche Ausgabe liefern.

Als Beispiel folgende **Aufgabe 0**:<br>
"Für welche Flugnummern haben Passagiere $200 für einen Platz bezahlt?"<br>
Das richtige Ergebnis ist die Projektion von Flugnummer mit dem einzigen Eintrag "**LH-200**". 

Ihre SQL-Abfrage darf **NICHT** folgendermaßen lauten:
```sql
SELECT flugnr
    FROM Buchung
    WHERE flugnr = "LH-200";
``` 
Das wäre eine vollkommen falsche Abfrage mit der zufällig gleichen Ausgabe. Durch solche SQL-Statements gefährden Sie die Erteilung eines Testats enorm! 

Korrekt wäre die Abfrage:
```sql
SELECT flugnr
    FROM Buchung
    WHERE Preis = "$200";
```

Zusätzlich können Sie auch gerne Erklärungen zu Ihren SQL-Select Statements schreiben, um zu erklären was da genau passiert, oder warum Sie sich für diese Query entschieden haben

<br>

Und nun viel Spaß bei der Generierung der SQL-Statements :-)

<br>

# SQL-SELECT Statements

1. Welche Flüge gehen am 01.10.2018?
    ```sql
    SELECT * FROM Abflug WHERE Abflugdatum = '2018-01-10';
    ```
2. Geben Sie Name, Vorname und Flugnummer aller Passagiere aus, die überhaupt Flüge gebucht haben.
    ```sql
    SELECT nachname, vorname, flugnr FROM Buchung INNER JOIN Passagier ON Passagier.knr = Buchung.knr;
    ```
3. Wie 2, jedoch nur für Abﬂüge am 02.10.2018.
    ```sql
    SELECT nachname, vorname, buchung.flugnr from buchung 
	INNER JOIN passagier on passagier.knr = buchung.knr 
	INNER JOIN abflug on abflug.flugnr = buchung.flugnr 
	AND abflug.abflugdatum = buchung.abflugdatum where abflug.abflugdatum = '02.10.2018';
    ```
4.  Geben Sie die Namen (und **nur** die Namen) der Flughäfen an, die von London Heathrow (LHR) aus angeﬂogen werden.
    ```sql
    SELECT flughafen.name from verbindung 
	LEFT JOIN flughafen on flughafen.iata = verbindung.ziel 
	WHERE verbindung.start = 'LHR';
    ```
5. Geben Sie die Gesamtsumme aus, die der Passagier „Michael Roth“ für Tickets ausgegeben hat.
     ```sql
    SELECT SUM(preis) FROM Buchung
	INNER JOIN Passagier ON Passagier.knr = Buchung.knr
	WHERE Passagier.knr = 1;
    ```
   
6. Geben Sie eine nach Anzahl der gebuchten Tickets sortierte Liste mit Namen und Vornamen der Passagiere sowie der Ticktanzahl aus.
     ```sql
    SELECT Passagier.vorname, Passagier.nachname, COUNT(Buchung.knr)as anzahl FROM Buchung 
	INNER JOIN Passagier ON Passagier.knr=Buchung.knr 
	GROUP BY vorname, nachname 
	ORDER BY anzahl DESC, nachname DESC;
    ```

7. Generieren Sie eine Liste, bei der alle Flüge mit der **Anzahl** der Abﬂüge ausgegeben werden. Sortieren Sie die Liste so, dass der Flug mit den meisten Abﬂügen ganz oben steht.
     ```sql
    SELECT flugnr, COUNT(Flugnr)AS Anzahl FROM Abflug GROUP BY flugnr ORDER BY Anzahl DESC;
    ```

8. Schreiben Sie eine Abfrage, welche Flughäfen anzeigt die **gar nicht** angeﬂogen werden.
     ```sql
    SELECT iata FROM Flughafen EXCEPT SELECT ziel FROM Verbindung;
    ```

9. Welche Flughäfen sind von Frankfurt aus nicht mit einem Direktﬂug, sondern lediglich **mit einem Umstieg** zu erreichen?
     ```sql
    SELECT v.ziel FROM Verbindung 
	INNER JOIN Verbindung as v ON Verbindung.ziel = v.start 
	WHERE Verbindung.start = 'FRA' and v.ziel not in 
	(SELECT ziel FROM Verbindung WHERE start = 'FRA') and v.ziel != 'FRA';
    ```

10. Ist es möglich, am 03.10.2018 von Frankfurt (FRA) **über** London (LHR) nach Beijing (PEK) zu ﬂiegen?
    Geben Sie für jede mögliche Verbindung Startdatum, Startﬂughafen, Zwischenlandung, Zielﬂughafen **in jeweils einer Zeile** an.
	(Dabei wird davon ausgegangen, dass Folgeﬂüge am selben Tag noch erreicht werden können) 
    ```sql
    SELECT Abflug.abflugdatum, Verbindung.flugnr, Verbindung.start,  Verbindung.ziel as zwischenstopp, a.abflugdatum, v.flugnr, v.ziel FROM Verbindung 
	INNER JOIN Verbindung as v ON Verbindung.ziel = v.start 
	INNER JOIN Abflug ON Abflug.flugnr = Verbindung.flugnr
	INNER JOIN Abflug AS a ON a.flugnr = v.flugnr
	WHERE Verbindung.start = 'FRA' and v.ziel = 'PEK' and Verbindung.ziel = 'LHR' and Abflug.abflugdatum = '2018-03-10';
    ```

11. Wie viele Passagiere könnten theoretisch (bei voller Auslastung aller geplanten Abﬂüge) am 02.10.2018 von Frankfurt aus transportiert werden?
    ```sql
    SELECT SUM(sitzplatze) FROM Flugzeug
	INNER JOIN Abflug ON Abflug.kennzeichen = Flugzeug.kennzeichen
	INNER JOIN Verbindung ON Verbindung.Flugnr = Abflug.Flugnr
	WHERE abflugdatum = '2018-02-10' AND Verbindung.start = 'FRA';
    ```
12. Geben Sie eine Liste aller Passagiere inklusive aller Flugdaten aus:
    - Nachname
    - Vorname
    - Preis
    - Flugnummer
    - Flugdatum
    - IATA-Code des Startﬂughafens
    - Name des Startﬂughafens
    - IATA-Code des Zielﬂughafens
    - Name des Zielﬂughafens
     ```sql
    SELECT p.nachname, p.vorname, b.preis, b.flugnr, b.abflugdatum, sf.iata AS start, sf.name AS startflughafen, zf.iata AS ziel, zf.name AS zielflughafen 
    FROM Buchung AS b
    INNER JOIN Passagier AS p ON p.knr = b.knr
    INNER JOIN Verbindung AS v ON v.flugnr = b.flugnr 
    INNER JOIN Flughafen AS sf ON sf.iata = v.start
    INNER JOIN Flughafen AS zf ON zf.iata = v.ziel
    ORDER BY p.nachname;
    ```

13. Generieren Sie eine absteigend sortierte Liste, die pro Flugzeugtyp angibt wie viele Passagiere in Summe bei voller Auslastung aller Abﬂüge befördert werden können.
     ```sql
    SELECT typ, SUM(sitzplatze)AS gesamt FROM Flugzeug
	INNER JOIN Abflug ON Abflug.kennzeichen = Flugzeug.kennzeichen
	INNER JOIN Verbindung ON Verbindung.Flugnr = Abflug.Flugnr
	GROUP BY typ
	ORDER BY gesamt DESC;
    ```

14. Welche Flughäfen sind am häuﬁgsten **Ziel** von Flugverbindungen?
     ```sql
    SELECT Flughafen. iata, COUNT(ziel)AS anzahl FROM Verbindung
	INNER JOIN  Flughafen ON Flughafen.iata = Verbindung.ziel
	GROUP BY Flughafen.iata
	ORDER BY anzahl DESC;
    ```




































