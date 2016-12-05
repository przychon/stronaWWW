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

function addNew($connectDB){ //dodawanie nowego newsa
	$sqlQuery = "INSERT INTO t_aktualnosci (tytul_aktualnosci, naglowek_aktualnosci, data_publikacji_aktualnosci) VALUES ('Nowa aktualnosc','Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.',NOW()) ";

	//echo $sqlQuery;
	mysqli_query($connectDB, $sqlQuery);
	//jak wejde na strone ?action=add_new  i odswież to dodaje te aktualnosc teraz
};
 ?>
