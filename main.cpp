#include <iostream>
using namespace std;
int main() {
    string c;
    int budgetIniziale;

    cout << "inserisci un budget iniziale" << endl;
    cin >> budgetIniziale;
    do {
        c = leggiComando();
        if (c == "R") {
            budgetIniziale = raccoltaFondi(budgetIniziale);
        }
        if (c == "P") {
            previsioneBudget(budgetIniziale);
        }
        if (c == "S") {
            budgetIniziale = spesaImprevista(budgetIniziale);
        }
    } while (c != "X");
    cout << "Torna presto" << endl;
    return 0;
}

string leggiComando() {
    string c;

    do {
        cout << "[R]accolta fondi | [P]revisione del budget | [S]pesa imprevista | [X]esce dal programma" << endl;
        cin >> c;
    } while (c != "R" && c != "P" && c != "S" && c != "X");
    
    return c;
}

void previsioneBudget(int budget) {
    int percentuale, variazione;

    percentuale = rand() % 31 - 10;
    variazione = budget * (percentuale / 100);
    budget = budget + variazione;
    cout << "Il budget è diventato: " << budget << endl;
}

int raccoltaFondi(int budget) {
    int raccolta, budgetIniziale;

    cout << "Con quanti soldi vuoi contribuire?" << endl;
    cin >> raccolta;
    budgetIniziale = budget + raccolta;
    cout << "Nuovo budget dopo raccolta fondi: " << budgetIniziale << endl;
    
    return raccolta;
}

int spesaImprevista(int budget) {
    int budgetIniziale, imprevisto;

    cout << "Quanti soldi sono necessari per risolvere questo problema?" << endl;
    cin >> imprevisto;
    if (imprevisto > budget) {
        budgetIniziale = 0;
    } else {
        budgetIniziale = budget - imprevisto;
    }
    cout << "Nuovo budget dopo spesa imprevista: " << budgetIniziale << endl;
    
    return imprevisto;
}
