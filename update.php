<?php
require 'config.inc'; //inc mozna zablokowac otworzenie
include 'lib/function.inc';
require 'lib/db_connect.inc';
require 'lib/aktualnosci.inc';
require 'lib/galeria.inc';


$connectDB = connectDB(__HOST__, __UNAME__, __PASSWD__, __DB_NAME__, __DB_CHARSET_SET__);

if(isset($_GET["action"]) && ($_GET['action'] == "saveUpdate")){ //saveUpdate odnosi sie do mojej akcji. mam to wpisane poniżej
  saveNew($connectDB, $_POST);
};


$oneNew = aktualizuj($connectDB,$_GET["id_aktualnosci"]);
//debug(aktualizuj($connectDB,$_GET["id_aktualnosci"]));

 ?>


<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Strona WWW - Aktualizacja</title>
	</head>
	<body>
		<section id = "articles">
		<h3>Podgląd</h3>
		<article>
			<h4 id = "title"><?=$oneNew["tytul_aktualnosci"];?></h4>
			<p id = "header"><?=$oneNew["naglowek_aktualnosci"];?></p>
			<span id = "data"><?=$oneNew["data_publikacji_aktualnosci"];?></span>

		</article>

	</section>

		<h3>Aktualizacja</h3>
		<form action="update.php?action=saveUpdate&id_aktualnosci=<?=$oneNew["id_aktualnosci"];?>" method="post"> <!--musze tu miec id aktualnosci zeby po odswiezeniu strony dalej byl wpisany odpwowiedni teskt-->
     <input type="hidden" name="id_aktualnosci" value = "<?=$oneNew["id_aktualnosci"];?>">
			Tytuł aktualności <br>
			<input name="tytul_aktualnosci" id = "tytul_aktualnosci" min = "1" maxlength="255" value="<?=$oneNew["tytul_aktualnosci"];?>" required = "required"> <br>
			Nagłówek aktualności <br>
			<textarea name="naglowek_aktualnosci" id = "naglowek_aktualnosci" cols = "35" rows = "10" required = "required"><?=$oneNew["naglowek_aktualnosci"];?>"</textarea><br>
			<input type="submit" name="submit" id = "submit" value="Zapisz aktualność">
		</form>

	</body>
</html>
