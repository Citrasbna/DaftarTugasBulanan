#include <stdio.h>

int main() {
    int hariSekarang; //menyimpan tanggal hari ini
    int jumlahTugas; //menyimpan jumlah tugas yang akan di input
    int angkaBulan; //menyimpan angka untuk bulan
    char tugas[10][50]; //array 2 dimensi dengan maksimal menginput 10 tugas dengan masing-masing 50 karakter
    int deadline[10]; //menyipan deadline sesuai jumlah tugas

    printf("== SELAMAT DATANG di DAFTAR TUGAS BULANAN ==\n");

    char bulan[12][10] = {
        "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"
    }; //array menyimpan 12 bulan dengan masing-masing 10 karakter

    // Input bulan
    printf("Bulan ke-berapa sekarang : ");
    scanf("%d", &angkaBulan);
    while (angkaBulan > 12 || angkaBulan <= 0){ //menggunakan loop while, jika menginput tidak diantara 1-12 maka diminta input ulang
        printf("Angka bulan tidak tersedia, coba input ulang\n");
        printf("Bulan ke-berapa sekarang : ");
        scanf("%d", &angkaBulan);
    }
    
    // Input tanggal hari ini
    printf("Masukan Tanggal hari ini (1 - 31) : ");
    scanf("%d", &hariSekarang);
    while (hariSekarang >= 32 || hariSekarang <= 0){// menggunakan loop while, jika menginput tidak diantara 1-31 maka diminta input ulang
        printf("tanggal tidak ada, coba input ulang\n");
        printf("Masukan Tanggal hari ini (1 - 31) : ");
        scanf("%d", &hariSekarang);
    }
    
    // Input jumlah tugas
    printf("Mau memasukan berapa tugas (maksimal 10): ");
    scanf("%d", &jumlahTugas);
    while(jumlahTugas > 10 || jumlahTugas <= 0){ //menggunakan loop while, jika menginput tidak diantara 1-10 maka diminta input ulang
        printf("maaf terlalu banyak, input ulang ya\n");
        printf("Mau memasukan berapa tugas (maksimal 10): ");
        scanf("%d", &jumlahTugas);
    }
    getchar(); // menghapus newline, agar enter selanjutnya tidak terbaca kosong
    
    // Input tugas dan deadline
    for (int i = 0; i < jumlahTugas; i++) { //mengulang jumlah tugas yang akan di input
        printf("Masukan tugas ke-%d : ", i + 1);
        scanf("%[^\n]", tugas[i]); //untuk membaca teks yang mengandung spasi
        getchar(); // menghapus newline, agar enter selanjutnya tidak terbaca kosong

        printf("Tanggal Deadline (1-31) : ");
        scanf("%d", &deadline[i]);
        while (deadline[i] >= 32 || deadline[i] <= 0) { // menggunakan loop while, jika menginput tidak diantara 1-31 maka diminta input ulang
            printf("tanggal tidak ada, coba input ulang  \n");
            printf("Tanggal Deadline (1-31) : ");
            scanf("%d", &deadline[i]);
        }
        getchar(); // menghapus newline, agar enter selanjutnya tidak terbaca kosong
    } 

    // Tampilkan daftar tugas yang di input
    printf("\n-- Daftar Tugas Kamu di Bulan %s --\n", bulan[angkaBulan - 1]); // angka bulan dikurang satu karena indeks dimulai dari 0

    for (int i = 0; i < jumlahTugas; i++) {
        int selisih = deadline[i] - hariSekarang; //menghitung selisih deadline dengan angka hari yang dimasukan
        printf("\n%d. %s\n", i + 1, tugas[i]); // menampilkan nomor dan nama tugas

        if (selisih > 0) {
            printf("Deadline : %d hari lagi\n", selisih);
            printf("Semangat, yuk di cicil dari sekarang\n");
        } else if (selisih == 0) {
            printf("Hari ini deadline-nya, yuk segera dikerjakan\n");
        } else {
            printf("Yahh, deadline-nya udah lewat %d hari yang lalu\n", -selisih);
        } //kondisional untuk mengecek status deadline
    }

    return 0;
}
