# SoalShift_modul2_D04
## Soal1
1.	Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.
```
code1
  char *temp;
  int length, length2, i;
  char *namaBaru = "_grey.png";
  char buffer[100] = "";
  char buffer2[100] = "";
  DIR *dir;
  struct dirent *rent;
  dir = opendir(".");
  if(dir != NULL){
        while((rent = readdir(dir)) != NULL){
                length = strlen(rent->d_name);
                if(rent->d_name[length-4] == '.' && rent->d_name[length-3] == 'p' && rent->d_name[length-2] == 'n' && rent->d_name[length-1] == 'g'){
                        strcpy(buffer, rent->d_name);
                        strcpy(buffer2, rent->d_name);
                        char direktori2[100] = "/home/nanta/modul2/gambar/";
                        length2 = strlen(buffer);
                        buffer[length2-4]='\0';
                        strcat(buffer, namaBaru);
                        strcat(direktori2, buffer);
                        rename(buffer2, direktori2);
                }
        }
        closedir(dir);
```

## Soal2
2.	Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab
```
code2
 char *direktori="/home/nanta/Downloads/Sisop-modul2/Soal_Shift_Modul_2/hatiku/elen.ku";
    char *nama="www-data";
    struct stat info;
    chmod (direktori, 777);
    //char *elen = "elen.ku";
    //strcat(direktori, elen);
    stat(direktori, &info);  // Error check omitted
    struct passwd *ow = getpwuid(info.st_uid);
    struct group  *gr = getgrgid(info.st_gid);
    if(strcmp(ow->pw_name,nama)==0 && strcmp(gr->gr_name,nama)==0)
      remove(direktori);
    sleep(3);
```

## Soal3
3.	Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :
i)  mengekstrak file zip tersebut.
ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 
Catatan:  
○	Gunakan fork dan exec.
○	Gunakan minimal 3 proses yang diakhiri dengan exec.
○	Gunakan pipe
○	Pastikan file daftar.txt dapat diakses dari text editor
```
code3

```

## Soal4
4.	Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 
-	dilarang menggunakan crontab
-	Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst
```
code4
```

## Soal5
5.	Kerjakan poin a dan b di bawah:
a.	Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:
-	Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
-	Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1
b.	Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.
```
code5
```
