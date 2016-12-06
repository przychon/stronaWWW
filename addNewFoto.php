<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Add New Foto</title>
	</head>
	<body>
		<h3>Nowe zdjęcie</h3>
		<form action="index.php?action=addNewFoto" method="post" enctype="multipart/form-data"> <!--rodzaj kodowania w jakim bedzie przeslany formularz, konieczne jak chce wyslac pliki na serwer-->
			Tytuł zdjęcia <br>
			<input name="tytul_foto" id = "tytul_foto" required = "required"> <br>
			Zdjęcie <br>
		<!--	<input name="nazwaPliku_foto" id = "nazwaPliku_foto" required = "required"> <br> -->
		<input type="hidden" name="MAX_FILE_SIZE" value="8000000"> <!--maximum podawane w info PHP-->
			<input type="file" name="nazwaPliku_foto" id ="nazwaPliku_foto" value="" required="required"><br>
			<input type="submit" name="submit" id = "submit" value="Dodaj zdjęcie">
		</form>

	</body>
</html>
