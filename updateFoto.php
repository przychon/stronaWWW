<?php
require 'config.inc'; //inc mozna zablokowac otworzenie
include 'lib/function.inc';
require 'lib/db_connect.inc';
require 'lib/aktualnosci.inc';
require 'lib/galeria.inc';


$connectDB = connectDB(__HOST__, __UNAME__, __PASSWD__, __DB_NAME__, __DB_CHARSET_SET__);

if(isset($_GET["action"]) && ($_GET['action'] == "saveNewFoto")){
  saveNewFoto($connectDB, $_POST, $_FILES);
	//debug($_POST);
};


$oneFoto= aktualizujFoto($connectDB,$_GET["id_foto"]);
//debug(aktualizujFoto($connectDB,$_GET["id_foto"]));

 ?>


<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Update Foto</title>
		<style media="screen">
			img{
				width: 100px;
			}
		</style>
	</head>
	<body>
		<section id = "articles">
		<h3>Podgląd</h3>
		<article>
			<h4 id = "title"><?=$oneFoto["tytul_foto"];?></h4>
			<img src =<?=$oneFoto["nazwaPliku_foto"]; ?>>

		</article>

	</section>

		<h3>Aktualizacja</h3>
		<form action="updateFoto.php?action=saveNewFoto&id_foto=<?=$_GET["id_foto"];?>" enctype="multipart/form-data" method="post">
			Tytuł zdjęcia <br>
			<input name="tytul_foto" id = "tytul_foto" required = "required" value = <?=$oneFoto["tytul_foto"];?>> <br>
			Zdjęcie <br>
			<input type="text" readonly="readonly" name="nazwaPliku_fotoOld" value="<?=$oneFoto["nazwaPliku_foto"]; ?>"><br> <!--to moglobyc hidden-->
			<input type="file" name="nazwaPliku_foto" id ="nazwaPliku_foto" value= "" accept="image/jpeg"><br> <!--wyswitli tylko jpg w przegladaj-->
			<!-- <input name="nazwaPliku_foto" id = "nazwaPliku_foto" required = "required" value = <?//=$oneFoto["nazwaPliku_foto"];?>> <br> -->
			<input type="submit" name="submit" id = "submit" value="Zmień zdjęcie">
		</form>

	</body>
</html>
