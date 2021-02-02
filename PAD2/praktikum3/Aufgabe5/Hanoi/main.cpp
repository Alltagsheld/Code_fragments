#include "hanoitowers.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hanoiTowers w;
    w.show();
    return a.exec();
}
/*Türme von Hanoi mit Qt
 *
Programmieren Sie eine Qt-Anwendung, mit der man das Spiel Die Türme von Hanoi spielen kann. Die Spielregeln finden Sie in Wikipedia. Das Programm soll ungefähr die folgende
Ansicht haben:

In den hier lEEREN Text-Feldern werden die Türme dargestellt. Der Einfachheit halber wird
die Größe der Scheiben durch Zahlen ausgedrückt (je großer die Zahl desto größer die
Scheibe). Wenn Sie die Türme waagerecht darstellen wollen, nehmen Sie das Qt-Objekt
LineEdit, für eine vertikale Darstellung das ListWidget.

Mit den Pfeilen verschiebt man die kleinste Scheibe zum nächsten passenden Turm. Mit
Restart beginnt man das Spiel von Neuem, d.h. alle Scheiben sind in der richtigen Reihenfolge im linken Feld gespeichert, d.h. 3, 2, 1. Mit EXIT wird das Spiel beendet.
Das Spiel soll mit 3 Scheiben gespielt werden können. Wenn Sie mögen, können Sie dafür
sorgen, dass der Benutzer die Zahl der Scheiben beim Start bestimmen kann.

Beim Design muss eine Klasse Tower entwickelt werden, die von einer Klasse Stack erbt.

Zusätzlich zur Klasse Stack werden die Methoden check(int), d.h. Überprüfung ob eine
Scheibe auf den Turm gelegt werden kann, und size() für die Höhe des Turms, zur Verfügung gestellt. Zum Befüllen der Text-Felder wird außerdem eine Methode at(int) benötigt,
die auf die einzelnen Elemente des Turms zugreift. Push() darf nur verwendet werden,wenn es zur Größe der verwendeten Scheiben passt.
Viele Spaß beim Spielen!
Hinweis: Wenn Sie überhaupt keine Möglichkeit haben, eine GUI mit Qt zu entwickeln, dürfen Sie auch eine GUI mit einem anderen Framework erstellen, oder nur mit Terminalausgaben arbeiten.*/
