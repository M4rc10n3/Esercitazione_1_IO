#include <fstream>  //necessaria per leggere i file 
#include <iostream>  //necessaria per maneggiare input/output 

// Andiamo a dichiarare e definire la funzione. Per definirla solo si può scrivere:
// unsigned int sum_values(const unsigned int &N)
// Ciò che viene dopo, nel corpo, definisce la funzione e le dà le istruzioni da seguire; se le funzioni saranno nell'header
// va incluso l'header nel CMakeLists.txt
unsigned int sum_values(const unsigned int &N) //"const" indica che N non è modificabile e 
// "&" dà il riferimento al valore, non una copia del valore stesso, così da evitare problemi di memoria.
{
    return N * (N+1) * (2 * N + 1) / 6; 
    // rapporti tra "unsigned int" danno un "unsigned int" anche se nell'output specifico il tipo "double"
    // per ottenere un "double", specificare "double" nell'output e scrivere così:
    // return N * (N+1) * (2 * N + 1) / 6.0;
}


int main()
{
    std::ifstream fstr("data.txt"); //ifstream è il tipo di un file per input, fstr è il nome della variabile file aperto
    //modo equivalente per scrivere tale istruzione è aprire il file e poi associarlo a una variabile, così
    //fstr.open("data.txt");

    // il file potrebbe non esistere nella posizione data oppure potremmo non avere i permessi per aprirlo
    if(fstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    std::string tmp;
    std::getline(fstr, tmp); //stream che prende come input la variabile in cui è salvato il file 
                            // e la stringa in cui salvarne la linea
    std::cout << tmp << std::endl;

    // Scriviamo qualcosa che manda in pappa il programma che stamperà un valore pazzurello al posto di -1
    //unsigned int i = -1;
    //std::cout << "i = " << i << std::endl;

    // non sappiamo quante righe ci sono nel file, quindi è meglio usare un ciclo while. 
    // Ricordarsi che se la lettura della riga fallisce, lo stato dell'oggetto fstr cambia 
    // e non si può più fare nulla con esso se non lo si riapre.
    unsigned int sum = 0;
    unsigned int val; // usiamo "unsigned int" così da avere più numeri interi possibili
    unsigned int n = 0;
    while(fstr >> val) // usando l'operatore >> non dobbiamo controllare se la stringa è vuota o con caratteri speciali, 
    // perché getline() prende riga per riga come una stringa; lo stream non lo fa.
    {
        sum += val * val; // scriviamo la potenza così perché pow() è più costoso; se le potenze sono piccole e intere,
        n++;
    }
    
    unsigned int S = sum_values(n);
    std::cout << "Sum done by hand = " << sum << std::endl;
    std::cout << "Sum calculated with the function = " << S << std::endl;

    return 0;
}
