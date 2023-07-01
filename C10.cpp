/*  Toms Madžuls, tm22005
    C10. Doti naturāli skaitļi n un a(1), a(2), ... a(n). Atrast minimālo no dotajiem saliktajiem skaitļiem 
    (t.i., tādiem, kas nav pirmskaitļi).
    Programma izveidota: 14.10.2022 */

#include <iostream>
#include <vector>       //tiek izmantots vektors, var izmantot ari dinamisko masivu
using namespace std;


bool salikts(int a){
 int i = 1;
 int count = 0;

 while(a >= i){
  if(a % i == 0)        //skaitlis tiks dalits ar visiem sk., kas mazaki par to
    count++;            //skaita dalitaju skaitu
    i++;
 }

 if(count > 2)          //ja skaitlis perfekti dalas ar vairak ka 2 dalitajiem, tad tas ir salikts sk.
    return true;
 else
    return false;
}

int main() {
    char izvele;        //defineti mainigie
    int N, a;
    vector <int> v;     //definets vektors "v"

    do{
        cout << "Ievadiet N: ";
        cin >> N;

        while (N < 1){
            cout  <<"Ievadiet N vismaz 1: ";                 //kamer lietotajs ievadis N < 1, tikmer jautas atkaroti
            cin >> N;
        }

        for (int i = 1; i < N+1; i++){                       //for loop jautas ievadit skaitli tik reizes, cik lietotajs noradija N
            cout << "Ievadiet skaitli a(" << i << "): ";
            cin >> a;

            if (a > 0){                                     //ja ievadits naturals sk, tad izsauc f-ju salikts()
                if (salikts(a))                             //ja ievadits naturals sk. un tam ir >2 dalitajiem, tad
                    v.push_back(a);                         //nosuta elementu uz vektora beigam
            }else{                                          //citadak jauta ievadit atkartoti naturalu sk.
                while (a <= 0){
                    cout << "Ievadiet naturalu skaitli!" << endl;
                    cout << "Ievadiet skaitli a(" << i << "): ";
                    cin >> a;
                }
            }
        }
        cout << "Saliktie skaitli: ";
        for (int i = 0; i < v.size(); i++){                 //kamer i bus mazaks par vektora izmeru, notiks for loop
            cout << v[i] << " ";                            //iziet cauri vektora elementiem
        }
        
        cout << endl << "Minimalais no skaitliem: " << *min_element(v.begin(), v.end()); //atgriez mazako elementu, skatas no vektora sakuma lidz beigam
        cout << endl << "Vai turpinat? y/n" << endl;
        cin >> izvele;
        v.clear();      //notira vektoru atkartotai izpildei
    }while (izvele == 'y');
    return 0;
} 