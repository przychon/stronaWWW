<?php
//docelowo uniwersalny wiec moge go pozniej uzywac

function connectDB($host, $user, $password, $database, $charset = "UTF8"){
	$connect = mysqli_connect($host, $user, $password, $database);
	if(!$connect){
		die("Problem z połączeniem z bazą danych." .  mysqli_connect_errno() . "ERROR: " . mysqli_connect_error()); //numer i blad pisany
	}else{
		//var_dump(mysqli_get_charset($connect));  - mamy latin wiec bez polskich znakóœ
			mysqli_set_charset($connect, $charset); //wiec zmieniam na polish
			return $connect;

	}
}
 ?>
