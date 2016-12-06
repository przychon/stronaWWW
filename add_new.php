<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Strona WWW - dodawnanie aktualności</title>
	</head>
	<body>
		<h3>Nowa aktualność</h3>
		<form action="index.php?action=add_new" method="post">
			Tytuł aktualności <br>
			<input name="tytul_aktualnosci" id = "tytul_aktualnosci" min = "1" maxlength="255" value="" required = "required"> <br>
			Nagłówek aktualności <br>
			<textarea name="naglowek_aktualnosci" id = "naglowek_aktualnosci" cols = "35" rows = "10" required = "required"></textarea><br>
			<input type="submit" name="submit" id = "submit" value="Zapisz aktualność">
		</form>

	</body>
</html>
