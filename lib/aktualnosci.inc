<?php

function fetchAllNews($connectDB, $sort){
	$arrayNews = array(); //tablica do której chce wrzucić aktualności

	if($sort == NULL OR ($sort !="DESC" AND $sort != "ASC")){ //domyslne sortowanie od najnowszej
		$sort = "DESC";
	};

	$sqlQuery = "SELECT * FROM t_aktualnosci ORDER BY data_publikacji_aktualnosci ".$sort . " LIMIT 3"; //sciagam wszystkie aktualnosci z bazy danych";
	//echo $sqlQuery;

	$sqlResult = mysqli_query($connectDB, $sqlQuery); //wyslanie zapytania do db
	$numRows = mysqli_num_rows($sqlResult); //sprawdzamy czy zwraca jakies rekordy
	if($numRows > 0){ //jak nie ma zadnego rekordu zwroconego
		//dopoki jakis rekord jest to while dziala. $oneRow - to bedzie moja aktualnosc
			while($oneRow = mysqli_fetch_assoc($sqlResult)){ //wylapuje wiersze. assoc - asocjacyjna
					//var_dump($oneRow);
					//return $oneRow;
					$arrayNews[] = $oneRow; //iteruje po tablicy
			}
			return $arrayNews;
	}else{
			return 0; // "Brak aktualności";
	}
};

function addNew($connectDB, $dataFormNew){ //dodawanie nowego newsa
	//debug($dataFormNew);
	$sqlQuery = "INSERT INTO t_aktualnosci (tytul_aktualnosci, naglowek_aktualnosci, data_publikacji_aktualnosci) VALUES ('".$dataFormNew['tytul_aktualnosci']."','".$dataFormNew['naglowek_aktualnosci']."',NOW() );";
	//echo $sqlQuery;
	mysqli_query($connectDB, $sqlQuery);
	//jak wejde na strone ?action=add_new  i odswież to dodaje te aktualnosc teraz
};

function usunAktualnosc($connectDB,$id_aktualnosci){
	$sqlQuery = "DELETE FROM t_aktualnosci WHERE id_aktualnosci = $id_aktualnosci";
	//echo $sqlQuery;
	mysqli_query($connectDB, $sqlQuery);
};



//AKTUALIZUJ AKTUALNOŚĆ
function aktualizuj($connectDB, $id_aktualnosci){
	$sqlQuery = "SELECT * FROM t_aktualnosci WHERE id_aktualnosci = $id_aktualnosci";
	$sqlResult = mysqli_query($connectDB, $sqlQuery);
	$numRows = mysqli_num_rows($sqlResult);
	if($numRows > 0){
			return mysqli_fetch_assoc($sqlResult);
	}else{
			return 0;
	}
};

//I ZAPISZ ZAKTUALIZOWANĄ
function saveNew($connectDB, $dataFormNew){
	//$sqlQuery = "UPDATE t_aktualnosci SET "tytul_aktualnosci = '".$dataFormNew["tytul_aktualnosci"]."',".
	//"naglowek_aktualnosci = '".$dataFormNew["naglowek_aktualnosci"]."'," . "data_publikacji_aktualnosci = NOW()"  WHERE id_aktualnosci = $id_aktualnosci";
	$sqlQuery="UPDATE t_aktualnosci SET
	tytul_aktualnosci = '".$dataFormNew["tytul_aktualnosci"]."',
	naglowek_aktualnosci='".$dataFormNew["naglowek_aktualnosci"]."',
	data_publikacji_aktualnosci = NOW()
	WHERE id_aktualnosci = ".$dataFormNew["id_aktualnosci"];
	mysqli_query($connectDB, $sqlQuery);
};


 ?>
