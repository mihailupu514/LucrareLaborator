/* Lupu Catalin Mihai compilator c++14 */
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Candidat {
protected:
    int index;
    string Cod_legitimatie;
    double proba1;
    double proba2;
    double proba3;
public:
    int getIndex() const {
        return index;
    }

    void setIndex(int index) {
        Candidat::index = index;
    }

    const string &getCodLegitimatie() const {
        return Cod_legitimatie;
    }

    void setCodLegitimatie(const string &codLegitimatie) {
        Cod_legitimatie = codLegitimatie;
    }

    double getProba1() const {
        return proba1;
    }

    void setProba1(double proba1) {
        Candidat::proba1 = proba1;
    }

    double getProba2() const {
        return proba2;
    }

    void setProba2(double proba2) {
        Candidat::proba2 = proba2;
    }

    double getProba3() const {
        return proba3;
    }

    void setProba3(double proba3) {
        Candidat::proba3 = proba3;
    }

};

class FisaInscriere : public Candidat {
public:
    FisaInscriere(const string &nume, const string &prenume, double medieBac, bool facultatePrecedenta,
                  const string &facultate1, double medieFacultate1, int optiuni, bool programStudiu,
                  double medieAdmitere) : nume(nume), prenume(prenume), medie_bac(medieBac),
                                          facultate_precedenta(facultatePrecedenta), Facultate1(facultate1),
                                          medie_facultate1(medieFacultate1), optiuni(optiuni),
                                          ProgramStudiu(programStudiu), Medie_admitere(medieAdmitere) {}
FisaInscriere(){
        nume="";
        prenume="";
        medie_bac=0;
        optiuni=0;
        medie_facultate1=0;
        Medie_admitere=0;
    }

    virtual ~FisaInscriere() {

    }

protected:
    string nume;
    string prenume;
    double medie_bac;
    bool facultate_precedenta;
    string Facultate1;
    double medie_facultate1;
    int optiuni;
    bool ProgramStudiu; //true-IF false-ID
    double Medie_admitere;
public:
    double getMedieAdmitere() const {
        return Medie_admitere;
    }

    void setMedieAdmitere(double medieAdmitere) {
        Medie_admitere = medieAdmitere;
    }

    bool isProgramStudiu() const {
        return ProgramStudiu;
    }

    void setProgramStudiu(bool programStudiu) {
        ProgramStudiu = programStudiu;
    }

    int getOptiuni() const {
        return optiuni;
    }

    void setOptiuni(int optiuni) {
        FisaInscriere::optiuni = optiuni;
    }

    const string &getNume() const {
        return nume;
    }

    void setNume(const string &nume) {
        FisaInscriere::nume = nume;
    }

    const string &getPrenume() const {
        return prenume;
    }

    void setPrenume(const string &prenume) {
        FisaInscriere::prenume = prenume;
    }

    double getMedieBac() const {
        return medie_bac;
    }

    void setMedieBac(double medieBac) {
        medie_bac = medieBac;
    }

    bool isFacultatePrecedenta() const {
        return facultate_precedenta;
    }

    void setFacultatePrecedenta(bool facultatePrecedenta) {
        facultate_precedenta = facultatePrecedenta;
    }

    const string &getFacultate1() const {
        return Facultate1;
    }

    void setFacultate1(const string &facultate1) {
        Facultate1 = facultate1;
    }

    double getMedieFacultate1() const {
        return medie_facultate1;
    }

    void setMedieFacultate1(double medieFacultate1) {
        medie_facultate1 = medieFacultate1;
    }


};

class Facultate {
protected:
    string denumire;
public:
    const string &getDenumire() const {
        return denumire;
    }

    void setDenumire(const string &denumire) {
        Facultate::denumire = denumire;
    }
};

class Admitere : public Facultate {
protected:
    int numar_total;
    int numar_locuri_IF;
    int numar_locuri_ID;
public:
    int getNumarTotal() const {
        return numar_total;
    }

    void setNumarTotal(int numarTotal) {
        numar_total = numarTotal;
    }

    int getNumarLocuriIf() const {
        return numar_locuri_IF;
    }

    void setNumarLocuriIf(int numarLocuriIf) {
        numar_locuri_IF = numarLocuriIf;
    }

    int getNumarLocuriId() const {
        return numar_locuri_ID;
    }

    void setNumarLocuriId(int numarLocuriId) {
        numar_locuri_ID = numarLocuriId;
    }


};

int main() {
    Facultate X;
    Admitere admitere2020;
    X.setDenumire("Facultatea de Matematica si Informatica");
    admitere2020.setNumarTotal(100);
    admitere2020.setNumarLocuriIf(0.8 * admitere2020.getNumarTotal());
    admitere2020.setNumarLocuriId(0.2 * admitere2020.getNumarTotal());
    Candidat candidat2020[100];
    FisaInscriere f2020[100];
    int counter = 0;
    int operatie = -1;

    while (operatie != 0) {
        cout
                << "Operatia dorita: \n1. Adaugare candidat \n2.Afisare numar si liste \n3.Afisare liste Admisi dupa Medie \n4.Afisare lista admisi pasaport";
        cin >> operatie;
        switch (operatie) {
            case 1: {
                counter++;
                f2020[counter].setIndex(counter);
                string nume;
                cout << "\nNumele Candidatului:";
                cin >> nume;
                f2020[counter].setNume(nume);
                cout << "\nPrima sau a 2 a facultate: 1.Prima 2.A 2 a(nu e implementat)";
                int alegere;
                cin >> alegere;
                if (alegere == 1)
                    f2020[counter].setFacultatePrecedenta(false);
                else
                    f2020[counter].setFacultatePrecedenta(true);
                cout << "\nOptiunile Candidatului : 1.Un singur domeniu 2.Mai multe domenii";
                cin >> alegere;
                if (alegere == 1) {

                    f2020[counter].setOptiuni(1);
                } else {
                    f2020[counter].setOptiuni(2);
                }
                if (f2020[counter].getOptiuni() == 1) {
                    cout << "\nCe program de studiu ? 1.IF 2.ID";
                    cin >> alegere;
                    if (alegere == 1) {
                        f2020[counter].setProgramStudiu(true);

                    } else
                        f2020[counter].setProgramStudiu(false);
                    if (f2020[counter].isProgramStudiu() == true) {
                        cout << "\nNota Proba Scrisa:";
                        cin >> alegere;
                        f2020[counter].setProba1(alegere);
                        cout << "\nNota Medie Bacalaureat";
                        cin >> alegere;
                        f2020[counter].setMedieBac(alegere);
                        f2020[counter].setMedieAdmitere(
                                floor(f2020[counter].getProba1() * 0.8 + f2020[counter].getMedieBac() * 0.2));
                    }
                    if (f2020[counter].isProgramStudiu() == false) {
                        cout << "\nNota Proba Orala:";
                        cin >> alegere;
                        f2020[counter].setProba2(alegere);
                        cout << "\nNota Matematica Bacalaureat";
                        cin >> alegere;
                        f2020[counter].setProba3(alegere);
                        f2020[counter].setMedieAdmitere(
                                floor(f2020[counter].getProba2() * 0.6 + f2020[counter].getProba3() * 0.4));

                    }
                }
                if (f2020[counter].getOptiuni() == 2) {
                    cout << "\nNota Proba Scrisa:";
                    cin >> alegere;
                    f2020[counter].setProba1(alegere);
                    cout << "\nNota Medie Bacalaureat";
                    cin >> alegere;
                    f2020[counter].setMedieBac(alegere);
                    f2020[counter].setMedieAdmitere(
                            floor(f2020[counter].getProba1() * 0.8 + f2020[counter].getMedieBac() * 0.2));
                    cout << "\nNota Proba Orala:";
                    cin >> alegere;
                    f2020[counter].setProba2(alegere);
                    cout << "\nNota Matematica Bacalaureat";
                    cin >> alegere;
                    f2020[counter].setProba3(alegere);
                    f2020[counter].setMedieAdmitere(
                            floor(f2020[counter].getProba2() * 0.6 + f2020[counter].getProba3() * 0.4));
                }

                break;
            }
            case 2: {
                cout << "Numar total candidati:" << counter;
                cout << endl;
                cout << "Domeniu IF-Prima facultate:";
                cout << endl;
                for (int i = 0; i < counter; i++) {
                    if (f2020[counter].isProgramStudiu() == true) {
                        cout << "Denumire:" << f2020[i].getNume() << " Medie Admitere:" << f2020[i].getMedieAdmitere();
                        cout << endl;
                    }
                }
                cout << "Domeniu ID-Prima facultate:";cout<<endl;
                for (int i = 0; i < counter; i++) {
                    if (f2020[counter].isProgramStudiu() == true) {
                        cout << "Denumire:" << f2020[i].getNume() << " Medie Admitere:" << f2020[i].getMedieAdmitere();
                        cout << endl;
                    }
                }
                break;
            }
            case 3:{
                cout<<"nu e implementat";
            }
            case 4:{
                cout<<"nu e implementat";
            }
        }
    }
    return 0;
}