#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));

    int health_robot=50, health_kecoak=20;              // Health awal robot dan kecoak
    int d=5;
    int damage_robot=rand()%d, damage_kecoa=rand()%d;   // Damage awal tembakan robot dan kecoak (random)
    int kecoak=1, kecoak_killed=0;                      // Jumlah kecoak dan yang terbunuh
    int a, b;

    //Batas koordinat
    int m, n;
    printf("Koordinat battlefield: m x n\nm: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    int koor[m][n];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            koor[i][j]=0;
        }
    }

    // Koordinat awal robot
    int Xr=0, Yr=0;
    koor[m-1-Yr][Xr]=7; // Robot di peta adalah angka 7

    // Spawn kecoak random
    int Xk, Yk;
    while (kecoak>0){
        Xk = rand() % n; 
        Yk = rand() % m;
        if (Xk!=0 && Yk!=m-1){
            if (koor[Yk][Xk]==0){
                koor[Yk][Xk]=8;
                kecoak = kecoak - 1;
            }
        }
    }

    // Peta awal
    printf("\n===PETA AWAL ROBOT DAN KECOAK===\n");
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%d ", koor[i][j]);
        }
        printf("\n");
    }
    printf("\n===STATUS ROBOT DAN KECOAK===\n");
    printf("Health robot: %d\n", health_robot);
    printf("Health kecoak: %d\n", health_kecoak);


    while (health_robot>0){
        // BUAT DETECTOR BELUM GAISSSSSSSSSS


        // Komando robot bergerak atau menembak
        printf("\n===COMMAND===");
        printf("\n1. Bergerak\n2. Menembak\nApakah robot akan bergerak atau menembak (masukkan angka)? ");
        scanf("%d", &a);
        koor[m-1-Yr][Xr]=0;
        if (a==1){        // Robot bergerak
            printf("\n===PERGERAKAN===\n");
            printf("1. Maju\n2. Mundur\n3. Kanan\n4. Kiri\nKe arah mana robot akan bergerak (masukkan angka)? ");
            scanf("%d", &b);
            if (b==1){      // Robot maju
                Yr+=1;
            }
            else if (b==2){ // Robot mundur
                Yr-=1;
            }
            else if (b==3){ // Robot ke kanan
                Xr+=1;
            }
            else if (b==4){ // Robot ke kiri
                Xr-=1;
            }
            health_robot-=5;
        }
        else if (a==2){   // Robot menembak
            if ((m-1-Yr) == Yk) { // Robot berada pada 1 garis vertikal dengan kecoak
                if (abs(Xr-Xk) <= 3) { 
                    health_kecoak -= damage_robot;
                }
                else {
                    printf("kecoak diluar jangkauan\n");
                }
            }
            else if (Xk == Xr) {
                if (abs(m-1-Yr-Yk) <= 3) {
                    health_kecoak -= damage_robot;
                }
                else {
                    printf("kecoak diluar jangkauan\n");
                }
            }
            else {
                printf("kecoak diluar jangkauan\n");
            }
            
            // belummm harus buat detector dulu

            health_robot-=5; health_kecoak-=damage_robot;
        }
        else if (a==3) {
            health_robot = 0;
        }
        // Mengupdate Peta
        printf("\n===PETA ROBOT DAN KECOAK===");
        koor[m-1-Yr][Xr]=7;
        printf("\n");
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                printf("%d ", koor[i][j]);       
            }
            printf("\n");
        }

        // Mencetak status health dari robot dan kecoak setelah command
        printf("\n===STATUS ROBOT DAN KECOAK===\n");
        printf("Health robot: %d\n", health_robot);
        printf("Health kecoak: %d\n", health_kecoak);
    }

    // health_robot <= 0
    printf("Health robot telah habis. Permainan selesai!!!\n");
    printf("Jumlah kecoak yang berhasil dibunuh: %d", kecoak_killed);
}
