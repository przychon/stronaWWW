<?php
require 'config.inc';
include 'lib/function.inc';
require 'lib/db_connect.inc';
require 'lib/galeria.inc';

$connectDB = connectDB(__HOST__, __UNAME__, __PASSWD__, __DB_NAME__, __DB_CHARSET_SET__);

if($_GET['action'] == "usunFoto"){
  usunFoto($connectDB, $_GET["id_foto"], $_GET["nazwaPliku_foto"]);
};

 ?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Zdjecie</title>
	</head>
	<body>

<section id= "zdjecie">
<?php
$oneFoto = getOnePhoto($connectDB, $_GET["id_foto"]);

if ($oneFoto == 0) :
?>
<span>Brak zdjęcia</span>

<?php
else :
 ?>

<figure>
<img alt ="<?=$oneFoto["tytul_foto"];?>" src="<?=__URL__.$oneFoto["nazwaPliku_foto"];?>">
<figcaption><?=$oneFoto["tytul_foto"];?></figcaption> <!--polaczone ze zdjecem-->
<a href="zdjecie.php?action=usunFoto&id_foto=<?=$_GET["id_foto"];?>&nazwaPliku_foto=<?=$oneFoto["nazwaPliku_foto"];?>"><button id = "usunFoto">Usuń</button></a>
<a href="updateFoto.php?id_foto=<?=$_GET["id_foto"];?>"><button = id = "aktualizujFoto">Aktualizuj</button></a>
</figure>

<?php endif; ?>
</section>

	</body>
</html>
