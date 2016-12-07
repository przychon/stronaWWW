<?php
require 'config.inc'; //inc mozna zablokowac otworzenie
include 'lib/function.inc';
require 'lib/db_connect.inc';
require 'lib/aktualnosci.inc';
require 'lib/galeria.inc';

//TESTY:

//debug($_SERVER);
//debug($_GET);

//echo __URL__;
//echo __HOST__;
//echo __UNAME__;
//echo __PASSWD__;
//echo __DB_NAME__;

$connectDB = connectDB(__HOST__, __UNAME__, __PASSWD__, __DB_NAME__, __DB_CHARSET_SET__);

//ZMieniam to ponizej zeby uzyc filter
/*if(isset($_GET["action"]) && ($_GET['action'] == "add_new")){
  addNew($connectDB, $_POST); //$_POST przejda informacje przeslane z formularza
};
*/
//TO SAMO CO WYZEJ INACZEJ. ZALECANE BO BEZPIECZNIEJSZE. bez isset
/*if(filter_input(INPUT_GET, "action") == "add_new"){
  addNew($connectDB, $_POST); //$_POST przejda informacje przeslane z formularza
};
*/
//dalej moge wpisac w tresci aktualnosci skrypt ktory znajdzie sie w bazie danych np <script>alert("test")</script> To na stronie wyskoczy alert, więc zmieniam dalej:
//To SAMO CO WYZEJ TYLKO JESZCZE LEPIEJ
if(filter_input(INPUT_GET, "action") == "add_new"){ //filter_input - konkretny rekord, filter input array - cala tablica
  addNew($connectDB, filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING)); //$_POST zamienione
};
//teraz dodaje tekst tylko, nie wrzuca skryptow do bazy danych. nie zadziala tez wstrzykiwanie SQL
//analogicznie następne

if(filter_input(INPUT_GET, "action") == "usun"){ //a bylo if ($_GET['action'] == "usun")
  usunAktualnosc($connectDB, filter_input(INPUT_GET, "id_aktualnosci"));
};

//$filterGet = filter_input(INPUT_GET, "action");
//debug($filterGet);

//GALERIA
if(filter_input(INPUT_GET, "action") == "addNewFoto"){ //bylo z isset($_GET["action"]) ale juz niepotrzbene
  addNewFoto($connectDB, filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING), $_FILES); //tablica globalan $_FILES. abylo addNewFoto($connectDB, $_POST, $_FILES);
};
//jeszcze poprawic isseta ale nie da sie na filter input po prostu i wtedy isset jest niepotrzebne

 ?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Aktualności SQL</title>
    <style>
      span{
        display: inline-block;;
        width: 100%;
        text-align: right;
        font-size: 12px;
      }

      p{
        text-align: justify;
      }

      img{
        display: inline-block;
        float: left;
        padding-left: 20px;
        width: 250px;
      }

    </style>
	</head>
	<body>
		<h3>Aktualności</h3>

    <a href = "index.php?sort=ASC"><button type="submit" name="ASC" id = "asc">Sortuj od najstarszych</button></a>
    <a href = "index.php?sort=DESC"><button type="submit" name="DESC" id = "desc">Sortuj od najnowszych</button></a>

    <section id = "articles">

		<?php
    foreach (fetchAllNews($connectDB, $_GET["sort"], $_GET["id_aktualnosci"]) as $oneNew) : 	 ?>
      <article>
        <h4 id = "title"><?=$oneNew["tytul_aktualnosci"]; ?></h4>
        <p id = "header"><?=$oneNew["naglowek_aktualnosci"]; ?></p>
        <span id = "data"><?=$oneNew["data_publikacji_aktualnosci"]; ?></span>
        <a href="index.php?action=usun&id_aktualnosci=<?=$oneNew["id_aktualnosci"];?>"><button>Usuń</button></a>
        <a href="update.php?action=aktualizuj&id_aktualnosci=<?=$oneNew["id_aktualnosci"];?>"><button>Aktualizuj</button></a>
      </article>
      <hr>

    <?php
    //<?= zamiast <?php echo
  endforeach;
  //debug(fetchAllNews($connectDB)); //bo wyswietle ładniej foreachem powyżej
     ?>


     <?php
//GALERIA

      foreach (fetchAllFoto($connectDB) as $oneFoto) : 	 ?>
        <a href = "zdjecie.php?id_foto=<?=$oneFoto["id_foto"] ?>" target =_blank><div id = "img_<?=$oneFoto["id_zdjecia"]; ?>" title = <?=$oneFoto["tytul_foto"]; ?> ><img src =<?=$oneFoto["nazwaPliku_foto"]; ?>></div></a>

      <?php
    endforeach;

       ?>
       <br><a href="addNewFoto.php?action=addNewFoto"><button id = "dodajFoto">Dodaj</button></a>

   </section>
	</body>
</html>
