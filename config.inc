<?php
//stale zmienne zwiazane z aplikacja
//error_reporting(E_ERROR | E_WARNING); //E_ERROR - wyswietla tylko fatal errory
//sciezka przypisane globalnie na stale
define("__URL__", "http://localhost/back/4/stronaWWW/");
//potem moge wywolac to <img src <?php = __URL__ pytajnik>nazwapliku.jpg">
//zmienna wartosc moge nazwac jak chce. ale frameworki czesto tak dzialaja ze sa te podkreslenia

//konfiguracja bazy danych
define("__HOST__", "localhost");
define("__UNAME__", "root"); //tu takie dane bo dodalam nowego uzytkownika w phpmyadmin
//Tworze owego uzytkownika: baza danych / privileges/ add user account
define("__PASSWD__", ""); //wygenerowalam haslo
define("__DB_NAME__", "strona_www");
define("__DB_CHARSET_SET__", "UTF8");
//Koniec konfiguracji bazy danych

 ?>
